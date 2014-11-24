#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Joint.hpp"
#include "objects/PrismaticJoint.hpp"

namespace LuaBox2D {
	void initPrismaticJoint(State * state){
		state->registerInterface<PrismaticJoint>("LuaBox2D_PrismaticJoint");
	}

	b2PrismaticJoint * PrismaticJoint::constructor(State & state, bool & managed){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		b2Joint * joint = interfaceJoint->get(1);
		if (joint != nullptr){
			if (joint->GetType() == b2JointType::e_prismaticJoint){
				managed = false;
				return dynamic_cast<b2PrismaticJoint*>(joint);
			}else{
				return nullptr;
			}
		}else{
			return nullptr;
		}
	}

	void PrismaticJoint::destructor(State & state, b2PrismaticJoint * object){
		base->destructor(state, object);
	}

	inline int PrismaticJoint::getType(State & state, b2PrismaticJoint * object){
		return base->getType(state, object);
	}

	inline int PrismaticJoint::getBodyA(State & state, b2PrismaticJoint * object){
		return base->getBodyA(state, object);
	}

	inline int PrismaticJoint::getBodyB(State & state, b2PrismaticJoint * object){
		return base->getBodyB(state, object);
	}

	inline int PrismaticJoint::getUserData(State & state, b2PrismaticJoint * object){
		return base->getUserData(state, object);
	}

	inline int PrismaticJoint::setUserData(State & state, b2PrismaticJoint * object){
		return base->setUserData(state, object);
	}

	int PrismaticJoint::getAnchorA(State & state, b2PrismaticJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetAnchorA()), true);
		return 1;
	}

	int PrismaticJoint::getAnchorB(State & state, b2PrismaticJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetAnchorB()), true);
		return 1;
	}

	int PrismaticJoint::getReactionForce(State & state, b2PrismaticJoint * object){
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

	int PrismaticJoint::getReactionTorque(State & state, b2PrismaticJoint * object){
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

	inline int PrismaticJoint::getActive(State & state, b2PrismaticJoint * object){
		return base->getActive(state, object);
	}

	inline int PrismaticJoint::getCollideConnected(State & state, b2PrismaticJoint * object){
		return base->getCollideConnected(state, object);
	}

	int PrismaticJoint::getLocalAnchorA(State & state, b2PrismaticJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetLocalAnchorA()), true);
		return 1;
	}

	int PrismaticJoint::getLocalAnchorB(State & state, b2PrismaticJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetLocalAnchorB()), true);
		return 1;
	}

	int PrismaticJoint::getLocalAxisA(State & state, b2PrismaticJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetLocalAxisA()), true);
		return 1;
	}

	int PrismaticJoint::getReferenceAngle(State & state, b2PrismaticJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetReferenceAngle()));
		return 1;
	}

	int PrismaticJoint::getEnableLimit(State & state, b2PrismaticJoint * object){
		state.stack->push<bool>(object->IsLimitEnabled());
		return 1;
	}

	int PrismaticJoint::setEnableLimit(State & state, b2PrismaticJoint * object){
		object->EnableLimit(state.stack->to<bool>(1));
		return 0;
	}

	int PrismaticJoint::getLowerLimit(State & state, b2PrismaticJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetLowerLimit()));
		return 1;
	}

	int PrismaticJoint::getUpperLimit(State & state, b2PrismaticJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetUpperLimit()));
		return 1;
	}

	int PrismaticJoint::setLimits(State & state, b2PrismaticJoint * object){
		if (state.stack->is<LUA_TNUMBER>(1) && state.stack->is<LUA_TNUMBER>(2)){
			object->SetLimits(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)), static_cast<float32>(state.stack->to<LUA_NUMBER>(2)));
		}
		return 0;
	}

	int PrismaticJoint::getEnableMotor(State & state, b2PrismaticJoint * object){
		state.stack->push<bool>(object->IsMotorEnabled());
		return 1;
	}

	int PrismaticJoint::setEnableMotor(State & state, b2PrismaticJoint * object){
		object->EnableMotor(state.stack->to<bool>(1));
		return 0;
	}

	int PrismaticJoint::getMotorSpeed(State & state, b2PrismaticJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetMotorSpeed()));
		return 1;
	}

	int PrismaticJoint::setMotorSpeed(State & state, b2PrismaticJoint * object){
		object->SetMotorSpeed(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int PrismaticJoint::getMaxMotorForce(State & state, b2PrismaticJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetMaxMotorForce()));
		return 1;
	}

	int PrismaticJoint::setMaxMotorForce(State & state, b2PrismaticJoint * object){
		object->SetMaxMotorForce(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}
};
