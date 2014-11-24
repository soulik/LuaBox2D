#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Joint.hpp"
#include "objects/WheelJoint.hpp"

namespace LuaBox2D {
	void initWheelJoint(State * state){
		state->registerInterface<WheelJoint>("LuaBox2D_WheelJoint");
	}

	b2WheelJoint * WheelJoint::constructor(State & state, bool & managed){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		b2Joint * joint = interfaceJoint->get(1);
		if (joint != nullptr){
			if (joint->GetType() == b2JointType::e_wheelJoint){
				managed = false;
				return dynamic_cast<b2WheelJoint*>(joint);
			}else{
				return nullptr;
			}
		}else{
			return nullptr;
		}
	}

	void WheelJoint::destructor(State & state, b2WheelJoint * object){
		base->destructor(state, object);
	}

	inline int WheelJoint::getType(State & state, b2WheelJoint * object){
		return base->getType(state, object);
	}

	inline int WheelJoint::getBodyA(State & state, b2WheelJoint * object){
		return base->getBodyA(state, object);
	}

	inline int WheelJoint::getBodyB(State & state, b2WheelJoint * object){
		return base->getBodyB(state, object);
	}

	int WheelJoint::getAnchorA(State & state, b2WheelJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetAnchorA()), true);
		return 1;
	}

	inline int WheelJoint::getUserData(State & state, b2WheelJoint * object){
		return base->getUserData(state, object);
	}

	inline int WheelJoint::setUserData(State & state, b2WheelJoint * object){
		return base->setUserData(state, object);
	}

	int WheelJoint::getAnchorB(State & state, b2WheelJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetAnchorB()), true);
		return 1;
	}

	int WheelJoint::getReactionForce(State & state, b2WheelJoint * object){
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

	int WheelJoint::getReactionTorque(State & state, b2WheelJoint * object){
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

	int WheelJoint::getMotorTorque(State & state, b2WheelJoint * object){
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

	inline int WheelJoint::getActive(State & state, b2WheelJoint * object){
		return base->getActive(state, object);
	}

	inline int WheelJoint::getCollideConnected(State & state, b2WheelJoint * object){
		return base->getCollideConnected(state, object);
	}

	int WheelJoint::getLocalAnchorA(State & state, b2WheelJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetLocalAnchorA()), true);
		return 1;
	}

	int WheelJoint::getLocalAnchorB(State & state, b2WheelJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetLocalAnchorB()), true);
		return 1;
	}

	int WheelJoint::getLocalAxisA(State & state, b2WheelJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetLocalAxisA()), true);
		return 1;
	}

	int WheelJoint::getEnableMotor(State & state, b2WheelJoint * object){
		state.stack->push<bool>(object->IsMotorEnabled());
		return 1;
	}

	int WheelJoint::setEnableMotor(State & state, b2WheelJoint * object){
		object->EnableMotor(state.stack->to<bool>(1));
		return 0;
	}

	int WheelJoint::getMotorSpeed(State & state, b2WheelJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetMotorSpeed()));
		return 1;
	}

	int WheelJoint::setMotorSpeed(State & state, b2WheelJoint * object){
		object->SetMotorSpeed(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int WheelJoint::getMaxMotorTorque(State & state, b2WheelJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetMaxMotorTorque()));
		return 1;
	}

	int WheelJoint::setMaxMotorTorque(State & state, b2WheelJoint * object){
		object->SetMaxMotorTorque(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int WheelJoint::getSpringFrequencyHz(State & state, b2WheelJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetSpringFrequencyHz()));
		return 1;
	}

	int WheelJoint::setSpringFrequencyHz(State & state, b2WheelJoint * object){
		object->SetSpringFrequencyHz(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int WheelJoint::getSpringDampingRatio(State & state, b2WheelJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetSpringDampingRatio()));
		return 1;
	}

	int WheelJoint::setSpringDampingRatio(State & state, b2WheelJoint * object){
		object->SetSpringDampingRatio(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int WheelJoint::getJointTranslation(State & state, b2WheelJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetJointTranslation()));
		return 1;
	}

	int WheelJoint::getJointSpeed(State & state, b2WheelJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetJointSpeed()));
		return 1;
	}
};
