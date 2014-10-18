#include "common.hpp"
#include "objects/Sweep.hpp"

namespace LuaBox2D {
	void initSweep(State * state){
		state->registerInterface<Sweep>("LuaBox2D_Sweep");
	}
};

