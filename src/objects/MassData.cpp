#include "common.hpp"
#include "objects/MassData.hpp"

namespace LuaBox2D {
	void initMassData(State * state){
		state->registerInterface<MassData>("LuaBox2D_MassData");
	}
};
