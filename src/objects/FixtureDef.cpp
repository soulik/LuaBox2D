#include "common.hpp"
#include "objects/FixtureDef.hpp"

namespace LuaBox2D {
	void initFixtureDef(State * state){
		state->registerInterface<FixtureDef>("LuaBox2D_FixtureDef");
	}
};