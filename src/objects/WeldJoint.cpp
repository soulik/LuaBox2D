#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Joint.hpp"
#include "objects/WeldJoint.hpp"

namespace LuaBox2D {
	void initWeldJoint(State * state){
		state->registerInterface<WeldJoint>("LuaBox2D_WeldJoint");
	}

	b2WeldJoint * WeldJoint::constructor(State & state, bool & managed){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		b2Joint * joint = interfaceJoint->get(1);
		if (joint != nullptr){
			if (joint->GetType() == b2JointType::e_weldJoint){
				managed = false;
				return dynamic_cast<b2WeldJoint*>(joint);
			}else{
				return nullptr;
			}
		}else{
			return nullptr;
		}
	}

	void WeldJoint::destructor(State & state, b2WeldJoint * object){
		base->destructor(state, object);
	}

	inline int WeldJoint::getType(State & state, b2WeldJoint * object){
		return base->getType(state, object);
	}

	inline int WeldJoint::getBodyA(State & state, b2WeldJoint * object){
		return base->getBodyA(state, object);
	}

	inline int WeldJoint::getBodyB(State & state, b2WeldJoint * object){
		return base->getBodyB(state, object);
	}

	inline int WeldJoint::getUserData(State & state, b2WeldJoint * object){
		return base->getUserData(state, object);
	}

	inline int WeldJoint::setUserData(State & state, b2WeldJoint * object){
		return base->setUserData(state, object);
	}

	int WeldJoint::getAnchorA(State & state, b2WeldJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetAnchorA()), true);
		return 1;
	}

	int WeldJoint::getAnchorB(State & state, b2WeldJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetAnchorB()), true);
		return 1;
	}

	int WeldJoint::getReactionForce(State & state, b2WeldJoint * object){
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

	int WeldJoint::getReactionTorque(State & state, b2WeldJoint * object){
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

	inline int WeldJoint::getActive(State & state, b2WeldJoint * object){
		return base->getActive(state, object);
	}

	inline int WeldJoint::getCollideConnected(State & state, b2WeldJoint * object){
		return base->getCollideConnected(state, object);
	}

	int WeldJoint::getLocalAnchorA(State & state, b2WeldJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetLocalAnchorA()), true);
		return 1;
	}

	int WeldJoint::getLocalAnchorB(State & state, b2WeldJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetLocalAnchorB()), true);
		return 1;
	}

	int WeldJoint::getReferenceAngle(State & state, b2WeldJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetReferenceAngle()));
		return 1;
	}

	int WeldJoint::getFrequencyHz(State & state, b2WeldJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetFrequency()));
		return 1;
	}

	int WeldJoint::setFrequencyHz(State & state, b2WeldJoint * object){
		object->SetFrequency(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int WeldJoint::getDampingRatio(State & state, b2WeldJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetDampingRatio()));
		return 1;
	}

	int WeldJoint::setDampingRatio(State & state, b2WeldJoint * object){
		object->SetDampingRatio(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}
};
