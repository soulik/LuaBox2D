#include "common.hpp"
#include "objects/ChainShape.hpp"

namespace LuaBox2D {
	void initChainShape(State * state){
		state->registerInterface<ChainShape>("LuaBox2D_ChainShape");
	}
};
