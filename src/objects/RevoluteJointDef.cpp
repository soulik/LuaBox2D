#include "common.hpp"
#include "objects/RevoluteJointDef.hpp"

namespace LuaBox2D {
	void initRevoluteJointDef(State * state){
		state->registerInterface<RevoluteJointDef>("LuaBox2D_RevoluteJointDef");
	}

	inline int RevoluteJointDef::getBodyA(State & state, b2RevoluteJointDef * object){
		return base->getBodyA(state, object);
	}

	inline int RevoluteJointDef::setBodyA(State & state, b2RevoluteJointDef * object){
		return base->setBodyA(state, object);
	}

	inline int RevoluteJointDef::getBodyB(State & state, b2RevoluteJointDef * object){
		return base->getBodyB(state, object);
	}

	inline int RevoluteJointDef::setBodyB(State & state, b2RevoluteJointDef * object){
		return base->setBodyB(state, object);
	}

	inline int RevoluteJointDef::getType(State & state, b2RevoluteJointDef * object){
		return base->getType(state, object);
	}

	inline int RevoluteJointDef::setType(State & state, b2RevoluteJointDef * object){
		return base->setType(state, object);
	}

	inline int RevoluteJointDef::getCollideConnected(State & state, b2RevoluteJointDef * object){
		return base->getCollideConnected(state, object);
	}

	inline int RevoluteJointDef::setCollideConnected(State & state, b2RevoluteJointDef * object){
		return base->setCollideConnected(state, object);
	}
};
