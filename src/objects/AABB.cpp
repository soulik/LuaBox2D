#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/RayCastInput.hpp"
#include "objects/RayCastOutput.hpp"
#include "objects/AABB.hpp"

namespace LuaBox2D {
	void initAABB(State * state){
		state->registerInterface<AABB>("LuaBox2D_AABB");
	}

	b2AABB * AABB::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		b2AABB * object = new b2AABB();
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		if (state.stack->is<LUA_TUSERDATA>(1) && state.stack->is<LUA_TUSERDATA>(2)){
			b2Vec2 * lowerBound = interfaceVec2->get(1);
			b2Vec2 * upperBound = interfaceVec2->get(2);
			if (lowerBound != nullptr && upperBound != nullptr){
				object->lowerBound = *lowerBound;
				object->upperBound = *upperBound;
			}
		}

		return object;
	}

	void AABB::destructor(State & state, b2AABB * object){
		delete object;
	}

	int AABB::getLowerBound(State & state, b2AABB * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->lowerBound, false);
		return 1;
	}

	int AABB::setLowerBound(State & state, b2AABB * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * bound = interfaceVec2->get(1);
		if (bound != nullptr){
			object->lowerBound = *bound;
		}
		return 0;
	}

	int AABB::getUpperBound(State & state, b2AABB * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->upperBound, false);
		return 1;
	}

	int AABB::setUpperBound(State & state, b2AABB * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * bound = interfaceVec2->get(1);
		if (bound != nullptr){
			object->upperBound = *bound;
		}
		return 0;
	}

	int AABB::getValid(State & state, b2AABB * object){
		state.stack->push<bool>(object->IsValid());
		return 1;
	}

	int AABB::getCenter(State & state, b2AABB * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetCenter()), true);
		return 1;
	}

	int AABB::getExtens(State & state, b2AABB * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetExtents()), true);
		return 1;
	}

	int AABB::getPerimeter(State & state, b2AABB * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetPerimeter()));
		return 1;
	}

	int AABB::operator_add(State & state, b2AABB * a, b2AABB * b){
		if (a != nullptr && b != nullptr){
			AABB * interfaceAABB = state.getInterface<AABB>("LuaBox2D_AABB");
			b2AABB * result = new b2AABB(*a);
			result->Combine(*b);
			interfaceAABB->push(result, true);
			return 1;
		}else{
			return 0;
		}
	}

	int AABB::combine(State & state, b2AABB * object){
		AABB * interfaceAABB = state.getInterface<AABB>("LuaBox2D_AABB");
		b2AABB * a = interfaceAABB->get(1);
		b2AABB * b = interfaceAABB->get(2);

		if (a != nullptr){
			if (b != nullptr){
				object->Combine(*a);
			}else{
				object->Combine(*a, *b);
			}
		}
		return 0;
	}

	int AABB::contains(State & state, b2AABB * object){
		AABB * interfaceAABB = state.getInterface<AABB>("LuaBox2D_AABB");
		b2AABB * other = interfaceAABB->get(1);

		if (other != nullptr){
			state.stack->push<bool>(object->Contains(*other));
			return 1;
		}else{
			return 0;
		}
	}

	int AABB::rayCast(State & state, b2AABB * object){
		RayCastInput * interfaceRayCastInput = state.getInterface<RayCastInput>("LuaBox2D_RayCastInput");
		RayCastOutput * interfaceRayCastOutput = state.getInterface<RayCastOutput>("LuaBox2D_RayCastOutput");

		b2RayCastInput * rayCastInput = interfaceRayCastInput->get(1);
		b2RayCastOutput * rayCastOutput = interfaceRayCastOutput->get(2);

		if (rayCastInput != nullptr){
			bool ownedOutput = false;
			if (rayCastOutput == nullptr){
				rayCastOutput = new b2RayCastOutput();
				ownedOutput = true;
			}
			bool result = object->RayCast(
				rayCastOutput,
				*rayCastInput);

			if (result){
				state.stack->push<bool>(true);
				interfaceRayCastOutput->push(rayCastOutput, ownedOutput);
				return 2;
			}else{
				if (ownedOutput){
					delete rayCastOutput;
				}
				state.stack->push<bool>(false);
				return 1;
			}
		}else{
			return 0;
		}
	}
};
