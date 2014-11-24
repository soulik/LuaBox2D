#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Body.hpp"
#include "objects/Joint.hpp"
#include "objects/JointDef.hpp"
#include "objects/GearJointDef.hpp"

namespace LuaBox2D {
	void initGearJointDef(State * state){
		state->registerInterface<GearJointDef>("LuaBox2D_GearJointDef");
	}

	b2GearJointDef * GearJointDef::constructor(State & state, bool & managed){
		JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
		b2JointDef * jointDef = interfaceJointDef->get(1);
		if (jointDef != nullptr){
			if (jointDef->type == b2JointType::e_gearJoint){
				managed = false;
				return reinterpret_cast<b2GearJointDef*>(jointDef);
			}else{
				return new b2GearJointDef();
			}
		}else{
			return new b2GearJointDef();
		}
	}

	void GearJointDef::destructor(State & state, b2GearJointDef * object){
		delete object;
	}

	inline int GearJointDef::getBodyA(State & state, b2GearJointDef * object){
		return base->getBodyA(state, object);
	}

	inline int GearJointDef::setBodyA(State & state, b2GearJointDef * object){
		return base->setBodyA(state, object);
	}

	inline int GearJointDef::getBodyB(State & state, b2GearJointDef * object){
		return base->getBodyB(state, object);
	}

	inline int GearJointDef::setBodyB(State & state, b2GearJointDef * object){
		return base->setBodyB(state, object);
	}

	inline int GearJointDef::getType(State & state, b2GearJointDef * object){
		return base->getType(state, object);
	}

	inline int GearJointDef::setType(State & state, b2GearJointDef * object){
		return base->setType(state, object);
	}

	inline int GearJointDef::getCollideConnected(State & state, b2GearJointDef * object){
		return base->getCollideConnected(state, object);
	}

	inline int GearJointDef::setCollideConnected(State & state, b2GearJointDef * object){
		return base->setCollideConnected(state, object);
	}

	inline int GearJointDef::getUserData(State & state, b2GearJointDef * object){
		return base->getUserData(state, object);
	}

	inline int GearJointDef::setUserData(State & state, b2GearJointDef * object){
		return base->setUserData(state, object);
	}

	int GearJointDef::getJoint1(State & state, b2GearJointDef * object){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		interfaceJoint->push(object->joint1, false);
		return 1;
	}

	int GearJointDef::setJoint1(State & state, b2GearJointDef * object){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		b2Joint * joint = interfaceJoint->get(1);
		if (joint != nullptr){
			object->joint1 = joint;
		}
		return 0;
	}

	int GearJointDef::getJoint2(State & state, b2GearJointDef * object){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		interfaceJoint->push(object->joint2, false);
		return 1;
	}

	int GearJointDef::setJoint2(State & state, b2GearJointDef * object){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		b2Joint * joint = interfaceJoint->get(1);
		if (joint != nullptr){
			object->joint2 = joint;
		}
		return 0;

	}

	int GearJointDef::getRatio(State & state, b2GearJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->ratio));
		return 1;
	}

	int GearJointDef::setRatio(State & state, b2GearJointDef * object){
		object->ratio = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}
};
