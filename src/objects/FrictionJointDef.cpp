#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Body.hpp"
#include "objects/JointDef.hpp"
#include "objects/FrictionJointDef.hpp"

namespace LuaBox2D {
	void initFrictionJointDef(State * state){
		state->registerInterface<FrictionJointDef>("LuaBox2D_FrictionJointDef");
	}

	b2FrictionJointDef * FrictionJointDef::constructor(State & state, bool & managed){
		JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
		b2JointDef * jointDef = interfaceJointDef->get(1);
		if (jointDef != nullptr){
			if (jointDef->type == b2JointType::e_frictionJoint){
				managed = false;
				return reinterpret_cast<b2FrictionJointDef*>(jointDef);
			}else{
				return new b2FrictionJointDef();
			}
		}else{
			return new b2FrictionJointDef();
		}
	}

	void FrictionJointDef::destructor(State & state, b2FrictionJointDef * object){
		delete object;
	}

	inline int FrictionJointDef::getBodyA(State & state, b2FrictionJointDef * object){
		return base->getBodyA(state, object);
	}

	inline int FrictionJointDef::setBodyA(State & state, b2FrictionJointDef * object){
		return base->setBodyA(state, object);
	}

	inline int FrictionJointDef::getBodyB(State & state, b2FrictionJointDef * object){
		return base->getBodyB(state, object);
	}

	inline int FrictionJointDef::setBodyB(State & state, b2FrictionJointDef * object){
		return base->setBodyB(state, object);
	}

	inline int FrictionJointDef::getType(State & state, b2FrictionJointDef * object){
		return base->getType(state, object);
	}

	inline int FrictionJointDef::setType(State & state, b2FrictionJointDef * object){
		return base->setType(state, object);
	}

	inline int FrictionJointDef::getCollideConnected(State & state, b2FrictionJointDef * object){
		return base->getCollideConnected(state, object);
	}

	inline int FrictionJointDef::setCollideConnected(State & state, b2FrictionJointDef * object){
		return base->setCollideConnected(state, object);
	}

	inline int FrictionJointDef::getUserData(State & state, b2FrictionJointDef * object){
		return base->getUserData(state, object);
	}

	inline int FrictionJointDef::setUserData(State & state, b2FrictionJointDef * object){
		return base->setUserData(state, object);
	}

	int FrictionJointDef::initialize(State & state, b2FrictionJointDef * object){
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

	int FrictionJointDef::getLocalAnchorA(State & state, b2FrictionJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->localAnchorA, false);
		return 1;
	}

	int FrictionJointDef::setLocalAnchorA(State & state, b2FrictionJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * anchor = interfaceVec2->get(1);
		if (anchor != nullptr){
			object->localAnchorA = *anchor;
		}
		return 0;
	}

	int FrictionJointDef::getLocalAnchorB(State & state, b2FrictionJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->localAnchorB, false);
		return 1;
	}

	int FrictionJointDef::setLocalAnchorB(State & state, b2FrictionJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * anchor = interfaceVec2->get(1);
		if (anchor != nullptr){
			object->localAnchorB = *anchor;
		}
		return 0;
	}

	int FrictionJointDef::getMaxForce(State & state, b2FrictionJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->maxForce));
		return 1;
	}

	int FrictionJointDef::setMaxForce(State & state, b2FrictionJointDef * object){
		object->maxForce = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int FrictionJointDef::getMaxTorque(State & state, b2FrictionJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->maxTorque));
		return 1;
	}

	int FrictionJointDef::setMaxTorque(State & state, b2FrictionJointDef * object){
		object->maxTorque = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}
};
