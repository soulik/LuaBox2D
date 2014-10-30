#include "common.hpp"
#include "objects/Joint.hpp"
#include "objects/WeldJoint.hpp"

namespace LuaBox2D {
	void initWeldJoint(State * state){
		state->registerInterface<WeldJoint>("LuaBox2D_WeldJoint");
	}

	b2WeldJoint * WeldJoint::constructor(State & state){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		b2Joint * joint = interfaceJoint->get(1);
		if (joint != nullptr){
			if (joint->GetType() == b2JointType::e_weldJoint){
				return new b2WeldJoint(*dynamic_cast<b2WeldJoint*>(joint));
			}else{
				return nullptr;
			}
		}else{
			return nullptr;
		}
	}

	void WeldJoint::destructor(State & state, b2WeldJoint * object){
		base->destructor(state, object);
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
