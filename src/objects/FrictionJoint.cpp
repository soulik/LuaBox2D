#include "common.hpp"
#include "objects/Joint.hpp"
#include "objects/FrictionJoint.hpp"

namespace LuaBox2D {
	void initFrictionJoint(State * state){
		state->registerInterface<FrictionJoint>("LuaBox2D_FrictionJoint");
	}

	b2FrictionJoint * FrictionJoint::constructor(State & state){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		b2Joint * joint = interfaceJoint->get(1);
		if (joint != nullptr){
			if (joint->GetType() == b2JointType::e_frictionJoint){
				return new b2FrictionJoint(*dynamic_cast<b2FrictionJoint*>(joint));
			}else{
				return nullptr;
			}
		}else{
			return nullptr;
		}
	}

	void FrictionJoint::destructor(State & state, b2FrictionJoint * object){
		delete object;
	}

	inline int FrictionJoint::getType(State & state, b2FrictionJoint * object){
		return base->getType(state, object);
	}

	inline int FrictionJoint::getBodyA(State & state, b2FrictionJoint * object){
		return base->getBodyA(state, object);
	}

	inline int FrictionJoint::getBodyB(State & state, b2FrictionJoint * object){
		return base->getBodyB(state, object);
	}

	inline int FrictionJoint::getAnchorA(State & state, b2FrictionJoint * object){
		return base->getAnchorA(state, object);
	}

	inline int FrictionJoint::getAnchorB(State & state, b2FrictionJoint * object){
		return base->getAnchorB(state, object);
	}

	inline int FrictionJoint::getReactionForce(State & state, b2FrictionJoint * object){
		return base->getReactionForce(state, object);
	}

	inline int FrictionJoint::getReactionTorque(State & state, b2FrictionJoint * object){
		return base->getReactionTorque(state, object);
	}

	inline int FrictionJoint::getActive(State & state, b2FrictionJoint * object){
		return base->getActive(state, object);
	}

	inline int FrictionJoint::getCollideConnected(State & state, b2FrictionJoint * object){
		return base->getCollideConnected(state, object);
	}
};
