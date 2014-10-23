#include "common.hpp"
#include "objects/Fixture.hpp"

namespace LuaBox2D {
	void initFixture(State * state){
		state->registerInterface<Fixture>("LuaBox2D_Fixture");
	}

	int Fixture::getBody(State & state, b2Fixture * object){
		Body * interfaceBody = dynamic_cast<Body*>(state.interfaces["LuaBox2D_Body"]);
		interfaceBody->push(object->GetBody(), false);
		return 1;
	}

};