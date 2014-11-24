#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Joint.hpp"
#include "objects/MotorJoint.hpp"

namespace LuaBox2D {
	void initMotorJoint(State * state){
		state->registerInterface<MotorJoint>("LuaBox2D_MotorJoint");
	}

	b2MotorJoint * MotorJoint::constructor(State & state, bool & managed){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		b2Joint * joint = interfaceJoint->get(1);
		if (joint != nullptr){
			if (joint->GetType() == b2JointType::e_motorJoint){
				managed = false;
				return dynamic_cast<b2MotorJoint*>(joint);
			}else{
				return nullptr;
			}
		}else{
			return nullptr;
		}
	}

	void MotorJoint::destructor(State & state, b2MotorJoint * object){
		base->destructor(state, object);
	}

	inline int MotorJoint::getType(State & state, b2MotorJoint * object){
		return base->getType(state, object);
	}

	inline int MotorJoint::getBodyA(State & state, b2MotorJoint * object){
		return base->getBodyA(state, object);
	}

	inline int MotorJoint::getBodyB(State & state, b2MotorJoint * object){
		return base->getBodyB(state, object);
	}

	inline int MotorJoint::getUserData(State & state, b2MotorJoint * object){
		return base->getUserData(state, object);
	}

	inline int MotorJoint::setUserData(State & state, b2MotorJoint * object){
		return base->setUserData(state, object);
	}

	int MotorJoint::getAnchorA(State & state, b2MotorJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetAnchorA()), true);
		return 1;
	}

	int MotorJoint::getAnchorB(State & state, b2MotorJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetAnchorB()), true);
		return 1;
	}

	int MotorJoint::getReactionForce(State & state, b2MotorJoint * object){
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

	int MotorJoint::getReactionTorque(State & state, b2MotorJoint * object){
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

	inline int MotorJoint::getActive(State & state, b2MotorJoint * object){
		return base->getActive(state, object);
	}

	inline int MotorJoint::getCollideConnected(State & state, b2MotorJoint * object){
		return base->getCollideConnected(state, object);
	}

	int MotorJoint::getLinearOffset(State & state, b2MotorJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetLinearOffset()), true);
		return 1;
	}

	int MotorJoint::setLinearOffset(State & state, b2MotorJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * linearOffset = interfaceVec2->get(1);
		if (linearOffset != nullptr){
			object->SetLinearOffset(*linearOffset);
		}
		return 0;
	}

	int MotorJoint::getAngularOffset(State & state, b2MotorJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetAngularOffset()));
		return 1;
	}

	int MotorJoint::setAngularOffset(State & state, b2MotorJoint * object){
		object->SetAngularOffset(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int MotorJoint::getMaxForce(State & state, b2MotorJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetMaxForce()));
		return 1;
	}

	int MotorJoint::setMaxForce(State & state, b2MotorJoint * object){
		object->SetMaxForce(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int MotorJoint::getMaxTorque(State & state, b2MotorJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetMaxTorque()));
		return 1;
	}

	int MotorJoint::setMaxTorque(State & state, b2MotorJoint * object){
		object->SetMaxTorque(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int MotorJoint::getCorrectionFactor(State & state, b2MotorJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetCorrectionFactor()));
		return 1;
	}

	int MotorJoint::setCorrectionFactor(State & state, b2MotorJoint * object){
		object->SetCorrectionFactor(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}
};
