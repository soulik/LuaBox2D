#include "common.hpp"

#include "objects/Timer.hpp"

#include "objects/Vec2.hpp"
#include "objects/Rot.hpp"
#include "objects/Transform.hpp"
#include "objects/Sweep.hpp"

#include "objects/World.hpp"
#include "objects/Body.hpp"
#include "objects/BodyDef.hpp"
#include "objects/Fixture.hpp"
#include "objects/FixtureDef.hpp"
#include "objects/Shape.hpp"
#include "objects/Filter.hpp"
#include "objects/RayCastInput.hpp"
#include "objects/RayCastOutput.hpp"
#include "objects/AABB.hpp"
#include "objects/MassData.hpp"
#include "objects/CircleShape.hpp"
#include "objects/ChainShape.hpp"
#include "objects/EdgeShape.hpp"
#include "objects/PolygonShape.hpp"
#include "objects/VertexArray.hpp"

namespace LuaBox2D {
	int version(State & state){
		Stack * stack = state.stack;
		stack->newTable();
		stack->setField<int>("major", b2_version.major);
		stack->setField<int>("minor", b2_version.minor);
		stack->setField<int>("revision", b2_version.revision);
		return 1;
	}
};

using namespace LuaBox2D;

extern "C" LUA_API int luaopen_LuaBox2D(lua_State * L){
	State * state = new State(L);
	Stack * stack = state->stack;
	stack->newTable();
		initTimer(state); stack->setField("Timer");
	
		initVec2(state); stack->setField("Vec2");
		initRot(state); stack->setField("Rot");
		initTransform(state); stack->setField("Transform");
		initSweep(state); stack->setField("Sweep");

		initWorld(state); stack->setField("World");
		initBody(state); stack->setField("Body");
		initBodyDef(state); stack->setField("BodyDef");
		initFixture(state); stack->setField("Fixture");
		initFixtureDef(state); stack->setField("FixtureDef");

		initShape(state); stack->setField("Shape");
		initCircleShape(state); stack->setField("CircleShape");
		initChainShape(state); stack->setField("ChainShape");
		initEdgeShape(state); stack->setField("EdgeShape");
		initPolygonShape(state); stack->setField("PolygonShape");

		initFilter(state); stack->setField("Filter");
		initRayCastInput(state); stack->setField("RaycastInput");
		initRayCastOutput(state); stack->setField("RaycastOutput");
		initAABB(state); stack->setField("AABB");
		initMassData(state); stack->setField("MassData");
		initVertexArray(state); stack->setField("VertexArray");

		stack->setField<Function>("version", version);
	return 1;
}