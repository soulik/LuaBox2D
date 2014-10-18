#include "common.hpp"
#include "objects/Rot.hpp"

namespace LuaBox2D {
	void initRot(State * state){
		state->registerInterface<Rot>("LuaBox2D_Rot");
	}
};

