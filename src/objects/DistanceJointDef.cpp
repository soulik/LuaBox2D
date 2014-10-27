#include "common.hpp"
#include "objects/JointDef.hpp"
#include "objects/DistanceJointDef.hpp"

namespace LuaBox2D {
	void initDistanceJointDef(State * state){
		state->registerInterface<DistanceJointDef>("LuaBox2D_DistanceJointDef");
	}

	b2DistanceJointDef * DistanceJointDef::constructor(State & state){
		JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
		b2JointDef * jointDef = interfaceJointDef->get(1);
		if (jointDef != nullptr){
			if (jointDef->type == b2JointType::e_revoluteJoint){
				return new b2DistanceJointDef(*(b2DistanceJointDef*)(jointDef));
			}else{
				return new b2DistanceJointDef();
			}
		}else{
			return new b2DistanceJointDef();
		}
	}

	void DistanceJointDef::destructor(State & state, b2DistanceJointDef * object){
		delete object;
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
