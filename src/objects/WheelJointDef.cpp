#include "common.hpp"
#include "objects/JointDef.hpp"
#include "objects/WheelJointDef.hpp"

namespace LuaBox2D {
	void initWheelJointDef(State * state){
		state->registerInterface<WheelJointDef>("LuaBox2D_WheelJointDef");
	}

	b2WheelJointDef * WheelJointDef::constructor(State & state){
		JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
		b2JointDef * jointDef = interfaceJointDef->get(1);
		if (jointDef != nullptr){
			if (jointDef->type == b2JointType::e_wheelJoint){
				return new b2WheelJointDef(*(b2WheelJointDef*)(jointDef));
			}else{
				return new b2WheelJointDef();
			}
		}else{
			return new b2WheelJointDef();
		}
	}

	void WheelJointDef::destructor(State & state, b2WheelJointDef * object){
		delete object;
	}

	inline int WheelJointDef::getBodyA(State & state, b2WheelJointDef * object){
		return base->getBodyA(state, object);
	}

	inline int WheelJointDef::setBodyA(State & state, b2WheelJointDef * object){
		return base->setBodyA(state, object);
	}

	inline int WheelJointDef::getBodyB(State & state, b2WheelJointDef * object){
		return base->getBodyB(state, object);
	}

	inline int WheelJointDef::setBodyB(State & state, b2WheelJointDef * object){
		return base->setBodyB(state, object);
	}

	inline int WheelJointDef::getType(State & state, b2WheelJointDef * object){
		return base->getType(state, object);
	}

	inline int WheelJointDef::setType(State & state, b2WheelJointDef * object){
		return base->setType(state, object);
	}

	inline int WheelJointDef::getCollideConnected(State & state, b2WheelJointDef * object){
		return base->getCollideConnected(state, object);
	}

	inline int WheelJointDef::setCollideConnected(State & state, b2WheelJointDef * object){
		return base->setCollideConnected(state, object);
	}
};
