#include "common.hpp"
#include "objects/JointDef.hpp"
#include "objects/RevoluteJointDef.hpp"

namespace LuaBox2D {
	void initRevoluteJointDef(State * state){
		state->registerInterface<RevoluteJointDef>("LuaBox2D_RevoluteJointDef");
	}

	b2RevoluteJointDef * RevoluteJointDef::constructor(State & state){
		JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
		b2JointDef * jointDef = interfaceJointDef->get(1);
		if (jointDef != nullptr){
			if (jointDef->type == b2JointType::e_revoluteJoint){
				return new b2RevoluteJointDef(*(b2RevoluteJointDef*)(jointDef));
			}else{
				return new b2RevoluteJointDef();
			}
		}else{
			return new b2RevoluteJointDef();
		}
	}

	void RevoluteJointDef::destructor(State & state, b2RevoluteJointDef * object){
		delete object;
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
