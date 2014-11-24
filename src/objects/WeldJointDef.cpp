#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Body.hpp"
#include "objects/JointDef.hpp"
#include "objects/WeldJointDef.hpp"

namespace LuaBox2D {
	void initWeldJointDef(State * state){
		state->registerInterface<WeldJointDef>("LuaBox2D_WeldJointDef");
	}

	b2WeldJointDef * WeldJointDef::constructor(State & state, bool & managed){
		JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
		b2JointDef * jointDef = interfaceJointDef->get(1);
		if (jointDef != nullptr){
			if (jointDef->type == b2JointType::e_weldJoint){
				managed = false;
				return reinterpret_cast<b2WeldJointDef*>(jointDef);
			}else{
				return new b2WeldJointDef();
			}
		}else{
			return new b2WeldJointDef();
		}
	}

	void WeldJointDef::destructor(State & state, b2WeldJointDef * object){
		delete object;
	}

	inline int WeldJointDef::getBodyA(State & state, b2WeldJointDef * object){
		return base->getBodyA(state, object);
	}

	inline int WeldJointDef::setBodyA(State & state, b2WeldJointDef * object){
		return base->setBodyA(state, object);
	}

	inline int WeldJointDef::getBodyB(State & state, b2WeldJointDef * object){
		return base->getBodyB(state, object);
	}

	inline int WeldJointDef::setBodyB(State & state, b2WeldJointDef * object){
		return base->setBodyB(state, object);
	}

	inline int WeldJointDef::getType(State & state, b2WeldJointDef * object){
		return base->getType(state, object);
	}

	inline int WeldJointDef::setType(State & state, b2WeldJointDef * object){
		return base->setType(state, object);
	}

	inline int WeldJointDef::getCollideConnected(State & state, b2WeldJointDef * object){
		return base->getCollideConnected(state, object);
	}

	inline int WeldJointDef::setCollideConnected(State & state, b2WeldJointDef * object){
		return base->setCollideConnected(state, object);
	}

	inline int WeldJointDef::getUserData(State & state, b2WeldJointDef * object){
		return base->getUserData(state, object);
	}

	inline int WeldJointDef::setUserData(State & state, b2WeldJointDef * object){
		return base->setUserData(state, object);
	}

	int WeldJointDef::initialize(State & state, b2WeldJointDef * object){
		Body * interfaceBody = state.getInterface<Body>("LuaBox2D_Body");
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");

		if (state.stack->is<LUA_TUSERDATA>(1) && state.stack->is<LUA_TUSERDATA>(2) && state.stack->is<LUA_TUSERDATA>(3)){
			b2Body * bodyA = interfaceBody->get(1);
			b2Body * bodyB = interfaceBody->get(2);
			b2Vec2 * anchor = interfaceVec2->get(3);

			if (bodyA != nullptr && bodyB != nullptr && anchor != nullptr){
				object->Initialize(bodyA, bodyB, *anchor);
			}
		}
		return 0;
	}

	int WeldJointDef::getLocalAnchorA(State & state, b2WeldJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->localAnchorA, false);
		return 1;
	}

	int WeldJointDef::setLocalAnchorA(State & state, b2WeldJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * anchor = interfaceVec2->get(1);
		if (anchor != nullptr){
			object->localAnchorA = *anchor;
		}
		return 0;
	}

	int WeldJointDef::getLocalAnchorB(State & state, b2WeldJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->localAnchorB, false);
		return 1;
	}

	int WeldJointDef::setLocalAnchorB(State & state, b2WeldJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * anchor = interfaceVec2->get(1);
		if (anchor != nullptr){
			object->localAnchorB = *anchor;
		}
		return 0;
	}

	int WeldJointDef::getReferenceAngle(State & state, b2WeldJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->referenceAngle));
		return 1;
	}

	int WeldJointDef::setReferenceAngle(State & state, b2WeldJointDef * object){
		object->referenceAngle = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int WeldJointDef::getFrequencyHz(State & state, b2WeldJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->frequencyHz));
		return 1;
	}

	int WeldJointDef::setFrequencyHz(State & state, b2WeldJointDef * object){
		object->frequencyHz = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int WeldJointDef::getDampingRatio(State & state, b2WeldJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->dampingRatio));
		return 1;
	}

	int WeldJointDef::setDampingRatio(State & state, b2WeldJointDef * object){
		object->dampingRatio = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

};
