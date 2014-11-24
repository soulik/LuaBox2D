#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Body.hpp"
#include "objects/JointDef.hpp"
#include "objects/PrismaticJointDef.hpp"

namespace LuaBox2D {
	void initPrismaticJointDef(State * state){
		state->registerInterface<PrismaticJointDef>("LuaBox2D_PrismaticJointDef");
	}

	b2PrismaticJointDef * PrismaticJointDef::constructor(State & state, bool & managed){
		JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
		b2JointDef * jointDef = interfaceJointDef->get(1);
		if (jointDef != nullptr){
			if (jointDef->type == b2JointType::e_prismaticJoint){
				managed = false;
				return reinterpret_cast<b2PrismaticJointDef*>(jointDef);
			}else{
				return new b2PrismaticJointDef();
			}
		}else{
			return new b2PrismaticJointDef();
		}
	}

	void PrismaticJointDef::destructor(State & state, b2PrismaticJointDef * object){
		delete object;
	}

	inline int PrismaticJointDef::getBodyA(State & state, b2PrismaticJointDef * object){
		return base->getBodyA(state, object);
	}

	inline int PrismaticJointDef::setBodyA(State & state, b2PrismaticJointDef * object){
		return base->setBodyA(state, object);
	}

	inline int PrismaticJointDef::getBodyB(State & state, b2PrismaticJointDef * object){
		return base->getBodyB(state, object);
	}

	inline int PrismaticJointDef::setBodyB(State & state, b2PrismaticJointDef * object){
		return base->setBodyB(state, object);
	}

	inline int PrismaticJointDef::getType(State & state, b2PrismaticJointDef * object){
		return base->getType(state, object);
	}

	inline int PrismaticJointDef::setType(State & state, b2PrismaticJointDef * object){
		return base->setType(state, object);
	}

	inline int PrismaticJointDef::getCollideConnected(State & state, b2PrismaticJointDef * object){
		return base->getCollideConnected(state, object);
	}

	inline int PrismaticJointDef::setCollideConnected(State & state, b2PrismaticJointDef * object){
		return base->setCollideConnected(state, object);
	}

	inline int PrismaticJointDef::getUserData(State & state, b2PrismaticJointDef * object){
		return base->getUserData(state, object);
	}

	inline int PrismaticJointDef::setUserData(State & state, b2PrismaticJointDef * object){
		return base->setUserData(state, object);
	}

	int PrismaticJointDef::initialize(State & state, b2PrismaticJointDef * object){
		Body * interfaceBody = state.getInterface<Body>("LuaBox2D_Body");
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");

		if (state.stack->is<LUA_TUSERDATA>(1) && state.stack->is<LUA_TUSERDATA>(2) && state.stack->is<LUA_TUSERDATA>(3) && state.stack->is<LUA_TUSERDATA>(4)){
			b2Body * bodyA = interfaceBody->get(1);
			b2Body * bodyB = interfaceBody->get(2);
			b2Vec2 * anchor = interfaceVec2->get(3);
			b2Vec2 * axis = interfaceVec2->get(4);

			if (bodyA != nullptr && bodyB != nullptr && anchor != nullptr && axis != nullptr){
				object->Initialize(bodyA, bodyB, *anchor, *axis);
			}
		}
		return 0;
	}

	int PrismaticJointDef::getLocalAnchorA(State & state, b2PrismaticJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->localAnchorA, false);
		return 1;
	}

	int PrismaticJointDef::setLocalAnchorA(State & state, b2PrismaticJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * anchor = interfaceVec2->get(1);
		if (anchor != nullptr){
			object->localAnchorA = *anchor;
		}
		return 0;
	}

	int PrismaticJointDef::getLocalAnchorB(State & state, b2PrismaticJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->localAnchorB, false);
		return 1;
	}

	int PrismaticJointDef::setLocalAnchorB(State & state, b2PrismaticJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * anchor = interfaceVec2->get(1);
		if (anchor != nullptr){
			object->localAnchorB = *anchor;
		}
		return 0;
	}

	int PrismaticJointDef::getLocalAxisA(State & state, b2PrismaticJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->localAxisA, false);
		return 1;
	}

	int PrismaticJointDef::setLocalAxisA(State & state, b2PrismaticJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * axisA = interfaceVec2->get(1);
		if (axisA != nullptr){
			object->localAxisA = *axisA;
		}
		return 0;
	}

	int PrismaticJointDef::getReferenceAngle(State & state, b2PrismaticJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->referenceAngle));
		return 1;
	}

	int PrismaticJointDef::setReferenceAngle(State & state, b2PrismaticJointDef * object){
		object->referenceAngle = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int PrismaticJointDef::getEnableLimit(State & state, b2PrismaticJointDef * object){
		state.stack->push<bool>(object->enableLimit);
		return 1;
	}

	int PrismaticJointDef::setEnableLimit(State & state, b2PrismaticJointDef * object){
		object->enableLimit = state.stack->to<bool>(1);
		return 0;
	}

	int PrismaticJointDef::getLowerTranslation(State & state, b2PrismaticJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->lowerTranslation));
		return 1;
	}

	int PrismaticJointDef::setLowerTranslation(State & state, b2PrismaticJointDef * object){
		object->lowerTranslation = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int PrismaticJointDef::getUpperTranslation(State & state, b2PrismaticJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->upperTranslation));
		return 1;
	}

	int PrismaticJointDef::setUpperTranslation(State & state, b2PrismaticJointDef * object){
		object->upperTranslation = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int PrismaticJointDef::getEnableMotor(State & state, b2PrismaticJointDef * object){
		state.stack->push<bool>(object->enableMotor);
		return 1;
	}

	int PrismaticJointDef::setEnableMotor(State & state, b2PrismaticJointDef * object){
		object->enableMotor = state.stack->to<bool>(1);
		return 0;
	}

	int PrismaticJointDef::getMotorSpeed(State & state, b2PrismaticJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->motorSpeed));
		return 1;
	}

	int PrismaticJointDef::setMotorSpeed(State & state, b2PrismaticJointDef * object){
		object->motorSpeed = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int PrismaticJointDef::getMaxMotorForce(State & state, b2PrismaticJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->maxMotorForce));
		return 1;
	}

	int PrismaticJointDef::setMaxMotorForce(State & state, b2PrismaticJointDef * object){
		object->maxMotorForce = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

};
