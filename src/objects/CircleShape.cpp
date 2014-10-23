#include "common.hpp"
#include "objects/CircleShape.hpp"

namespace LuaBox2D {
	void initCircleShape(State * state){
		state->registerInterface<CircleShape>("LuaBox2D_CircleShape");
	}
};
