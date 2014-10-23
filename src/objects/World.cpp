#include "common.hpp"
#include "objects/World.hpp"

namespace LuaBox2D {
	void initWorld(State * state){
		state->registerInterface<World>("LuaBox2D_World");
	}

	int World::createBody(State & state, b2World * object){
		BodyDef * interfaceBodyDef = state.getInterface<BodyDef>("LuaBox2D_BodyDef");
		b2BodyDef * bodyDef = interfaceBodyDef->get(1);
		if (bodyDef != nullptr){
			Body * interfaceBody = state.getInterface<Body>("LuaBox2D_Body");
			b2Body * body = object->CreateBody(bodyDef);
			interfaceBody->push(body, true);
			return 1;
		}else{
			return 0;
		}
	}

	int World::createJoint(State & state, b2World * object){
		JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
		b2JointDef * jointDef = interfaceJointDef->get(1);
		if (jointDef != nullptr){
			Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
			b2Joint * joint = object->CreateJoint(jointDef);
			interfaceJoint->push(joint, true);
			return 1;
		}else{
			return 0;
		}
	}
};
