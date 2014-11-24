#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Joint.hpp"
#include "objects/DistanceJoint.hpp"

namespace LuaBox2D {
	void initDistanceJoint(State * state){
		state->registerInterface<DistanceJoint>("LuaBox2D_DistanceJoint");
	}

	b2DistanceJoint * DistanceJoint::constructor(State & state, bool & managed){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		b2Joint * joint = interfaceJoint->get(1);
		if (joint != nullptr){
			if (joint->GetType() == b2JointType::e_distanceJoint){
				managed = false;
				return dynamic_cast<b2DistanceJoint*>(joint);
			}else{
				return nullptr;
			}
		}else{
			return nullptr;
		}
	}

	void DistanceJoint::destructor(State & state, b2DistanceJoint * object){
		base->destructor(state, object);
	}

	inline int DistanceJoint::getType(State & state, b2DistanceJoint * object){
		return base->getType(state, object);
	}

	inline int DistanceJoint::getBodyA(State & state, b2DistanceJoint * object){
		return base->getBodyA(state, object);
	}

	inline int DistanceJoint::getBodyB(State & state, b2DistanceJoint * object){
		return base->getBodyB(state, object);
	}

	inline int DistanceJoint::getUserData(State & state, b2DistanceJoint * object){
		return base->getUserData(state, object);
	}

	inline int DistanceJoint::setUserData(State & state, b2DistanceJoint * object){
		return base->setUserData(state, object);
	}

	int DistanceJoint::getReactionForce(State & state, b2DistanceJoint * object){
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

	int DistanceJoint::getReactionTorque(State & state, b2DistanceJoint * object){
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

	inline int DistanceJoint::getActive(State & state, b2DistanceJoint * object){
		return base->getActive(state, object);
	}

	inline int DistanceJoint::getCollideConnected(State & state, b2DistanceJoint * object){
		return base->getCollideConnected(state, object);
	}

	int DistanceJoint::getAnchorA(State & state, b2DistanceJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetAnchorA()), true);
		return 1;
	}

	int DistanceJoint::getAnchorB(State & state, b2DistanceJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetAnchorB()), true);
		return 1;
	}

	int DistanceJoint::getLocalAnchorA(State & state, b2DistanceJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetLocalAnchorA()), true);
		return 1;
	}

	int DistanceJoint::getLocalAnchorB(State & state, b2DistanceJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetLocalAnchorB()), true);
		return 1;
	}

	int DistanceJoint::getLength(State & state, b2DistanceJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetLength()));
		return 1;
	}

	int DistanceJoint::setLength(State & state, b2DistanceJoint * object){
		object->SetLength(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int DistanceJoint::getFrequencyHz(State & state, b2DistanceJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetFrequency()));
		return 1;
	}

	int DistanceJoint::setFrequencyHz(State & state, b2DistanceJoint * object){
		object->SetFrequency(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int DistanceJoint::getDampingRatio(State & state, b2DistanceJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetDampingRatio()));
		return 1;
	}

	int DistanceJoint::setDampingRatio(State & state, b2DistanceJoint * object){
		object->SetDampingRatio(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

};
