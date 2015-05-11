#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/RayCastOutput.hpp"

namespace LuaBox2D {
	void initRayCastOutput(State * state){
		state->registerInterface<RayCastOutput>("LuaBox2D_RayCastOutput");
	}

	b2RayCastOutput * RayCastOutput::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		b2RayCastOutput * object = new b2RayCastOutput();
		return object;
	}

	void RayCastOutput::destructor(State & state, b2RayCastOutput * object){
		delete object;
	}

	int RayCastOutput::getNormal(State & state, b2RayCastOutput * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->normal, false);
		return 1;
	}

	int RayCastOutput::setNormal(State & state, b2RayCastOutput * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * point = interfaceVec2->get(1);
		if (point != nullptr){
			object->normal = *point;
		}
		return 0;
	}

	int RayCastOutput::getFraction(State & state, b2RayCastOutput * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->fraction));
		return 1;
	}

	int RayCastOutput::setFraction(State & state, b2RayCastOutput * object){
		object->fraction = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}
};
