#include "common.hpp"
#include "objects/Rot.hpp"

namespace LuaBox2D {
	void initRot(State * state){
		Rot * interface = new Rot(state);
		state->interfaces["LuaBox2D_Rot"] = interface;
		interface->getConstructor();
	}
};

