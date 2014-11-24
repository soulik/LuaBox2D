#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Joint.hpp"
#include "objects/PulleyJoint.hpp"

namespace LuaBox2D {
	void initPulleyJoint(State * state){
		state->registerInterface<PulleyJoint>("LuaBox2D_PulleyJoint");
	}

	b2PulleyJoint * PulleyJoint::constructor(State & state, bool & managed){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		b2Joint * joint = interfaceJoint->get(1);
		if (joint != nullptr){
			if (joint->GetType() == b2JointType::e_pulleyJoint){
				managed = false;
				return dynamic_cast<b2PulleyJoint*>(joint);
			}else{
				return nullptr;
			}
		}else{
			return nullptr;
		}
	}

	void PulleyJoint::destructor(State & state, b2PulleyJoint * object){
		base->destructor(state, object);
	}

	inline int PulleyJoint::getType(State & state, b2PulleyJoint * object){
		return base->getType(state, object);
	}

	inline int PulleyJoint::getBodyA(State & state, b2PulleyJoint * object){
		return base->getBodyA(state, object);
	}

	inline int PulleyJoint::getBodyB(State & state, b2PulleyJoint * object){
		return base->getBodyB(state, object);
	}

	inline int PulleyJoint::getUserData(State & state, b2PulleyJoint * object){
		return base->getUserData(state, object);
	}

	inline int PulleyJoint::setUserData(State & state, b2PulleyJoint * object){
		return base->setUserData(state, object);
	}

	int PulleyJoint::getAnchorA(State & state, b2PulleyJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetAnchorA()), true);
		return 1;
	}

	int PulleyJoint::getAnchorB(State & state, b2PulleyJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetAnchorB()), true);
		return 1;
	}

	int PulleyJoint::getReactionForce(State & state, b2PulleyJoint * object){
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

	int PulleyJoint::getReactionTorque(State & state, b2PulleyJoint * object){
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

	inline int PulleyJoint::getActive(State & state, b2PulleyJoint * object){
		return base->getActive(state, object);
	}

	inline int PulleyJoint::getCollideConnected(State & state, b2PulleyJoint * object){
		return base->getCollideConnected(state, object);
	}

	int PulleyJoint::getGroundAnchorA(State & state, b2PulleyJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetGroundAnchorA()), true);
		return 1;
	}

	int PulleyJoint::getGroundAnchorB(State & state, b2PulleyJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetGroundAnchorB()), true);
		return 1;
	}

	int PulleyJoint::getLengthA(State & state, b2PulleyJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetLengthA()));
		return 1;
	}

	int PulleyJoint::getLengthB(State & state, b2PulleyJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetLengthB()));
		return 1;
	}

	int PulleyJoint::getRatio(State & state, b2PulleyJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetRatio()));
		return 1;
	}

	int PulleyJoint::getCurrentLengthA(State & state, b2PulleyJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetCurrentLengthA()));
		return 1;
	}

	int PulleyJoint::getCurrentLengthB(State & state, b2PulleyJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetCurrentLengthB()));
		return 1;
	}

	int PulleyJoint::shiftOrigin(State & state, b2PulleyJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * linearOffset = interfaceVec2->get(1);
		if (linearOffset != nullptr){
			object->ShiftOrigin(*linearOffset);
		}
		return 0;
	}
};
