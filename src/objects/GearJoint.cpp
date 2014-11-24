#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Joint.hpp"
#include "objects/GearJoint.hpp"

namespace LuaBox2D {
	void initGearJoint(State * state){
		state->registerInterface<GearJoint>("LuaBox2D_GearJoint");
	}

	b2GearJoint * GearJoint::constructor(State & state, bool & managed){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		b2Joint * joint = interfaceJoint->get(1);
		if (joint != nullptr){
			if (joint->GetType() == b2JointType::e_gearJoint){
				managed = false;
				return dynamic_cast<b2GearJoint*>(joint);
			}else{
				return nullptr;
			}
		}else{
			return nullptr;
		}
	}

	void GearJoint::destructor(State & state, b2GearJoint * object){
		base->destructor(state, object);
	}

	inline int GearJoint::getType(State & state, b2GearJoint * object){
		return base->getType(state, object);
	}

	inline int GearJoint::getBodyA(State & state, b2GearJoint * object){
		return base->getBodyA(state, object);
	}

	inline int GearJoint::getBodyB(State & state, b2GearJoint * object){
		return base->getBodyB(state, object);
	}

	inline int GearJoint::getUserData(State & state, b2GearJoint * object){
		return base->getUserData(state, object);
	}

	inline int GearJoint::setUserData(State & state, b2GearJoint * object){
		return base->setUserData(state, object);
	}

	int GearJoint::getReactionForce(State & state, b2GearJoint * object){
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

	int GearJoint::getReactionTorque(State & state, b2GearJoint * object){
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

	inline int GearJoint::getActive(State & state, b2GearJoint * object){
		return base->getActive(state, object);
	}

	inline int GearJoint::getCollideConnected(State & state, b2GearJoint * object){
		return base->getCollideConnected(state, object);
	}

	int GearJoint::getAnchorA(State & state, b2GearJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetAnchorA()), true);
		return 1;
	}

	int GearJoint::getAnchorB(State & state, b2GearJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetAnchorB()), true);
		return 1;
	}

	int GearJoint::getJoint1(State & state, b2GearJoint * object){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		interfaceJoint->push(object->GetJoint1(), false);
		return 1;
	}

	int GearJoint::getJoint2(State & state, b2GearJoint * object){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		interfaceJoint->push(object->GetJoint2(), false);
		return 1;
	}

	int GearJoint::getRatio(State & state, b2GearJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetRatio()));
		return 1;
	}

	int GearJoint::setRatio(State & state, b2GearJoint * object){
		object->SetRatio(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}
};
