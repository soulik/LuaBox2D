#include "common.hpp"
#include "objects/Joint.hpp"

namespace LuaBox2D {
	void initJoint(State * state){
		state->registerInterface<Joint>("LuaBox2D_Joint");
	}
};
