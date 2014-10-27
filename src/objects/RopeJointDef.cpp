#include "common.hpp"
#include "objects/JointDef.hpp"
#include "objects/RopeJointDef.hpp"

namespace LuaBox2D {
	void initRopeJointDef(State * state){
		state->registerInterface<RopeJointDef>("LuaBox2D_RopeJointDef");
	}

	b2RopeJointDef * RopeJointDef::constructor(State & state){
		JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
		b2JointDef * jointDef = interfaceJointDef->get(1);
		if (jointDef != nullptr){
			if (jointDef->type == b2JointType::e_ropeJoint){
				return new b2RopeJointDef(*(b2RopeJointDef*)(jointDef));
			}else{
				return new b2RopeJointDef();
			}
		}else{
			return new b2RopeJointDef();
		}
	}

	void RopeJointDef::destructor(State & state, b2RopeJointDef * object){
		delete object;
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
