#include "common.hpp"
#include "objects/Vec2.hpp"

namespace LuaBox2D {
	void initVec2(State * state){
		state->registerInterface<Vec2>("LuaBox2D_Vec2");
	}
}