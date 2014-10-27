#include "common.hpp"
#include "objects/JointDef.hpp"
#include "objects/PulleyJointDef.hpp"

namespace LuaBox2D {
	void initPulleyJointDef(State * state){
		state->registerInterface<PulleyJointDef>("LuaBox2D_PulleyJointDef");
	}

	b2PulleyJointDef * PulleyJointDef::constructor(State & state){
		JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
		b2JointDef * jointDef = interfaceJointDef->get(1);
		if (jointDef != nullptr){
			if (jointDef->type == b2JointType::e_pulleyJoint){
				return new b2PulleyJointDef(*(b2PulleyJointDef*)(jointDef));
			}else{
				return new b2PulleyJointDef();
			}
		}else{
			return new b2PulleyJointDef();
		}
	}

	void PulleyJointDef::destructor(State & state, b2PulleyJointDef * object){
		delete object;
	}

	inline int PulleyJointDef::getBodyA(State & state, b2PulleyJointDef * object){
		return base->getBodyA(state, object);
	}

	inline int PulleyJointDef::setBodyA(State & state, b2PulleyJointDef * object){
		return base->setBodyA(state, object);
	}

	inline int PulleyJointDef::getBodyB(State & state, b2PulleyJointDef * object){
		return base->getBodyB(state, object);
	}

	inline int PulleyJointDef::setBodyB(State & state, b2PulleyJointDef * object){
		return base->setBodyB(state, object);
	}

	inline int PulleyJointDef::getType(State & state, b2PulleyJointDef * object){
		return base->getType(state, object);
	}

	inline int PulleyJointDef::setType(State & state, b2PulleyJointDef * object){
		return base->setType(state, object);
	}

	inline int PulleyJointDef::getCollideConnected(State & state, b2PulleyJointDef * object){
		return base->getCollideConnected(state, object);
	}

	inline int PulleyJointDef::setCollideConnected(State & state, b2PulleyJointDef * object){
		return base->setCollideConnected(state, object);
	}
};
