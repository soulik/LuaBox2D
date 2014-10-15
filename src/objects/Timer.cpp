#include "common.hpp"
#include "objects/Timer.hpp"

namespace LuaBox2D {
	void initTimer(State * state){
		Timer * interface = new Timer(state);
		state->interfaces["LuaBox2D_Timer"] = interface;
		interface->getConstructor();
	}
};
