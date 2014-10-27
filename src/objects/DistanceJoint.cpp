#include "common.hpp"
#include "objects/DistanceJoint.hpp"

namespace LuaBox2D {
	void initDistanceJoint(State * state){
		state->registerInterface<DistanceJoint>("LuaBox2D_DistanceJoint");
	}

	inline int DistanceJoint::getType(State & state, b2DistanceJoint * object){
		return base->getType(state, object);
	}

	inline int DistanceJoint::getBodyA(State & state, b2DistanceJoint * object){
		return base->getBodyA(state, object);
	}

	inline int DistanceJoint::getBodyB(State & state, b2DistanceJoint * object){
		return base->getBodyB(state, object);
	}

	inline int DistanceJoint::getAnchorA(State & state, b2DistanceJoint * object){
		return base->getAnchorA(state, object);
	}

	inline int DistanceJoint::getAnchorB(State & state, b2DistanceJoint * object){
		return base->getAnchorB(state, object);
	}

	inline int DistanceJoint::getReactionForce(State & state, b2DistanceJoint * object){
		return base->getReactionForce(state, object);
	}

	inline int DistanceJoint::getReactionTorque(State & state, b2DistanceJoint * object){
		return base->getReactionTorque(state, object);
	}

	inline int DistanceJoint::getActive(State & state, b2DistanceJoint * object){
		return base->getActive(state, object);
	}

	inline int DistanceJoint::getCollideConnected(State & state, b2DistanceJoint * object){
		return base->getCollideConnected(state, object);
	}
};
