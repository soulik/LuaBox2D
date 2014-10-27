#include "common.hpp"
#include "objects/RopeJointDef.hpp"

namespace LuaBox2D {
	void initRopeJointDef(State * state){
		state->registerInterface<RopeJointDef>("LuaBox2D_RopeJointDef");
	}

	inline int RopeJointDef::getBodyA(State & state, b2RopeJointDef * object){
		return base->getBodyA(state, object);
	}

	inline int RopeJointDef::setBodyA(State & state, b2RopeJointDef * object){
		return base->setBodyA(state, object);
	}

	inline int RopeJointDef::getBodyB(State & state, b2RopeJointDef * object){
		return base->getBodyB(state, object);
	}

	inline int RopeJointDef::setBodyB(State & state, b2RopeJointDef * object){
		return base->setBodyB(state, object);
	}

	inline int RopeJointDef::getType(State & state, b2RopeJointDef * object){
		return base->getType(state, object);
	}

	inline int RopeJointDef::setType(State & state, b2RopeJointDef * object){
		return base->setType(state, object);
	}

	inline int RopeJointDef::getCollideConnected(State & state, b2RopeJointDef * object){
		return base->getCollideConnected(state, object);
	}

	inline int RopeJointDef::setCollideConnected(State & state, b2RopeJointDef * object){
		return base->setCollideConnected(state, object);
	}
};
