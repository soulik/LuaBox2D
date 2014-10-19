#include "common.hpp"
#include "objects/RayCastOutput.hpp"

namespace LuaBox2D {
	void initRayCastOutput(State * state){
		state->registerInterface<RayCastOutput>("LuaBox2D_RayCastOutput");
	}
};
