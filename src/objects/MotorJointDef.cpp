#include "common.hpp"
#include "objects/MotorJointDef.hpp"

namespace LuaBox2D {
	void initMotorJointDef(State * state){
		state->registerInterface<MotorJointDef>("LuaBox2D_MotorJointDef");
	}

	inline int MotorJointDef::getBodyA(State & state, b2MotorJointDef * object){
		return base->getBodyA(state, object);
	}

	inline int MotorJointDef::setBodyA(State & state, b2MotorJointDef * object){
		return base->setBodyA(state, object);
	}

	inline int MotorJointDef::getBodyB(State & state, b2MotorJointDef * object){
		return base->getBodyB(state, object);
	}

	inline int MotorJointDef::setBodyB(State & state, b2MotorJointDef * object){
		return base->setBodyB(state, object);
	}

	inline int MotorJointDef::getType(State & state, b2MotorJointDef * object){
		return base->getType(state, object);
	}

	inline int MotorJointDef::setType(State & state, b2MotorJointDef * object){
		return base->setType(state, object);
	}

	inline int MotorJointDef::getCollideConnected(State & state, b2MotorJointDef * object){
		return base->getCollideConnected(state, object);
	}

	inline int MotorJointDef::setCollideConnected(State & state, b2MotorJointDef * object){
		return base->setCollideConnected(state, object);
	}
};
