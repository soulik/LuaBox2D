#include "common.hpp"
#include "objects/JointDef.hpp"
#include "objects/MouseJointDef.hpp"

namespace LuaBox2D {
	void initMouseJointDef(State * state){
		state->registerInterface<MouseJointDef>("LuaBox2D_MouseJointDef");
	}

	b2MouseJointDef * MouseJointDef::constructor(State & state){
		JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
		b2JointDef * jointDef = interfaceJointDef->get(1);
		if (jointDef != nullptr){
			if (jointDef->type == b2JointType::e_revoluteJoint){
				return new b2MouseJointDef(*(b2MouseJointDef*)(jointDef));
			}else{
				return new b2MouseJointDef();
			}
		}else{
			return new b2MouseJointDef();
		}
	}

	void MouseJointDef::destructor(State & state, b2MouseJointDef * object){
		delete object;
	}

	inline int MouseJointDef::getBodyA(State & state, b2MouseJointDef * object){
		return base->getBodyA(state, object);
	}

	inline int MouseJointDef::setBodyA(State & state, b2MouseJointDef * object){
		return base->setBodyA(state, object);
	}

	inline int MouseJointDef::getBodyB(State & state, b2MouseJointDef * object){
		return base->getBodyB(state, object);
	}

	inline int MouseJointDef::setBodyB(State & state, b2MouseJointDef * object){
		return base->setBodyB(state, object);
	}

	inline int MouseJointDef::getType(State & state, b2MouseJointDef * object){
		return base->getType(state, object);
	}

	inline int MouseJointDef::setType(State & state, b2MouseJointDef * object){
		return base->setType(state, object);
	}

	inline int MouseJointDef::getCollideConnected(State & state, b2MouseJointDef * object){
		return base->getCollideConnected(state, object);
	}

	inline int MouseJointDef::setCollideConnected(State & state, b2MouseJointDef * object){
		return base->setCollideConnected(state, object);
	}
};
