#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Body.hpp"
#include "objects/JointDef.hpp"
#include "objects/WheelJointDef.hpp"

namespace LuaBox2D {
	void initWheelJointDef(State * state){
		state->registerInterface<WheelJointDef>("LuaBox2D_WheelJointDef");
	}

	b2WheelJointDef * WheelJointDef::constructor(State & state, bool & managed){
		JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
		b2JointDef * jointDef = interfaceJointDef->get(1);
		if (jointDef != nullptr){
			if (jointDef->type == b2JointType::e_wheelJoint){
				managed = false;
				return reinterpret_cast<b2WheelJointDef*>(jointDef);
			}else{
				return new b2WheelJointDef();
			}
		}else{
			return new b2WheelJointDef();
		}
	}

	void WheelJointDef::destructor(State & state, b2WheelJointDef * object){
		delete object;
	}

	inline int WheelJointDef::getBodyA(State & state, b2WheelJointDef * object){
		return base->getBodyA(state, object);
	}

	inline int WheelJointDef::setBodyA(State & state, b2WheelJointDef * object){
		return base->setBodyA(state, object);
	}

	inline int WheelJointDef::getBodyB(State & state, b2WheelJointDef * object){
		return base->getBodyB(state, object);
	}

	inline int WheelJointDef::setBodyB(State & state, b2WheelJointDef * object){
		return base->setBodyB(state, object);
	}

	inline int WheelJointDef::getType(State & state, b2WheelJointDef * object){
		return base->getType(state, object);
	}

	inline int WheelJointDef::setType(State & state, b2WheelJointDef * object){
		return base->setType(state, object);
	}

	inline int WheelJointDef::getCollideConnected(State & state, b2WheelJointDef * object){
		return base->getCollideConnected(state, object);
	}

	inline int WheelJointDef::setCollideConnected(State & state, b2WheelJointDef * object){
		return base->setCollideConnected(state, object);
	}

	inline int WheelJointDef::getUserData(State & state, b2WheelJointDef * object){
		return base->getUserData(state, object);
	}

	inline int WheelJointDef::setUserData(State & state, b2WheelJointDef * object){
		return base->setUserData(state, object);
	}

	int WheelJointDef::initialize(State & state, b2WheelJointDef * object){
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

	int WheelJointDef::getLocalAnchorA(State & state, b2WheelJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->localAnchorA, false);
		return 1;
	}

	int WheelJointDef::setLocalAnchorA(State & state, b2WheelJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * anchor = interfaceVec2->get(1);
		if (anchor != nullptr){
			object->localAnchorA = *anchor;
		}
		return 0;
	}

	int WheelJointDef::getLocalAnchorB(State & state, b2WheelJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->localAnchorB, false);
		return 1;
	}

	int WheelJointDef::setLocalAnchorB(State & state, b2WheelJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * anchor = interfaceVec2->get(1);
		if (anchor != nullptr){
			object->localAnchorB = *anchor;
		}
		return 0;
	}

	int WheelJointDef::getLocalAxisA(State & state, b2WheelJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->localAxisA, false);
		return 1;
	}

	int WheelJointDef::setLocalAxisA(State & state, b2WheelJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * axis = interfaceVec2->get(1);
		if (axis != nullptr){
			object->localAxisA = *axis;
		}
		return 0;
	}

	int WheelJointDef::getEnableMotor(State & state, b2WheelJointDef * object){
		state.stack->push<bool>(object->enableMotor);
		return 1;
	}

	int WheelJointDef::setEnableMotor(State & state, b2WheelJointDef * object){
		object->enableMotor = state.stack->to<bool>(1);
		return 0;
	}

	int WheelJointDef::getMotorSpeed(State & state, b2WheelJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->motorSpeed));
		return 1;
	}

	int WheelJointDef::setMotorSpeed(State & state, b2WheelJointDef * object){
		object->motorSpeed = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int WheelJointDef::getMaxMotorTorque(State & state, b2WheelJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->maxMotorTorque));
		return 1;
	}

	int WheelJointDef::setMaxMotorTorque(State & state, b2WheelJointDef * object){
		object->maxMotorTorque = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int WheelJointDef::getFrequencyHz(State & state, b2WheelJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->frequencyHz));
		return 1;
	}

	int WheelJointDef::setFrequencyHz(State & state, b2WheelJointDef * object){
		object->frequencyHz = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int WheelJointDef::getDampingRatio(State & state, b2WheelJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->dampingRatio));
		return 1;
	}

	int WheelJointDef::setDampingRatio(State & state, b2WheelJointDef * object){
		object->dampingRatio = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}
};
