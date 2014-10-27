#include "common.hpp"
#include "objects/JointDef.hpp"
#include "objects/GearJointDef.hpp"

namespace LuaBox2D {
	void initGearJointDef(State * state){
		state->registerInterface<GearJointDef>("LuaBox2D_GearJointDef");
	}

	b2GearJointDef * GearJointDef::constructor(State & state){
		JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
		b2JointDef * jointDef = interfaceJointDef->get(1);
		if (jointDef != nullptr){
			if (jointDef->type == b2JointType::e_revoluteJoint){
				return new b2GearJointDef(*(b2GearJointDef*)(jointDef));
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
};
