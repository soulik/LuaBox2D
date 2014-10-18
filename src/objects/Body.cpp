#include "common.hpp"
#include "objects/Body.hpp"

namespace LuaBox2D {
	void initBody(State * state){
		state->registerInterface<Body>("LuaBox2D_Body");
	}
};
