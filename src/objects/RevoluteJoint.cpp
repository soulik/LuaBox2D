#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Joint.hpp"
#include "objects/RevoluteJoint.hpp"

namespace LuaBox2D {
	void initRevoluteJoint(State * state){
		state->registerInterface<RevoluteJoint>("LuaBox2D_RevoluteJoint");
	}

	b2RevoluteJoint * RevoluteJoint::constructor(State & state, bool & managed){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		b2Joint * joint = interfaceJoint->get(1);
		if (joint != nullptr){
			if (joint->GetType() == b2JointType::e_revoluteJoint){
				managed = false;
				return dynamic_cast<b2RevoluteJoint*>(joint);
			}else{
				return nullptr;
			}
		}else{
			return nullptr;
		}
	}

	void RevoluteJoint::destructor(State & state, b2RevoluteJoint * object){
		base->destructor(state, object);
	}

	inline int RevoluteJoint::getType(State & state, b2RevoluteJoint * object){
		return base->getType(state, object);
	}

	inline int RevoluteJoint::getBodyA(State & state, b2RevoluteJoint * object){
		return base->getBodyA(state, object);
	}

	inline int RevoluteJoint::getBodyB(State & state, b2RevoluteJoint * object){
		return base->getBodyB(state, object);
	}

	inline int RevoluteJoint::getUserData(State & state, b2RevoluteJoint * object){
		return base->getUserData(state, object);
	}

	inline int RevoluteJoint::setUserData(State & state, b2RevoluteJoint * object){
		return base->setUserData(state, object);
	}

	int RevoluteJoint::getAnchorA(State & state, b2RevoluteJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetAnchorA()), true);
		return 1;
	}

	int RevoluteJoint::getAnchorB(State & state, b2RevoluteJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetAnchorB()), true);
		return 1;
	}

	int RevoluteJoint::getReactionForce(State & state, b2RevoluteJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		if (state.stack->is<LUA_TNUMBER>(1)){
			interfaceVec2->push(new b2Vec2(object->GetReactionForce(
				static_cast<float32>(state.stack->to<LUA_NUMBER>(1))
				)), true);
			return 1;
		}else{
			return 0;
		}
	}

	int RevoluteJoint::getReactionTorque(State & state, b2RevoluteJoint * object){
		if (state.stack->is<LUA_TNUMBER>(1)){
			state.stack->push<LUA_NUMBER>(
				static_cast<LUA_NUMBER>(
				object->GetReactionTorque(
				static_cast<float32>(state.stack->to<LUA_NUMBER>(1))
				)
				)
				);
			return 1;
		}else{
			return 0;
		}
	}

	int RevoluteJoint::getMotorTorque(State & state, b2RevoluteJoint * object){
		if (state.stack->is<LUA_TNUMBER>(1)){
			state.stack->push<LUA_NUMBER>(
				static_cast<LUA_NUMBER>(
				object->GetMotorTorque(
				static_cast<float32>(state.stack->to<LUA_NUMBER>(1))
				)
				)
				);
			return 1;
		}else{
			return 0;
		}
	}

	inline int RevoluteJoint::getActive(State & state, b2RevoluteJoint * object){
		return base->getActive(state, object);
	}

	inline int RevoluteJoint::getCollideConnected(State & state, b2RevoluteJoint * object){
		return base->getCollideConnected(state, object);
	}

	int RevoluteJoint::getLocalAnchorA(State & state, b2RevoluteJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetLocalAnchorA()), true);
		return 1;
	}

	int RevoluteJoint::getLocalAnchorB(State & state, b2RevoluteJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetLocalAnchorB()), true);
		return 1;
	}

	int RevoluteJoint::getReferenceAngle(State & state, b2RevoluteJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetReferenceAngle()));
		return 1;
	}

	int RevoluteJoint::getEnableLimit(State & state, b2RevoluteJoint * object){
		state.stack->push<bool>(object->IsLimitEnabled());
		return 1;
	}

	int RevoluteJoint::setEnableLimit(State & state, b2RevoluteJoint * object){
		object->EnableLimit(state.stack->to<bool>(1));
		return 0;
	}

	int RevoluteJoint::getLowerLimit(State & state, b2RevoluteJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetLowerLimit()));
		return 1;
	}

	int RevoluteJoint::getUpperLimit(State & state, b2RevoluteJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetUpperLimit()));
		return 1;
	}

	int RevoluteJoint::setLimits(State & state, b2RevoluteJoint * object){
		if (state.stack->is<LUA_TNUMBER>(1) && state.stack->is<LUA_TNUMBER>(2)){
			object->SetLimits(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)), static_cast<float32>(state.stack->to<LUA_NUMBER>(2)));
		}
		return 0;
	}

	int RevoluteJoint::getEnableMotor(State & state, b2RevoluteJoint * object){
		state.stack->push<bool>(object->IsMotorEnabled());
		return 1;
	}

	int RevoluteJoint::setEnableMotor(State & state, b2RevoluteJoint * object){
		object->EnableMotor(state.stack->to<bool>(1));
		return 0;
	}

	int RevoluteJoint::getMotorSpeed(State & state, b2RevoluteJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetMotorSpeed()));
		return 1;
	}

	int RevoluteJoint::setMotorSpeed(State & state, b2RevoluteJoint * object){
		object->SetMotorSpeed(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int RevoluteJoint::getMaxMotorTorque(State & state, b2RevoluteJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetMaxMotorTorque()));
		return 1;
	}

	int RevoluteJoint::setMaxMotorTorque(State & state, b2RevoluteJoint * object){
		object->SetMaxMotorTorque(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}
};
