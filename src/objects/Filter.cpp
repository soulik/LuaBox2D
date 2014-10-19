#include "common.hpp"
#include "objects/Filter.hpp"

namespace LuaBox2D {
	void initFilter(State * state){
		state->registerInterface<Filter>("LuaBox2D_Filter");

	}
};
