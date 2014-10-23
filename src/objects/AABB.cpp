#include "common.hpp"
#include "objects/AABB.hpp"

namespace LuaBox2D {
	void initAABB(State * state){
		state->registerInterface<AABB>("LuaBox2D_AABB");
	}
};
