#include "common.hpp"
#include "objects/Joint.hpp"
#include "objects/GearJoint.hpp"

namespace LuaBox2D {
	void initGearJoint(State * state){
		state->registerInterface<GearJoint>("LuaBox2D_GearJoint");
	}

	b2GearJoint * GearJoint::constructor(State & state){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		b2Joint * joint = interfaceJoint->get(1);
		if (joint != nullptr){
			if (joint->GetType() == b2JointType::e_gearJoint){
				return new b2GearJoint(*dynamic_cast<b2GearJoint*>(joint));
			}else{
				return nullptr;
			}
		}else{
			return nullptr;
		}
	}

	void GearJoint::destructor(State & state, b2GearJoint * object){
		base->destructor(state, object);
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
