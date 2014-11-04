#include "common.hpp"

#include "objects/Timer.hpp"

#include "objects/Vec2.hpp"
#include "objects/Rot.hpp"
#include "objects/Transform.hpp"
#include "objects/Sweep.hpp"

#include "objects/World.hpp"
#include "objects/Body.hpp"
#include "objects/BodyDef.hpp"
#include "objects/Joint.hpp"
#include "objects/JointDef.hpp"
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
#include "objects/Contact.hpp"
#include "objects/Manifold.hpp"
#include "objects/ManifoldPoint.hpp"
#include "objects/ContactID.hpp"
#include "objects/ContactFeature.hpp"
#include "objects/WorldManifold.hpp"
#include "objects/ContactListener.hpp"
#include "objects/ContactImpulse.hpp"
#include "objects/ContactManager.hpp"
#include "objects/ContactFilter.hpp"

#include "objects/QueryCallback.hpp"
#include "objects/RayCastCallback.hpp"

#include "objects/RevoluteJoint.hpp"
#include "objects/RevoluteJointDef.hpp"
#include "objects/PrismaticJoint.hpp"
#include "objects/PrismaticJointDef.hpp"
#include "objects/DistanceJoint.hpp"
#include "objects/DistanceJointDef.hpp"
#include "objects/PulleyJoint.hpp"
#include "objects/PulleyJointDef.hpp"
#include "objects/MouseJoint.hpp"
#include "objects/MouseJointDef.hpp"
#include "objects/GearJoint.hpp"
#include "objects/GearJointDef.hpp"
#include "objects/WheelJoint.hpp"
#include "objects/WheelJointDef.hpp"
#include "objects/WeldJoint.hpp"
#include "objects/WeldJointDef.hpp"
#include "objects/FrictionJoint.hpp"
#include "objects/FrictionJointDef.hpp"
#include "objects/RopeJoint.hpp"
#include "objects/RopeJointDef.hpp"
#include "objects/MotorJoint.hpp"
#include "objects/MotorJointDef.hpp"

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