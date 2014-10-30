#include "common.hpp"
#include "objects/Joint.hpp"
#include "objects/MouseJoint.hpp"

namespace LuaBox2D {
	void initMouseJoint(State * state){
		state->registerInterface<MouseJoint>("LuaBox2D_MouseJoint");
	}

	b2MouseJoint * MouseJoint::constructor(State & state){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		b2Joint * joint = interfaceJoint->get(1);
		if (joint != nullptr){
			if (joint->GetType() == b2JointType::e_mouseJoint){
				return new b2MouseJoint(*dynamic_cast<b2MouseJoint*>(joint));
			}else{
				return nullptr;
			}
		}else{
			return nullptr;
		}
	}

	void MouseJoint::destructor(State & state, b2MouseJoint * object){
		base->destructor(state, object);
	}

	inline int MouseJoint::getType(State & state, b2MouseJoint * object){
		return base->getType(state, object);
	}

	inline int MouseJoint::getBodyA(State & state, b2MouseJoint * object){
		return base->getBodyA(state, object);
	}

	inline int MouseJoint::getBodyB(State & state, b2MouseJoint * object){
		return base->getBodyB(state, object);
	}

	inline int MouseJoint::getAnchorA(State & state, b2MouseJoint * object){
		return base->getAnchorA(state, object);
	}

	inline int MouseJoint::getAnchorB(State & state, b2MouseJoint * object){
		return base->getAnchorB(state, object);
	}

	inline int MouseJoint::getReactionForce(State & state, b2MouseJoint * object){
		return base->getReactionForce(state, object);
	}

	inline int MouseJoint::getReactionTorque(State & state, b2MouseJoint * object){
		return base->getReactionTorque(state, object);
	}

	inline int MouseJoint::getActive(State & state, b2MouseJoint * object){
		return base->getActive(state, object);
	}

	inline int MouseJoint::getCollideConnected(State & state, b2MouseJoint * object){
		return base->getCollideConnected(state, object);
	}
};
