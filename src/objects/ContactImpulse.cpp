#include "common.hpp"
#include "objects/ContactImpulse.hpp"

namespace LuaBox2D {
	void initContactImpulse(State * state){
		state->registerInterface<ContactImpulse>("LuaBox2D_ContactImpulse");
	}

	b2ContactImpulse * ContactImpulse::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		return nullptr;
	}

	void ContactImpulse::destructor(State & state, b2ContactImpulse * object){
		delete object;
	}


	int ContactImpulse::operator_len(State & state, b2ContactImpulse * object){
		state.stack->push<int>(static_cast<int>(object->count));
		return 1;
	}

	int ContactImpulse::getNormalImpulse(State & state, b2ContactImpulse * object){
		int index = state.stack->to<int>(1) - 1;
		if (index>=0 && index<object->count && index<b2_maxManifoldPoints){
			state.stack->push<LUA_NUMBER>( static_cast<LUA_NUMBER>(object->normalImpulses[index]) );
			return 1;
		}else{
			return 0;
		}
	}

	int ContactImpulse::setNormalImpulse(State & state, b2ContactImpulse * object){
		int index = state.stack->to<int>(1) - 1;
		if (index>=0 && index<b2_maxManifoldPoints){
			if (state.stack->is<LUA_TNUMBER>(2)){
				object->normalImpulses[index] = static_cast<float32>(state.stack->to<LUA_NUMBER>(2));
			}
		}
		return 0;
	}

	int ContactImpulse::getTangentImpulse(State & state, b2ContactImpulse * object){
		int index = state.stack->to<int>(1) - 1;
		if (index>=0 && index<object->count && index<b2_maxManifoldPoints){
			state.stack->push<LUA_NUMBER>( static_cast<LUA_NUMBER>(object->tangentImpulses[index]) );
			return 1;
		}else{
			return 0;
		}
	}

	int ContactImpulse::setTangentImpulse(State & state, b2ContactImpulse * object){
		int index = state.stack->to<int>(1) - 1;
		if (index>=0 && index<b2_maxManifoldPoints){
			if (state.stack->is<LUA_TNUMBER>(2)){
				object->tangentImpulses[index] = static_cast<float32>(state.stack->to<LUA_NUMBER>(2));
			}
		}
		return 0;
	}
};
