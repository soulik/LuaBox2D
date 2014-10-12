#include "common.hpp"
#include "objects/Vec2.hpp"

using namespace LuaBox2D;

extern "C" LUA_API int luaopen_LuaBox2D(lua_State * L){
	State * state = new State(L);
	Stack * stack = state->stack;
	stack->newTable();
		initVec2(state);
		stack->setField("Vec2");
	return 1;
}