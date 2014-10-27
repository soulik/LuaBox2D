#include "common.hpp"
#include "objects/GearJoint.hpp"

namespace LuaBox2D {
	void initGearJoint(State * state){
		state->registerInterface<GearJoint>("LuaBox2D_GearJoint");
	}

	inline int GearJoint::getType(State & state, b2GearJoint * object){
		return base->getType(state, object);
	}

	inline int GearJoint::getBodyA(State & state, b2GearJoint * object){
		return base->getBodyA(state, object);
	}

	inline int GearJoint::getBodyB(State & state, b2GearJoint * object){
		return base->getBodyB(state, object);
	}

	inline int GearJoint::getAnchorA(State & state, b2GearJoint * object){
		return base->getAnchorA(state, object);
	}

	inline int GearJoint::getAnchorB(State & state, b2GearJoint * object){
		return base->getAnchorB(state, object);
	}

	inline int GearJoint::getReactionForce(State & state, b2GearJoint * object){
		return base->getReactionForce(state, object);
	}

	inline int GearJoint::getReactionTorque(State & state, b2GearJoint * object){
		return base->getReactionTorque(state, object);
	}

	inline int GearJoint::getActive(State & state, b2GearJoint * object){
		return base->getActive(state, object);
	}

	inline int GearJoint::getCollideConnected(State & state, b2GearJoint * object){
		return base->getCollideConnected(state, object);
	}
};
