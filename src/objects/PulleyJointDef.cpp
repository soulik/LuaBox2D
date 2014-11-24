#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Body.hpp"
#include "objects/JointDef.hpp"
#include "objects/PulleyJointDef.hpp"

namespace LuaBox2D {
	void initPulleyJointDef(State * state){
		state->registerInterface<PulleyJointDef>("LuaBox2D_PulleyJointDef");
	}

	b2PulleyJointDef * PulleyJointDef::constructor(State & state, bool & managed){
		JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
		b2JointDef * jointDef = interfaceJointDef->get(1);
		if (jointDef != nullptr){
			if (jointDef->type == b2JointType::e_pulleyJoint){
				managed = false;
				return reinterpret_cast<b2PulleyJointDef*>(jointDef);
			}else{
				return new b2PulleyJointDef();
			}
		}else{
			return new b2PulleyJointDef();
		}
	}

	void PulleyJointDef::destructor(State & state, b2PulleyJointDef * object){
		delete object;
	}

	inline int PulleyJointDef::getBodyA(State & state, b2PulleyJointDef * object){
		return base->getBodyA(state, object);
	}

	inline int PulleyJointDef::setBodyA(State & state, b2PulleyJointDef * object){
		return base->setBodyA(state, object);
	}

	inline int PulleyJointDef::getBodyB(State & state, b2PulleyJointDef * object){
		return base->getBodyB(state, object);
	}

	inline int PulleyJointDef::setBodyB(State & state, b2PulleyJointDef * object){
		return base->setBodyB(state, object);
	}

	inline int PulleyJointDef::getType(State & state, b2PulleyJointDef * object){
		return base->getType(state, object);
	}

	inline int PulleyJointDef::setType(State & state, b2PulleyJointDef * object){
		return base->setType(state, object);
	}

	inline int PulleyJointDef::getCollideConnected(State & state, b2PulleyJointDef * object){
		return base->getCollideConnected(state, object);
	}

	inline int PulleyJointDef::setCollideConnected(State & state, b2PulleyJointDef * object){
		return base->setCollideConnected(state, object);
	}

	inline int PulleyJointDef::getUserData(State & state, b2PulleyJointDef * object){
		return base->getUserData(state, object);
	}

	inline int PulleyJointDef::setUserData(State & state, b2PulleyJointDef * object){
		return base->setUserData(state, object);
	}

	int PulleyJointDef::initialize(State & state, b2PulleyJointDef * object){
		Body * interfaceBody = state.getInterface<Body>("LuaBox2D_Body");
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");

		if (state.stack->is<LUA_TUSERDATA>(1) && state.stack->is<LUA_TUSERDATA>(2) && state.stack->is<LUA_TUSERDATA>(3) && state.stack->is<LUA_TUSERDATA>(4)
			&& state.stack->is<LUA_TUSERDATA>(5) && state.stack->is<LUA_TUSERDATA>(6) && state.stack->is<LUA_TNUMBER>(7)
			){
			b2Body * bodyA = interfaceBody->get(1);
			b2Body * bodyB = interfaceBody->get(2);
			b2Vec2 * groundAnchorA = interfaceVec2->get(3);
			b2Vec2 * groundAnchorB = interfaceVec2->get(4);
			b2Vec2 * anchorA = interfaceVec2->get(5);
			b2Vec2 * anchorB = interfaceVec2->get(6);

			if (bodyA != nullptr && bodyB != nullptr && groundAnchorA != nullptr && groundAnchorB != nullptr && anchorA != nullptr && anchorB != nullptr){
				object->Initialize(bodyA, bodyB, *groundAnchorA, *groundAnchorB, *anchorA, *anchorB, static_cast<float32>(state.stack->to<LUA_NUMBER>(7)));
			}
		}
		return 0;
	}

	int PulleyJointDef::getLocalAnchorA(State & state, b2PulleyJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->localAnchorA, false);
		return 1;
	}

	int PulleyJointDef::setLocalAnchorA(State & state, b2PulleyJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * anchor = interfaceVec2->get(1);
		if (anchor != nullptr){
			object->localAnchorA = *anchor;
		}
		return 0;
	}

	int PulleyJointDef::getLocalAnchorB(State & state, b2PulleyJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->localAnchorB, false);
		return 1;
	}

	int PulleyJointDef::setLocalAnchorB(State & state, b2PulleyJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * anchor = interfaceVec2->get(1);
		if (anchor != nullptr){
			object->localAnchorB = *anchor;
		}
		return 0;
	}

	int PulleyJointDef::getGroundAnchorA(State & state, b2PulleyJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->groundAnchorA, false);
		return 1;
	}

	int PulleyJointDef::setGroundAnchorA(State & state, b2PulleyJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * anchor = interfaceVec2->get(1);
		if (anchor != nullptr){
			object->groundAnchorA = *anchor;
		}
		return 0;
	}

	int PulleyJointDef::getGroundAnchorB(State & state, b2PulleyJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->groundAnchorB, false);
		return 1;
	}

	int PulleyJointDef::setGroundAnchorB(State & state, b2PulleyJointDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * anchor = interfaceVec2->get(1);
		if (anchor != nullptr){
			object->groundAnchorB = *anchor;
		}
		return 0;
	}

	int PulleyJointDef::getLengthA(State & state, b2PulleyJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->lengthA));
		return 1;
	}

	int PulleyJointDef::setLengthA(State & state, b2PulleyJointDef * object){
		object->lengthA = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int PulleyJointDef::getLengthB(State & state, b2PulleyJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->lengthB));
		return 1;
	}

	int PulleyJointDef::setLengthB(State & state, b2PulleyJointDef * object){
		object->lengthB = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int PulleyJointDef::getRatio(State & state, b2PulleyJointDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->ratio));
		return 1;
	}

	int PulleyJointDef::setRatio(State & state, b2PulleyJointDef * object){
		object->ratio = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}
};
