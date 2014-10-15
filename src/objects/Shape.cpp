#include "common.hpp"
#include "objects/Shape.hpp"

namespace LuaBox2D {
	void initShape(State * state){
		Shape * interface = new Shape(state);
		state->interfaces["LuaBox2D_Shape"] = interface;
		interface->getConstructor();
	}
};