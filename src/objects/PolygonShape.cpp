#include "common.hpp"
#include "objects/PolygonShape.hpp"

namespace LuaBox2D {
	void initPolygonShape(State * state){
		state->registerInterface<PolygonShape>("LuaBox2D_PolygonShape");
	}
};
