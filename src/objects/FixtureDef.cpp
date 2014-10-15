#include "common.hpp"
#include "objects/FixtureDef.hpp"

namespace LuaBox2D {
	void initFixtureDef(State * state){
		FixtureDef * interface = new FixtureDef(state);
		state->interfaces["LuaBox2D_FixtureDef"] = interface;
		interface->getConstructor();
	}
};