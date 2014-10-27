#include "common.hpp"
#include "objects/PrismaticJoint.hpp"

namespace LuaBox2D {
	void initPrismaticJoint(State * state){
		state->registerInterface<PrismaticJoint>("LuaBox2D_PrismaticJoint");
	}

	inline int PrismaticJoint::getType(State & state, b2PrismaticJoint * object){
		return base->getType(state, object);
	}

	inline int PrismaticJoint::getBodyA(State & state, b2PrismaticJoint * object){
		return base->getBodyA(state, object);
	}

	inline int PrismaticJoint::getBodyB(State & state, b2PrismaticJoint * object){
		return base->getBodyB(state, object);
	}

	inline int PrismaticJoint::getAnchorA(State & state, b2PrismaticJoint * object){
		return base->getAnchorA(state, object);
	}

	inline int PrismaticJoint::getAnchorB(State & state, b2PrismaticJoint * object){
		return base->getAnchorB(state, object);
	}

	inline int PrismaticJoint::getReactionForce(State & state, b2PrismaticJoint * object){
		return base->getReactionForce(state, object);
	}

	inline int PrismaticJoint::getReactionTorque(State & state, b2PrismaticJoint * object){
		return base->getReactionTorque(state, object);
	}

	inline int PrismaticJoint::getActive(State & state, b2PrismaticJoint * object){
		return base->getActive(state, object);
	}

	inline int PrismaticJoint::getCollideConnected(State & state, b2PrismaticJoint * object){
		return base->getCollideConnected(state, object);
	}
};
