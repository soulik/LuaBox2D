#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Body.hpp"
#include "objects/JointDef.hpp"
#include "objects/RopeJointDef.hpp"

namespace LuaBox2D {
	void initRopeJointDef(State * state){
		state->registerInterface<RopeJointDef>("LuaBox2D_RopeJointDef");
	}

	b2RopeJointDef * RopeJointDef::constructor(State & state, bool & managed){
		JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
		b2JointDef * jointDef = interfaceJointDef->get(1);
		if (jointDef != nullptr){
			if (jointDef->type == b2JointType::e_ropeJoint){
				managed = false;
				return reinterpret_cast<b2RopeJointDef*>(jointDef);
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

	inline int RopeJointDef::getUserData(State & state, b2RopeJointDef * object){
		return base->getUserData(state, object);
	}

	inline int RopeJointDef::setUserData(State & state, b2RopeJointDef * object){
		return base->setUserData(state, object);
	}

	int RopeJointDef::getLocalAnchorA(State & state, b2RopeJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->localAnchorA, false);
		return 1;
	}

	int RopeJointDef::setLocalAnchorA(State & state, b2RopeJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * anchor = interfaceVec2->get(1);
		if (anchor != nullptr){
			object->localAnchorA = *anchor;
		}
		return 0;
	}

	int RopeJointDef::getLocalAnchorB(State & state, b2RopeJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->localAnchorB, false);
		return 1;
	}

	int RopeJointDef::setLocalAnchorB(State & state, b2RopeJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * anchor = interfaceVec2->get(1);
		if (anchor != nullptr){
			object->localAnchorB = *anchor;
		}
		return 0;
	}

	int RopeJointDef::getMaxLength(State & state, b2RopeJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->maxLength));
		return 1;
	}

	int RopeJointDef::setMaxLength(State & state, b2RopeJointDef * object){
		object->maxLength = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

};
