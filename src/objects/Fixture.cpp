#include "common.hpp"
#include "objects/Fixture.hpp"

namespace LuaBox2D {
	void initFixture(State * state){
		state->registerInterface<Fixture>("LuaBox2D_Fixture");
	}
};