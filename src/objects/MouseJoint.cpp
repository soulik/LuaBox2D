#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Joint.hpp"
#include "objects/MouseJoint.hpp"

namespace LuaBox2D {
	void initMouseJoint(State * state){
		state->registerInterface<MouseJoint>("LuaBox2D_MouseJoint");
	}

	b2MouseJoint * MouseJoint::constructor(State & state, bool & managed){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		b2Joint * joint = interfaceJoint->get(1);
		if (joint != nullptr){
			if (joint->GetType() == b2JointType::e_mouseJoint){
				managed = false;
				return dynamic_cast<b2MouseJoint*>(joint);
			}else{
				return nullptr;
			}
		}else{
			return nullptr;
		}
	}

	void MouseJoint::destructor(State & state, b2MouseJoint * object){
		base->destructor(state, object);
	}

	inline int MouseJoint::getType(State & state, b2MouseJoint * object){
		return base->getType(state, object);
	}

	inline int MouseJoint::getBodyA(State & state, b2MouseJoint * object){
		return base->getBodyA(state, object);
	}

	inline int MouseJoint::getBodyB(State & state, b2MouseJoint * object){
		return base->getBodyB(state, object);
	}

	inline int MouseJoint::getUserData(State & state, b2MouseJoint * object){
		return base->getUserData(state, object);
	}

	inline int MouseJoint::setUserData(State & state, b2MouseJoint * object){
		return base->setUserData(state, object);
	}

	int MouseJoint::getAnchorA(State & state, b2MouseJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetAnchorA()), true);
		return 1;
	}

	int MouseJoint::getAnchorB(State & state, b2MouseJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetAnchorB()), true);
		return 1;
	}

	inline int MouseJoint::getActive(State & state, b2MouseJoint * object){
		return base->getActive(state, object);
	}

	inline int MouseJoint::getCollideConnected(State & state, b2MouseJoint * object){
		return base->getCollideConnected(state, object);
	}

	int MouseJoint::getReactionForce(State & state, b2MouseJoint * object){
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

	int MouseJoint::getReactionTorque(State & state, b2MouseJoint * object){
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

	int MouseJoint::getTarget(State & state, b2MouseJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetTarget()), true);
		return 1;
	}

	int MouseJoint::setTarget(State & state, b2MouseJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * linearOffset = interfaceVec2->get(1);
		if (linearOffset != nullptr){
			object->SetTarget(*linearOffset);
		}
		return 0;
	}

	int MouseJoint::getMaxForce(State & state, b2MouseJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetMaxForce()));
		return 1;
	}

	int MouseJoint::setMaxForce(State & state, b2MouseJoint * object){
		object->SetMaxForce(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int MouseJoint::getFrequencyHz(State & state, b2MouseJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetFrequency()));
		return 1;
	}

	int MouseJoint::setFrequencyHz(State & state, b2MouseJoint * object){
		object->SetFrequency(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int MouseJoint::getDampingRatio(State & state, b2MouseJoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetDampingRatio()));
		return 1;
	}

	int MouseJoint::setDampingRatio(State & state, b2MouseJoint * object){
		object->SetDampingRatio(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int MouseJoint::shiftOrigin(State & state, b2MouseJoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * linearOffset = interfaceVec2->get(1);
		if (linearOffset != nullptr){
			object->ShiftOrigin(*linearOffset);
		}
		return 0;
	}
};
