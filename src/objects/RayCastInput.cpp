#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/RayCastInput.hpp"

namespace LuaBox2D {
	void initRayCastInput(State * state){
		state->registerInterface<RayCastInput>("LuaBox2D_RayCastInput");
	}

	b2RayCastInput * RayCastInput::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		b2RayCastInput * object = nullptr;
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * p1 = interfaceVec2->get(1);
		b2Vec2 * p2 = interfaceVec2->get(2);

		object = new b2RayCastInput();

		if (p1 != nullptr && p2 != nullptr && state.stack->is<LUA_TNUMBER>(3)){
			object->p1 = *p1;
			object->p2 = *p2;
			object->maxFraction = static_cast<float32>(state.stack->to<LUA_NUMBER>(3));
		}
		return object;
	}

	void RayCastInput::destructor(State & state, b2RayCastInput * object){
		delete object;
	}

	int RayCastInput::getP1(State & state, b2RayCastInput * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->p1, false);
		return 1;
	}

	int RayCastInput::setP1(State & state, b2RayCastInput * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * point = interfaceVec2->get(1);
		if (point != nullptr){
			object->p1 = *point;
		}
		return 0;
	}

	int RayCastInput::getP2(State & state, b2RayCastInput * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->p2, false);
		return 1;
	}

	int RayCastInput::setP2(State & state, b2RayCastInput * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * point = interfaceVec2->get(1);
		if (point != nullptr){
			object->p2 = *point;
		}
		return 0;
	}

	int RayCastInput::getMaxFraction(State & state, b2RayCastInput * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->maxFraction));
		return 1;
	}

	int RayCastInput::setMaxFraction(State & state, b2RayCastInput * object){
		object->maxFraction = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}
};
