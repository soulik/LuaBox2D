#include "common.hpp"
#include "objects/VertexArray.hpp"

namespace LuaBox2D {
	void initVertexArray(State * state){
		state->registerInterface<VertexArray>("LuaBox2D_VertexArray");
	}
};
