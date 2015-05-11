#include "common.hpp"
#include "objects/Transform.hpp"
#include "objects/Sweep.hpp"

namespace LuaBox2D {
	void initSweep(State * state){
		state->registerInterface<Sweep>("LuaBox2D_Sweep");
	}

	b2Sweep * Sweep::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		b2Sweep * obj = nullptr;
		obj = new b2Sweep();
		return obj;
	}

	void Sweep::destructor(State & state, b2Sweep * object){
		delete object;
	}

	int Sweep::getTransform(State & state, b2Sweep * object){
		if (state.stack->is<LUA_TNUMBER>(1)){
			Transform * interfaceTransform = state.getInterface<Transform>("LuaBox2D_Transform");
			b2Transform * transform = new b2Transform();
			object->GetTransform(transform, static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
			interfaceTransform->push(transform, true);
			return 1;
		}else{
			return 0;
		}
	}

	int Sweep::advance(State & state, b2Sweep * object){
		if (state.stack->is<LUA_TNUMBER>(1)){
			object->Advance(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		}
		return 0;
	}

	int Sweep::normalize(State & state, b2Sweep * object){
		object->Normalize();
		return 0;
	}
};

