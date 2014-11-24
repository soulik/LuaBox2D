#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Joint.hpp"
#include "objects/RopeJoint.hpp"

namespace LuaBox2D {
	void initRopeJoint(State * state){
		state->registerInterface<RopeJoint>("LuaBox2D_RopeJoint");
	}

	b2RopeJoint * RopeJoint::constructor(State & state, bool & managed){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		b2Joint * joint = interfaceJoint->get(1);
		if (joint != nullptr){
			if (joint->GetType() == b2JointType::e_ropeJoint){
				managed = false;
				return dynamic_cast<b2RopeJoint*>(joint);
			}else{
				return nullptr;
			}
		}else{
			return nullptr;
		}
	}

	void RopeJoint::destructor(State & state, b2RopeJoint * object){
		base->destructor(state, object);
	}

	inline int RopeJoint::getType(State & state, b2RopeJoint * object){
		return base->getType(state, object);
	}

	inline int RopeJoint::getBodyA(State & state, b2RopeJoint * object){
		return base->getBodyA(state, object);
	}

	inline int RopeJoint::getBodyB(State & state, b2RopeJoint * object){
		return base->getBodyB(state, object);
	}

	inline int RopeJoint::getUserData(State & state, b2RopeJoint * object){
		return base->getUserData(state, object);
	}

	inline int RopeJoint::setUserData(State & state, b2RopeJoint * object){
		return base->setUserData(state, object);
	}

	int RopeJoint::getAnchorA(State & state, b2RopeJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetAnchorA()), true);
		return 1;
	}

	int RopeJoint::getAnchorB(State & state, b2RopeJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetAnchorB()), true);
		return 1;
	}

	int RopeJoint::getReactionForce(State & state, b2RopeJoint * object){
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

	int RopeJoint::getReactionTorque(State & state, b2RopeJoint * object){
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


	inline int RopeJoint::getActive(State & state, b2RopeJoint * object){
		return base->getActive(state, object);
	}

	inline int RopeJoint::getCollideConnected(State & state, b2RopeJoint * object){
		return base->getCollideConnected(state, object);
	}

	int RopeJoint::getLocalAnchorA(State & state, b2RopeJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetLocalAnchorA()), true);
		return 1;
	}

	int RopeJoint::getLocalAnchorB(State & state, b2RopeJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetLocalAnchorB()), true);
		return 1;
	}

	int RopeJoint::getMaxLength(State & state, b2RopeJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetMaxLength()));
		return 1;
	}

	int RopeJoint::setMaxLength(State & state, b2RopeJoint * object){
		object->SetMaxLength(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int RopeJoint::getLimitState(State & state, b2RopeJoint * object){
		state.stack->push<int>(static_cast<int>(object->GetLimitState()));
		return 1;
	}

};
