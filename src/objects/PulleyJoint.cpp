#include "common.hpp"
#include "objects/PulleyJoint.hpp"

namespace LuaBox2D {
	void initPulleyJoint(State * state){
		state->registerInterface<PulleyJoint>("LuaBox2D_PulleyJoint");
	}

	inline int PulleyJoint::getType(State & state, b2PulleyJoint * object){
		return base->getType(state, object);
	}

	inline int PulleyJoint::getBodyA(State & state, b2PulleyJoint * object){
		return base->getBodyA(state, object);
	}

	inline int PulleyJoint::getBodyB(State & state, b2PulleyJoint * object){
		return base->getBodyB(state, object);
	}

	inline int PulleyJoint::getAnchorA(State & state, b2PulleyJoint * object){
		return base->getAnchorA(state, object);
	}

	inline int PulleyJoint::getAnchorB(State & state, b2PulleyJoint * object){
		return base->getAnchorB(state, object);
	}

	inline int PulleyJoint::getReactionForce(State & state, b2PulleyJoint * object){
		return base->getReactionForce(state, object);
	}

	inline int PulleyJoint::getReactionTorque(State & state, b2PulleyJoint * object){
		return base->getReactionTorque(state, object);
	}

	inline int PulleyJoint::getActive(State & state, b2PulleyJoint * object){
		return base->getActive(state, object);
	}

	inline int PulleyJoint::getCollideConnected(State & state, b2PulleyJoint * object){
		return base->getCollideConnected(state, object);
	}
};
