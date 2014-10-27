#include "common.hpp"
#include "objects/DistanceJointDef.hpp"

namespace LuaBox2D {
	void initDistanceJointDef(State * state){
		state->registerInterface<DistanceJointDef>("LuaBox2D_DistanceJointDef");
	}

	inline int DistanceJointDef::getBodyA(State & state, b2DistanceJointDef * object){
		return base->getBodyA(state, object);
	}

	inline int DistanceJointDef::setBodyA(State & state, b2DistanceJointDef * object){
		return base->setBodyA(state, object);
	}

	inline int DistanceJointDef::getBodyB(State & state, b2DistanceJointDef * object){
		return base->getBodyB(state, object);
	}

	inline int DistanceJointDef::setBodyB(State & state, b2DistanceJointDef * object){
		return base->setBodyB(state, object);
	}

	inline int DistanceJointDef::getType(State & state, b2DistanceJointDef * object){
		return base->getType(state, object);
	}

	inline int DistanceJointDef::setType(State & state, b2DistanceJointDef * object){
		return base->setType(state, object);
	}

	inline int DistanceJointDef::getCollideConnected(State & state, b2DistanceJointDef * object){
		return base->getCollideConnected(state, object);
	}

	inline int DistanceJointDef::setCollideConnected(State & state, b2DistanceJointDef * object){
		return base->setCollideConnected(state, object);
	}
};
