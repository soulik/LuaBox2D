#include "common.hpp"
#include "objects/Fixture.hpp"

namespace LuaBox2D {
	void initFixture(State * state){
		Fixture * interface = new Fixture(state);
		state->interfaces["LuaBox2D_Fixture"] = interface;
		interface->getConstructor();
	}
};