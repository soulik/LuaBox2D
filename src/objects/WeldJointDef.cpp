#include "common.hpp"
#include "objects/JointDef.hpp"
#include "objects/WeldJointDef.hpp"

namespace LuaBox2D {
	void initWeldJointDef(State * state){
		state->registerInterface<WeldJointDef>("LuaBox2D_WeldJointDef");
	}

	b2WeldJointDef * WeldJointDef::constructor(State & state){
		JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
		b2JointDef * jointDef = interfaceJointDef->get(1);
		if (jointDef != nullptr){
			if (jointDef->type == b2JointType::e_weldJoint){
				return new b2WeldJointDef(*(b2WeldJointDef*)(jointDef));
			}else{
				return new b2WeldJointDef();
			}
		}else{
			return new b2WeldJointDef();
		}
	}

	void WeldJointDef::destructor(State & state, b2WeldJointDef * object){
		delete object;
	}

	inline int WeldJointDef::getBodyA(State & state, b2WeldJointDef * object){
		return base->getBodyA(state, object);
	}

	inline int WeldJointDef::setBodyA(State & state, b2WeldJointDef * object){
		return base->setBodyA(state, object);
	}

	inline int WeldJointDef::getBodyB(State & state, b2WeldJointDef * object){
		return base->getBodyB(state, object);
	}

	inline int WeldJointDef::setBodyB(State & state, b2WeldJointDef * object){
		return base->setBodyB(state, object);
	}

	inline int WeldJointDef::getType(State & state, b2WeldJointDef * object){
		return base->getType(state, object);
	}

	inline int WeldJointDef::setType(State & state, b2WeldJointDef * object){
		return base->setType(state, object);
	}

	inline int WeldJointDef::getCollideConnected(State & state, b2WeldJointDef * object){
		return base->getCollideConnected(state, object);
	}

	inline int WeldJointDef::setCollideConnected(State & state, b2WeldJointDef * object){
		return base->setCollideConnected(state, object);
	}
};
