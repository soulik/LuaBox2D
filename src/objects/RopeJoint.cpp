#include "common.hpp"
#include "objects/Joint.hpp"
#include "objects/RopeJoint.hpp"

namespace LuaBox2D {
	void initRopeJoint(State * state){
		state->registerInterface<RopeJoint>("LuaBox2D_RopeJoint");
	}

	b2RopeJoint * RopeJoint::constructor(State & state){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		b2Joint * joint = interfaceJoint->get(1);
		if (joint != nullptr){
			if (joint->GetType() == b2JointType::e_revoluteJoint){
				return new b2RopeJoint(*dynamic_cast<b2RopeJoint*>(joint));
			}else{
				return nullptr;
			}
		}else{
			return nullptr;
		}
	}

	void RopeJoint::destructor(State & state, b2RopeJoint * object){
		delete object;
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
