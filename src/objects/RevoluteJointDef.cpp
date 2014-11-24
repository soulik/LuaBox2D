#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Body.hpp"
#include "objects/JointDef.hpp"
#include "objects/RevoluteJointDef.hpp"

namespace LuaBox2D {
	void initRevoluteJointDef(State * state){
		state->registerInterface<RevoluteJointDef>("LuaBox2D_RevoluteJointDef");
	}

	b2RevoluteJointDef * RevoluteJointDef::constructor(State & state, bool & managed){
		JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
		b2JointDef * jointDef = interfaceJointDef->get(1);
		if (jointDef != nullptr){
			if (jointDef->type == b2JointType::e_revoluteJoint){
				managed = false;
				return reinterpret_cast<b2RevoluteJointDef*>(jointDef);
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

	inline int RevoluteJointDef::getUserData(State & state, b2RevoluteJointDef * object){
		return base->getUserData(state, object);
	}

	inline int RevoluteJointDef::setUserData(State & state, b2RevoluteJointDef * object){
		return base->setUserData(state, object);
	}

	int RevoluteJointDef::initialize(State & state, b2RevoluteJointDef * object){
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

	int RevoluteJointDef::getLocalAnchorA(State & state, b2RevoluteJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->localAnchorA, false);
		return 1;
	}

	int RevoluteJointDef::setLocalAnchorA(State & state, b2RevoluteJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * anchor = interfaceVec2->get(1);
		if (anchor != nullptr){
			object->localAnchorA = *anchor;
		}
		return 0;
	}

	int RevoluteJointDef::getLocalAnchorB(State & state, b2RevoluteJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->localAnchorB, false);
		return 1;
	}

	int RevoluteJointDef::setLocalAnchorB(State & state, b2RevoluteJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * anchor = interfaceVec2->get(1);
		if (anchor != nullptr){
			object->localAnchorB = *anchor;
		}
		return 0;
	}

	int RevoluteJointDef::getReferenceAngle(State & state, b2RevoluteJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->referenceAngle));
		return 1;
	}

	int RevoluteJointDef::setReferenceAngle(State & state, b2RevoluteJointDef * object){
		object->referenceAngle = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int RevoluteJointDef::getEnableLimit(State & state, b2RevoluteJointDef * object){
		state.stack->push<bool>(object->enableLimit);
		return 1;
	}

	int RevoluteJointDef::setEnableLimit(State & state, b2RevoluteJointDef * object){
		object->enableLimit = state.stack->to<bool>(1);
		return 0;
	}

	int RevoluteJointDef::getLowerAngle(State & state, b2RevoluteJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->lowerAngle));
		return 1;
	}

	int RevoluteJointDef::setLowerAngle(State & state, b2RevoluteJointDef * object){
		object->lowerAngle = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int RevoluteJointDef::getUpperAngle(State & state, b2RevoluteJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->upperAngle));
		return 1;
	}

	int RevoluteJointDef::setUpperAngle(State & state, b2RevoluteJointDef * object){
		object->upperAngle = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int RevoluteJointDef::getEnableMotor(State & state, b2RevoluteJointDef * object){
		state.stack->push<bool>(object->enableMotor);
		return 1;
	}

	int RevoluteJointDef::setEnableMotor(State & state, b2RevoluteJointDef * object){
		object->enableMotor = state.stack->to<bool>(1);
		return 0;
	}

	int RevoluteJointDef::getMotorSpeed(State & state, b2RevoluteJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->motorSpeed));
		return 1;
	}

	int RevoluteJointDef::setMotorSpeed(State & state, b2RevoluteJointDef * object){
		object->motorSpeed = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int RevoluteJointDef::getMaxMotorTorque(State & state, b2RevoluteJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->maxMotorTorque));
		return 1;
	}

	int RevoluteJointDef::setMaxMotorTorque(State & state, b2RevoluteJointDef * object){
		object->maxMotorTorque = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

};
