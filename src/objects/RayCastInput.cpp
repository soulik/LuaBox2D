#include "common.hpp"
#include "objects/RayCastInput.hpp"

namespace LuaBox2D {
	void initRayCastInput(State * state){
		state->registerInterface<RayCastInput>("LuaBox2D_RayCastInput");
	}
};
