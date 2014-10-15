#include "common.hpp"
#include "objects/World.hpp"

namespace LuaBox2D {
	void initWorld(State * state){
		World * interface = new World(state);
		state->interfaces["LuaBox2D_World"] = interface;
		interface->getConstructor();
	}
};
