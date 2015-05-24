#include "common.hpp"
#include "array.hpp"
#include "main.hpp"

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

#define INIT_OBJECT(OBJ_NAME) init ## OBJ_NAME(state); stack->setField(#OBJ_NAME)
#define INIT_JOINT(JOINT_NAME) INIT_OBJECT(JOINT_NAME ## Joint); \
	INIT_OBJECT(JOINT_NAME ## JointDef)

extern "C" LIBLUABOX2D_DLL_EXPORTED int luaopen_LuaBox2D(lua_State * L){
	int t = lua_gettop(L);
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
		initJoint(state); stack->setField("Joint");
		initJointDef(state); stack->setField("JointDef");
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
		initContact(state); stack->setField("Contact");
		initManifold(state); stack->setField("Manifold");
		initManifoldPoint(state); stack->setField("ManifoldPoint");
		initContactID(state); stack->setField("ContactID");
		initContactFeature(state); stack->setField("ContactFeature");
		initWorldManifold(state); stack->setField("WorldManifold");
		initContactListener(state); stack->setField("ContactListener");
		initContactImpulse(state); stack->setField("ContactImpulse");
		initContactManager(state); stack->setField("ContactManager");
		initContactFilter(state); stack->setField("ContactFilter");

		initQueryCallback(state); stack->setField("QueryCallback");
		initRayCastCallback(state); stack->setField("RayCastCallback");

		initJointEdge(state); stack->setField("JointEdge");
		initContactEdge(state); stack->setField("ContactEdge");

		INIT_JOINT(Revolute);
		INIT_JOINT(Prismatic);
		INIT_JOINT(Distance);
		INIT_JOINT(Pulley);
		INIT_JOINT(Mouse);
		INIT_JOINT(Gear);
		INIT_JOINT(Wheel);
		INIT_JOINT(Weld);
		INIT_JOINT(Friction);
		INIT_JOINT(Rope);
		INIT_JOINT(Motor);

		stack->setField<Function>("version", version);
	return 1;
}