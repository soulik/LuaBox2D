#include "common.hpp"
#include "objects/Transform.hpp"

namespace LuaBox2D {
	void initTransform(State * state){
		state->registerInterface<Transform>("LuaBox2D_Transform");
	}
};

