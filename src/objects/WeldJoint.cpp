#include "common.hpp"
#include "objects/WeldJoint.hpp"

namespace LuaBox2D {
	void initWeldJoint(State * state){
		state->registerInterface<WeldJoint>("LuaBox2D_WeldJoint");
	}

	inline int WeldJoint::getType(State & state, b2WeldJoint * object){
		return base->getType(state, object);
	}

	inline int WeldJoint::getBodyA(State & state, b2WeldJoint * object){
		return base->getBodyA(state, object);
	}

	inline int WeldJoint::getBodyB(State & state, b2WeldJoint * object){
		return base->getBodyB(state, object);
	}

	inline int WeldJoint::getAnchorA(State & state, b2WeldJoint * object){
		return base->getAnchorA(state, object);
	}

	inline int WeldJoint::getAnchorB(State & state, b2WeldJoint * object){
		return base->getAnchorB(state, object);
	}

	inline int WeldJoint::getReactionForce(State & state, b2WeldJoint * object){
		return base->getReactionForce(state, object);
	}

	inline int WeldJoint::getReactionTorque(State & state, b2WeldJoint * object){
		return base->getReactionTorque(state, object);
	}

	inline int WeldJoint::getActive(State & state, b2WeldJoint * object){
		return base->getActive(state, object);
	}

	inline int WeldJoint::getCollideConnected(State & state, b2WeldJoint * object){
		return base->getCollideConnected(state, object);
	}
};
