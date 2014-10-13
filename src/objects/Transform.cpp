#include "common.hpp"
#include "objects/Transform.hpp"

namespace LuaBox2D {
	void initTransform(State * state){
		Transform * interface = new Transform(state);
		state->interfaces["LuaBox2D_Transform"] = interface;
		interface->getConstructor();
	}
};

