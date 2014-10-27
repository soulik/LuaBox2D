#include "common.hpp"
#include "objects/MotorJoint.hpp"

namespace LuaBox2D {
	void initMotorJoint(State * state){
		state->registerInterface<MotorJoint>("LuaBox2D_MotorJoint");
	}

	inline int MotorJoint::getType(State & state, b2MotorJoint * object){
		return base->getType(state, object);
	}

	inline int MotorJoint::getBodyA(State & state, b2MotorJoint * object){
		return base->getBodyA(state, object);
	}

	inline int MotorJoint::getBodyB(State & state, b2MotorJoint * object){
		return base->getBodyB(state, object);
	}

	inline int MotorJoint::getAnchorA(State & state, b2MotorJoint * object){
		return base->getAnchorA(state, object);
	}

	inline int MotorJoint::getAnchorB(State & state, b2MotorJoint * object){
		return base->getAnchorB(state, object);
	}

	inline int MotorJoint::getReactionForce(State & state, b2MotorJoint * object){
		return base->getReactionForce(state, object);
	}

	inline int MotorJoint::getReactionTorque(State & state, b2MotorJoint * object){
		return base->getReactionTorque(state, object);
	}

	inline int MotorJoint::getActive(State & state, b2MotorJoint * object){
		return base->getActive(state, object);
	}

	inline int MotorJoint::getCollideConnected(State & state, b2MotorJoint * object){
		return base->getCollideConnected(state, object);
	}
};
