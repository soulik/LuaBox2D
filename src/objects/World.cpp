#include "common.hpp"
#include "objects/World.hpp"

namespace LuaBox2D {
	void initWorld(State * state){
		state->registerInterface<World>("LuaBox2D_World");
	}
};
