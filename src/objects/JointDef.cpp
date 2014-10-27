#include "common.hpp"
#include "objects/JointDef.hpp"

namespace LuaBox2D {
	void initJointDef(State * state){
		state->registerInterface<JointDef>("LuaBox2D_JointDef");
	}

	b2JointDef * JointDef::constructor(State & state){
		Body * interfaceBody = dynamic_cast<Body*>(state.interfaces["LuaBox2D_Body"]);
		b2JointDef * object = new b2JointDef();
		object->bodyA = nullptr;
		object->bodyB = nullptr;

		if (state.stack->is<LUA_TUSERDATA>(1) && state.stack->is<LUA_TUSERDATA>(2)){
			b2Body * bodyA = interfaceBody->get(1);
			b2Body * bodyB = interfaceBody->get(2);
			if (bodyA != nullptr && bodyB != nullptr){
				object->bodyA = bodyA;
				object->bodyB = bodyB;
			}
		}
		return object;
	}

	int JointDef::getBodyA(State & state, b2JointDef * object){
		Body * interfaceBody = dynamic_cast<Body*>(state.interfaces["LuaBox2D_Body"]);
		if (object->bodyA != nullptr){
			interfaceBody->push(object->bodyA, false);
			return 1;
		}else{
			return 0;
		}
	}

	int JointDef::setBodyA(State & state, b2JointDef * object){
		Body * interfaceBody = dynamic_cast<Body*>(state.interfaces["LuaBox2D_Body"]);
		b2Body * body = interfaceBody->get(1);
		if (body != nullptr){
			object->bodyA = body;
		}
		return 0;
	}

	int JointDef::getBodyB(State & state, b2JointDef * object){
		Body * interfaceBody = dynamic_cast<Body*>(state.interfaces["LuaBox2D_Body"]);
		if (object->bodyA != nullptr){
			interfaceBody->push(object->bodyB, false);
			return 1;
		}else{
			return 0;
		}
	}

	int JointDef::setBodyB(State & state, b2JointDef * object){
		Body * interfaceBody = dynamic_cast<Body*>(state.interfaces["LuaBox2D_Body"]);
		b2Body * body = interfaceBody->get(1);
		if (body != nullptr){
			object->bodyB = body;
		}
		return 0;
	}
};
