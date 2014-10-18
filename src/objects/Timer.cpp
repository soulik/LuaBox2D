#include "common.hpp"
#include "objects/Timer.hpp"

namespace LuaBox2D {
	void initTimer(State * state){
		state->registerInterface<Timer>("LuaBox2D_Timer");
	}
};
