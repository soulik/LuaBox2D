#include "common.hpp"
#include "objects/WheelJoint.hpp"

namespace LuaBox2D {
	void initWheelJoint(State * state){
		state->registerInterface<WheelJoint>("LuaBox2D_WheelJoint");
	}

	inline int WheelJoint::getType(State & state, b2WheelJoint * object){
		return base->getType(state, object);
	}

	inline int WheelJoint::getBodyA(State & state, b2WheelJoint * object){
		return base->getBodyA(state, object);
	}

	inline int WheelJoint::getBodyB(State & state, b2WheelJoint * object){
		return base->getBodyB(state, object);
	}

	inline int WheelJoint::getAnchorA(State & state, b2WheelJoint * object){
		return base->getAnchorA(state, object);
	}

	inline int WheelJoint::getAnchorB(State & state, b2WheelJoint * object){
		return base->getAnchorB(state, object);
	}

	inline int WheelJoint::getReactionForce(State & state, b2WheelJoint * object){
		return base->getReactionForce(state, object);
	}

	inline int WheelJoint::getReactionTorque(State & state, b2WheelJoint * object){
		return base->getReactionTorque(state, object);
	}

	inline int WheelJoint::getActive(State & state, b2WheelJoint * object){
		return base->getActive(state, object);
	}

	inline int WheelJoint::getCollideConnected(State & state, b2WheelJoint * object){
		return base->getCollideConnected(state, object);
	}
};
