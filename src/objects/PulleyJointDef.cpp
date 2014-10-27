#include "common.hpp"
#include "objects/PulleyJointDef.hpp"

namespace LuaBox2D {
	void initPulleyJointDef(State * state){
		state->registerInterface<PulleyJointDef>("LuaBox2D_PulleyJointDef");
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
