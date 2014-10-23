#include "common.hpp"
#include "objects/JointDef.hpp"

namespace LuaBox2D {
	void initJointDef(State * state){
		state->registerInterface<JointDef>("LuaBox2D_JointDef");
	}
};
