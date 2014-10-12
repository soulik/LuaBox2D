#include "common.hpp"
#include "objects/Vec2.hpp"

namespace LuaBox2D {
	void initVec2(State * state){
		Vec2 * interface = new Vec2(state);
		state->interfaces["LuaBox2D_Vec2"] = interface;
		interface->getConstructor();
	}
}