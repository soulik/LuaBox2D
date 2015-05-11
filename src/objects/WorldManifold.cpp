#include "common.hpp"
#include "objects/WorldManifold.hpp"
#include "objects/Vec2.hpp"
#include "objects/Transform.hpp"
#include "objects/Manifold.hpp"

namespace LuaBox2D {
	void initWorldManifold(State * state){
		state->registerInterface<WorldManifold>("LuaBox2D_WorldManifold");
	}

	b2WorldManifold * WorldManifold::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(state);
		LUTOK2_NOT_USED(managed);
		return new b2WorldManifold();
	}

	void WorldManifold::destructor(State & state, b2WorldManifold * object){
		delete object;
	}

	int WorldManifold::getNormal(State & state, b2WorldManifold * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->normal, false);
		return 1;
	}

	int WorldManifold::setNormal(State & state, b2WorldManifold * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * point = interfaceVec2->get(1);
		if (point != nullptr){
			object->normal = *point;
		}
		return 0;
	}

	int WorldManifold::initialize(State & state, b2WorldManifold * object){
		if (state.stack->is<LUA_TUSERDATA>(1) && state.stack->is<LUA_TUSERDATA>(2) && state.stack->is<LUA_TNUMBER>(3) && state.stack->is<LUA_TUSERDATA>(4) && state.stack->is<LUA_TNUMBER>(5)){
			Manifold * interfaceManifold = state.getInterface<Manifold>("LuaBox2D_Manifold");
			Transform * interfaceTransform = state.getInterface<Transform>("LuaBox2D_Transform");
			b2Manifold * manifold = interfaceManifold->get(1);
			b2Transform * fA = interfaceTransform->get(2);
			b2Transform * fB = interfaceTransform->get(4);
			if (manifold != nullptr && fA != nullptr && fB != nullptr){
				float32 radiusA = static_cast<float32>(state.stack->to<LUA_NUMBER>(3));
				float32 radiusB = static_cast<float32>(state.stack->to<LUA_NUMBER>(5));
				object->Initialize(manifold, *fA, radiusA, *fB, radiusB);
			}
		}
		return 0;
	}

	int WorldManifold::getSeparation(State & state, b2WorldManifold * object){
		if (state.stack->is<LUA_TNUMBER>(1)){
			int index = state.stack->to<int>(1) - 1;
			if (index >= 0 && index < b2_maxManifoldPoints){
				state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->separations[index]));
				return 1;
			}else{
				return 0;
			}
		}else{
			return 0;
		}
	}

	int WorldManifold::setSeparation(State & state, b2WorldManifold * object){
		if (state.stack->is<LUA_TNUMBER>(1) && state.stack->is<LUA_TNUMBER>(2)){
			int index = state.stack->to<int>(1) - 1;
			if (index >= 0 && index < b2_maxManifoldPoints){
				object->separations[index] = static_cast<float32>(state.stack->to<LUA_NUMBER>(2));
			}
		}
		return 0;
	}

	int WorldManifold::operator_getArray(State & state, b2WorldManifold * object){
		int index = state.stack->to<int>(1) - 1;
		if (index >= 0 && index < b2_maxManifoldPoints){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			interfaceVec2->push(& object->points[index], false);
			return 1;
		}else{
			return 0;
		}
	}

	void WorldManifold::operator_setArray(State & state, b2WorldManifold * object){
		if (state.stack->is<LUA_TNUMBER>(1) && state.stack->is<LUA_TUSERDATA>(2)){
			int index = state.stack->to<int>(1) - 1;
			if (index >= 0 && index < b2_maxManifoldPoints){
				Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
				b2Vec2 * point = interfaceVec2->get(1);
				if (point != nullptr){
					object->points[index] = *point;
				}
			}
		}
	}
};
