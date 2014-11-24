#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Body.hpp"
#include "objects/JointDef.hpp"
#include "objects/MouseJointDef.hpp"

namespace LuaBox2D {
	void initMouseJointDef(State * state){
		state->registerInterface<MouseJointDef>("LuaBox2D_MouseJointDef");
	}

	b2MouseJointDef * MouseJointDef::constructor(State & state, bool & managed){
		JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
		b2JointDef * jointDef = interfaceJointDef->get(1);
		if (jointDef != nullptr){
			if (jointDef->type == b2JointType::e_mouseJoint){
				managed = false;
				return reinterpret_cast<b2MouseJointDef*>(jointDef);
			}else{
				return new b2MouseJointDef();
			}
		}else{
			return new b2MouseJointDef();
		}
	}

	void MouseJointDef::destructor(State & state, b2MouseJointDef * object){
		delete object;
	}

	inline int MouseJointDef::getBodyA(State & state, b2MouseJointDef * object){
		return base->getBodyA(state, object);
	}

	inline int MouseJointDef::setBodyA(State & state, b2MouseJointDef * object){
		return base->setBodyA(state, object);
	}

	inline int MouseJointDef::getBodyB(State & state, b2MouseJointDef * object){
		return base->getBodyB(state, object);
	}

	inline int MouseJointDef::setBodyB(State & state, b2MouseJointDef * object){
		return base->setBodyB(state, object);
	}

	inline int MouseJointDef::getType(State & state, b2MouseJointDef * object){
		return base->getType(state, object);
	}

	inline int MouseJointDef::setType(State & state, b2MouseJointDef * object){
		return base->setType(state, object);
	}

	inline int MouseJointDef::getCollideConnected(State & state, b2MouseJointDef * object){
		return base->getCollideConnected(state, object);
	}

	inline int MouseJointDef::setCollideConnected(State & state, b2MouseJointDef * object){
		return base->setCollideConnected(state, object);
	}

	inline int MouseJointDef::getUserData(State & state, b2MouseJointDef * object){
		return base->getUserData(state, object);
	}

	inline int MouseJointDef::setUserData(State & state, b2MouseJointDef * object){
		return base->setUserData(state, object);
	}

	int MouseJointDef::getTarget(State & state, b2MouseJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->target, false);
		return 1;
	}

	int MouseJointDef::setTarget(State & state, b2MouseJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * linearOffset = interfaceVec2->get(1);
		if (linearOffset != nullptr){
			object->target = *linearOffset;
		}
		return 0;
	}

	int MouseJointDef::getMaxForce(State & state, b2MouseJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->maxForce));
		return 1;
	}

	int MouseJointDef::setMaxForce(State & state, b2MouseJointDef * object){
		object->maxForce = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int MouseJointDef::getFrequencyHz(State & state, b2MouseJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->frequencyHz));
		return 1;
	}

	int MouseJointDef::setFrequencyHz(State & state, b2MouseJointDef * object){
		object->frequencyHz = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int MouseJointDef::getDampingRatio(State & state, b2MouseJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->dampingRatio));
		return 1;
	}

	int MouseJointDef::setDampingRatio(State & state, b2MouseJointDef * object){
		object->dampingRatio = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}
};
