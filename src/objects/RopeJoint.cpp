#include "common.hpp"
#include "objects/RopeJoint.hpp"

namespace LuaBox2D {
	void initRopeJoint(State * state){
		state->registerInterface<RopeJoint>("LuaBox2D_RopeJoint");
	}

	inline int RopeJoint::getType(State & state, b2RopeJoint * object){
		return base->getType(state, object);
	}

	inline int RopeJoint::getBodyA(State & state, b2RopeJoint * object){
		return base->getBodyA(state, object);
	}

	inline int RopeJoint::getBodyB(State & state, b2RopeJoint * object){
		return base->getBodyB(state, object);
	}

	inline int RopeJoint::getAnchorA(State & state, b2RopeJoint * object){
		return base->getAnchorA(state, object);
	}

	inline int RopeJoint::getAnchorB(State & state, b2RopeJoint * object){
		return base->getAnchorB(state, object);
	}

	inline int RopeJoint::getReactionForce(State & state, b2RopeJoint * object){
		return base->getReactionForce(state, object);
	}

	inline int RopeJoint::getReactionTorque(State & state, b2RopeJoint * object){
		return base->getReactionTorque(state, object);
	}

	inline int RopeJoint::getActive(State & state, b2RopeJoint * object){
		return base->getActive(state, object);
	}

	inline int RopeJoint::getCollideConnected(State & state, b2RopeJoint * object){
		return base->getCollideConnected(state, object);
	}
};
