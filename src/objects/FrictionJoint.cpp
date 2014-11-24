#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Joint.hpp"
#include "objects/FrictionJoint.hpp"

namespace LuaBox2D {
	void initFrictionJoint(State * state){
		state->registerInterface<FrictionJoint>("LuaBox2D_FrictionJoint");
	}

	b2FrictionJoint * FrictionJoint::constructor(State & state, bool & managed){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		b2Joint * joint = interfaceJoint->get(1);
		if (joint != nullptr){
			if (joint->GetType() == b2JointType::e_frictionJoint){
				managed = false;
				return dynamic_cast<b2FrictionJoint*>(joint);
			}else{
				return nullptr;
			}
		}else{
			return nullptr;
		}
	}

	void FrictionJoint::destructor(State & state, b2FrictionJoint * object){
		base->destructor(state, object);
	}

	inline int FrictionJoint::getType(State & state, b2FrictionJoint * object){
		return base->getType(state, object);
	}

	inline int FrictionJoint::getBodyA(State & state, b2FrictionJoint * object){
		return base->getBodyA(state, object);
	}

	inline int FrictionJoint::getBodyB(State & state, b2FrictionJoint * object){
		return base->getBodyB(state, object);
	}

	inline int FrictionJoint::getUserData(State & state, b2FrictionJoint * object){
		return base->getUserData(state, object);
	}

	inline int FrictionJoint::setUserData(State & state, b2FrictionJoint * object){
		return base->setUserData(state, object);
	}

	int FrictionJoint::getReactionForce(State & state, b2FrictionJoint * object){
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

	int FrictionJoint::getReactionTorque(State & state, b2FrictionJoint * object){
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

	inline int FrictionJoint::getActive(State & state, b2FrictionJoint * object){
		return base->getActive(state, object);
	}

	inline int FrictionJoint::getCollideConnected(State & state, b2FrictionJoint * object){
		return base->getCollideConnected(state, object);
	}

	int FrictionJoint::getAnchorA(State & state, b2FrictionJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetAnchorA()), true);
		return 1;
	}

	int FrictionJoint::getAnchorB(State & state, b2FrictionJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetAnchorB()), true);
		return 1;
	}

	int FrictionJoint::getLocalAnchorA(State & state, b2FrictionJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetLocalAnchorA()), true);
		return 1;
	}

	int FrictionJoint::getLocalAnchorB(State & state, b2FrictionJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetLocalAnchorB()), true);
		return 1;
	}

	int FrictionJoint::getMaxForce(State & state, b2FrictionJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetMaxForce()));
		return 1;
	}

	int FrictionJoint::setMaxForce(State & state, b2FrictionJoint * object){
		object->SetMaxForce(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int FrictionJoint::getMaxTorque(State & state, b2FrictionJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetMaxTorque()));
		return 1;
	}

	int FrictionJoint::setMaxTorque(State & state, b2FrictionJoint * object){
		object->SetMaxTorque(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

};
