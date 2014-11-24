#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Body.hpp"
#include "objects/JointDef.hpp"
#include "objects/DistanceJointDef.hpp"

namespace LuaBox2D {
	void initDistanceJointDef(State * state){
		state->registerInterface<DistanceJointDef>("LuaBox2D_DistanceJointDef");
	}

	b2DistanceJointDef * DistanceJointDef::constructor(State & state, bool & managed){
		JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
		b2JointDef * jointDef = interfaceJointDef->get(1);
		if (jointDef != nullptr){
			if (jointDef->type == b2JointType::e_distanceJoint){
				managed = false;
				return reinterpret_cast<b2DistanceJointDef*>(jointDef);
			}else{
				return new b2DistanceJointDef();
			}
		}else{
			return new b2DistanceJointDef();
		}
	}

	void DistanceJointDef::destructor(State & state, b2DistanceJointDef * object){
		delete object;
	}

	inline int DistanceJointDef::getBodyA(State & state, b2DistanceJointDef * object){
		return base->getBodyA(state, object);
	}

	inline int DistanceJointDef::setBodyA(State & state, b2DistanceJointDef * object){
		return base->setBodyA(state, object);
	}

	inline int DistanceJointDef::getBodyB(State & state, b2DistanceJointDef * object){
		return base->getBodyB(state, object);
	}

	inline int DistanceJointDef::setBodyB(State & state, b2DistanceJointDef * object){
		return base->setBodyB(state, object);
	}

	inline int DistanceJointDef::getType(State & state, b2DistanceJointDef * object){
		return base->getType(state, object);
	}

	inline int DistanceJointDef::setType(State & state, b2DistanceJointDef * object){
		return base->setType(state, object);
	}

	inline int DistanceJointDef::getCollideConnected(State & state, b2DistanceJointDef * object){
		return base->getCollideConnected(state, object);
	}

	inline int DistanceJointDef::setCollideConnected(State & state, b2DistanceJointDef * object){
		return base->setCollideConnected(state, object);
	}

	inline int DistanceJointDef::getUserData(State & state, b2DistanceJointDef * object){
		return base->getUserData(state, object);
	}

	inline int DistanceJointDef::setUserData(State & state, b2DistanceJointDef * object){
		return base->setUserData(state, object);
	}

	int DistanceJointDef::initialize(State & state, b2DistanceJointDef * object){
		Body * interfaceBody = state.getInterface<Body>("LuaBox2D_Body");
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");

		if (state.stack->is<LUA_TUSERDATA>(1) && state.stack->is<LUA_TUSERDATA>(2) && state.stack->is<LUA_TUSERDATA>(3) && state.stack->is<LUA_TUSERDATA>(4)){
			b2Body * bodyA = interfaceBody->get(1);
			b2Body * bodyB = interfaceBody->get(2);
			b2Vec2 * anchorA = interfaceVec2->get(3);
			b2Vec2 * anchorB = interfaceVec2->get(4);

			if (bodyA != nullptr && bodyB != nullptr && anchorA != nullptr && anchorB != nullptr){
				object->Initialize(bodyA, bodyB, *anchorA, *anchorB);
			}
		}
		return 0;
	}

	int DistanceJointDef::getLocalAnchorA(State & state, b2DistanceJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->localAnchorA, false);
		return 1;
	}

	int DistanceJointDef::setLocalAnchorA(State & state, b2DistanceJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * anchor = interfaceVec2->get(1);
		if (anchor != nullptr){
			object->localAnchorA = *anchor;
		}
		return 0;
	}

	int DistanceJointDef::getLocalAnchorB(State & state, b2DistanceJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->localAnchorB, false);
		return 1;
	}

	int DistanceJointDef::setLocalAnchorB(State & state, b2DistanceJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * anchor = interfaceVec2->get(1);
		if (anchor != nullptr){
			object->localAnchorB = *anchor;
		}
		return 0;
	}

	int DistanceJointDef::getLength(State & state, b2DistanceJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->length));
		return 1;
	}

	int DistanceJointDef::setLength(State & state, b2DistanceJointDef * object){
		object->length = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int DistanceJointDef::getFrequencyHz(State & state, b2DistanceJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->frequencyHz));
		return 1;
	}

	int DistanceJointDef::setFrequencyHz(State & state, b2DistanceJointDef * object){
		object->frequencyHz = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int DistanceJointDef::getDampingRatio(State & state, b2DistanceJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->dampingRatio));
		return 1;
	}

	int DistanceJointDef::setDampingRatio(State & state, b2DistanceJointDef * object){
		object->dampingRatio = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}
};
