#include "common.hpp"
#include "objects/Shape.hpp"

namespace LuaBox2D {
	void initShape(State * state){
		state->registerInterface<Shape>("LuaBox2D_Shape");
	}
};