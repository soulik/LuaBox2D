#include "common.hpp"
#include "objects/Body.hpp"

namespace LuaBox2D {
	void initBody(State * state){
		Body * interface = new Body(state);
		state->interfaces["LuaBox2D_Body"] = interface;
		interface->getConstructor();
	}
};
