#include "common.hpp"
#include "objects/Joint.hpp"
#include "objects/PulleyJoint.hpp"

namespace LuaBox2D {
	void initPulleyJoint(State * state){
		state->registerInterface<PulleyJoint>("LuaBox2D_PulleyJoint");
	}

	b2PulleyJoint * PulleyJoint::constructor(State & state){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		b2Joint * joint = interfaceJoint->get(1);
		if (joint != nullptr){
			if (joint->GetType() == b2JointType::e_revoluteJoint){
				return new b2PulleyJoint(*dynamic_cast<b2PulleyJoint*>(joint));
			}else{
				return nullptr;
			}
		}else{
			return nullptr;
		}
	}

	void PulleyJoint::destructor(State & state, b2PulleyJoint * object){
		delete object;
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
