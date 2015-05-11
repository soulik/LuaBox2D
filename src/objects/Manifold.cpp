#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Manifold.hpp"
#include "objects/ManifoldPoint.hpp"

namespace LuaBox2D {
	void initManifold(State * state){
		state->registerInterface<Manifold>("LuaBox2D_Manifold");
	}

	b2Manifold * Manifold::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		return new b2Manifold();
	}

	void Manifold::destructor(State & state, b2Manifold * object){
		delete object;
	}

	int Manifold::operator_len(State & state, b2Manifold * object){
		state.stack->push<int>(static_cast<int>(object->pointCount));
		return 1;
	}

	int Manifold::getLocalNormal(State & state, b2Manifold * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->localNormal, false);
		return 1;
	}

	int Manifold::setLocalNormal(State & state, b2Manifold * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * normal = interfaceVec2->get(1);
		if (normal != nullptr){
			object->localNormal = *normal;
		}
		return 0;
	}

	int Manifold::getLocalPoint(State & state, b2Manifold * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->localPoint, false);
		return 1;
	}

	int Manifold::setLocalPoint(State & state, b2Manifold * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * point = interfaceVec2->get(1);
		if (point != nullptr){
			object->localPoint = *point;
		}
		return 0;
	}

	int Manifold::getType(State & state, b2Manifold * object){
		state.stack->push<int>(static_cast<int>(object->type));
		return 1;
	}

	int Manifold::setType(State & state, b2Manifold * object){
		object->type = static_cast<b2Manifold::Type>(state.stack->to<int>(1));
		return 0;
	}

	int Manifold::operator_getArray(State & state, b2Manifold * object){
		int index = state.stack->to<int>(1) - 1;
		if (index >= 0 && index < object->pointCount){
			ManifoldPoint * interfaceManifoldPoint = state.getInterface<ManifoldPoint>("LuaBox2D_ManifoldPoint");
			interfaceManifoldPoint->push(& object->points[index], false);
			return 1;
		}else{
			return 0;
		}
	}

	void Manifold::operator_setArray(State & state, b2Manifold * object){
		if (state.stack->is<LUA_TNUMBER>(1) && state.stack->is<LUA_TUSERDATA>(2)){
			int index = state.stack->to<int>(1) - 1;
			if (index >= 0 && index < object->pointCount){
				ManifoldPoint * interfaceManifoldPoint = state.getInterface<ManifoldPoint>("LuaBox2D_ManifoldPoint");
				b2ManifoldPoint * point = interfaceManifoldPoint->get(1);
				if (point != nullptr){
					object->points[index] = *point;
				}
			}
		}
	}
};
