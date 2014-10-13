#include "common.hpp"
#include "objects/Sweep.hpp"

namespace LuaBox2D {
	void initSweep(State * state){
		Sweep * interface = new Sweep(state);
		state->interfaces["LuaBox2D_Sweep"] = interface;
		interface->getConstructor();
	}
};

