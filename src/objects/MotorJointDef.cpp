#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Body.hpp"
#include "objects/JointDef.hpp"
#include "objects/MotorJointDef.hpp"

namespace LuaBox2D {
	void initMotorJointDef(State * state){
		state->registerInterface<MotorJointDef>("LuaBox2D_MotorJointDef");
	}

	b2MotorJointDef * MotorJointDef::constructor(State & state, bool & managed){
		JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
		b2JointDef * jointDef = interfaceJointDef->get(1);
		if (jointDef != nullptr){
			if (jointDef->type == b2JointType::e_motorJoint){
				managed = false;
				return reinterpret_cast<b2MotorJointDef*>(jointDef);
			}else{
				return new b2MotorJointDef();
			}
		}else{
			return new b2MotorJointDef();
		}
	}

	void MotorJointDef::destructor(State & state, b2MotorJointDef * object){
		delete object;
	}

	inline int MotorJointDef::getBodyA(State & state, b2MotorJointDef * object){
		return base->getBodyA(state, object);
	}

	inline int MotorJointDef::setBodyA(State & state, b2MotorJointDef * object){
		return base->setBodyA(state, object);
	}

	inline int MotorJointDef::getBodyB(State & state, b2MotorJointDef * object){
		return base->getBodyB(state, object);
	}

	inline int MotorJointDef::setBodyB(State & state, b2MotorJointDef * object){
		return base->setBodyB(state, object);
	}

	inline int MotorJointDef::getType(State & state, b2MotorJointDef * object){
		return base->getType(state, object);
	}

	inline int MotorJointDef::setType(State & state, b2MotorJointDef * object){
		return base->setType(state, object);
	}

	inline int MotorJointDef::getCollideConnected(State & state, b2MotorJointDef * object){
		return base->getCollideConnected(state, object);
	}

	inline int MotorJointDef::setCollideConnected(State & state, b2MotorJointDef * object){
		return base->setCollideConnected(state, object);
	}

	inline int MotorJointDef::getUserData(State & state, b2MotorJointDef * object){
		return base->getUserData(state, object);
	}

	inline int MotorJointDef::setUserData(State & state, b2MotorJointDef * object){
		return base->setUserData(state, object);
	}

	int MotorJointDef::initialize(State & state, b2MotorJointDef * object){
		Body * interfaceBody = state.getInterface<Body>("LuaBox2D_Body");

		if (state.stack->is<LUA_TUSERDATA>(1) && state.stack->is<LUA_TUSERDATA>(2)){
			b2Body * bodyA = interfaceBody->get(1);
			b2Body * bodyB = interfaceBody->get(2);

			if (bodyA != nullptr && bodyB != nullptr){
				object->Initialize(bodyA, bodyB);
			}
		}
		return 0;
	}

	int MotorJointDef::getLinearOffset(State & state, b2MotorJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->linearOffset, false);
		return 1;
	}

	int MotorJointDef::setLinearOffset(State & state, b2MotorJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * linearOffset = interfaceVec2->get(1);
		if (linearOffset != nullptr){
			object->linearOffset = *linearOffset;
		}
		return 0;
	}

	int MotorJointDef::getAngularOffset(State & state, b2MotorJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->angularOffset));
		return 1;
	}

	int MotorJointDef::setAngularOffset(State & state, b2MotorJointDef * object){
		object->angularOffset = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int MotorJointDef::getMaxForce(State & state, b2MotorJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->maxForce));
		return 1;
	}

	int MotorJointDef::setMaxForce(State & state, b2MotorJointDef * object){
		object->maxForce = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int MotorJointDef::getMaxTorque(State & state, b2MotorJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->maxTorque));
		return 1;
	}

	int MotorJointDef::setMaxTorque(State & state, b2MotorJointDef * object){
		object->maxTorque = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int MotorJointDef::getCorrectionFactor(State & state, b2MotorJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->correctionFactor));
		return 1;
	}

	int MotorJointDef::setCorrectionFactor(State & state, b2MotorJointDef * object){
		object->correctionFactor = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}
};
