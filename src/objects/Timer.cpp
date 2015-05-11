#include "common.hpp"
#include "objects/Timer.hpp"

namespace LuaBox2D {
	void initTimer(State * state){
		state->registerInterface<Timer>("LuaBox2D_Timer");
	}

	b2Timer * Timer::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		b2Timer * obj = nullptr;
		obj = new b2Timer();
		return obj;
	}

	void Timer::destructor(State & state, b2Timer * object){
		delete object;
	}

	int Timer::getMiliseconds(State & state, b2Timer * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetMilliseconds()));
		return 1;
	}

	int Timer::reset(State & state, b2Timer * object){
		object->Reset();
		return 0;
	}
};
