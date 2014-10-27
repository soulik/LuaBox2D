#include "common.hpp"
#include "objects/Joint.hpp"
#include "objects/MotorJoint.hpp"

namespace LuaBox2D {
	void initMotorJoint(State * state){
		state->registerInterface<MotorJoint>("LuaBox2D_MotorJoint");
	}

	b2MotorJoint * MotorJoint::constructor(State & state){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		b2Joint * joint = interfaceJoint->get(1);
		if (joint != nullptr){
			if (joint->GetType() == b2JointType::e_revoluteJoint){
				return new b2MotorJoint(*dynamic_cast<b2MotorJoint*>(joint));
			}else{
				return nullptr;
			}
		}else{
			return nullptr;
		}
	}

	void MotorJoint::destructor(State & state, b2MotorJoint * object){
		delete object;
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
