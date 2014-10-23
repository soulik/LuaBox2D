#include "common.hpp"
#include "objects/EdgeShape.hpp"

namespace LuaBox2D {
	void initEdgeShape(State * state){
		state->registerInterface<EdgeShape>("LuaBox2D_EdgeShape");
	}
};
