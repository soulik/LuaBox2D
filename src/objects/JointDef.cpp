#include "common.hpp"
#include "objects/JointDef.hpp"
#include "objects/Body.hpp"

namespace LuaBox2D {
	void initJointDef(State * state){
		state->registerInterface<JointDef>("LuaBox2D_JointDef");
	}

	b2JointDef * JointDef::constructor(State & state){
		Body * interfaceBody = state.getInterface<Body>("LuaBox2D_Body");
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
		Body * interfaceBody = state.getInterface<Body>("LuaBox2D_Body");
		if (object->bodyA != nullptr){
			interfaceBody->push(object->bodyA, false);
			return 1;
		}else{
			return 0;
		}
	}

	int JointDef::setBodyA(State & state, b2JointDef * object){
		Body * interfaceBody = state.getInterface<Body>("LuaBox2D_Body");
		b2Body * body = interfaceBody->get(1);
		if (body != nullptr){
			object->bodyA = body;
		}
		return 0;
	}

	int JointDef::getBodyB(State & state, b2JointDef * object){
		Body * interfaceBody = state.getInterface<Body>("LuaBox2D_Body");
		if (object->bodyA != nullptr){
			interfaceBody->push(object->bodyB, false);
			return 1;
		}else{
			return 0;
		}
	}

	int JointDef::setBodyB(State & state, b2JointDef * object){
		Body * interfaceBody = state.getInterface<Body>("LuaBox2D_Body");
		b2Body * body = interfaceBody->get(1);
		if (body != nullptr){
			object->bodyB = body;
		}
		return 0;
	}

	void JointDef::destructor(State & state, b2JointDef * object){
		delete object;
	}

	b2JointDef * JointDef::get(const int index){
		ObjWrapper * wrapper = getWrapped(index, validTypes);
		if (wrapper){
			return wrapper->instance;
		}else{

			return nullptr;
		}
	}

	int JointDef::getType(State & state, b2JointDef * object){
		state.stack->push<int>(static_cast<int>(object->type));
		return 1;
	}

	int JointDef::setType(State & state, b2JointDef * object){
		object->type = static_cast<b2JointType>(state.stack->to<int>(1));
		return 0;
	}

	int JointDef::getCollideConnected(State & state, b2JointDef * object){
		state.stack->push<bool>(object->collideConnected);
		return 1;
	}

	int JointDef::setCollideConnected(State & state, b2JointDef * object){
		object->collideConnected =  state.stack->to<bool>(1);
		return 0;
	}

	int JointDef::getUserData(State & state, b2JointDef * object){
		int ref = static_cast<int>(reinterpret_cast<intptr_t>(object->userData));
		if (ref != LUA_NOREF && ref != 0){
			state.stack->rawGet(LUA_REGISTRYINDEX, ref);
			return 1;
		}else{
			return 0;
		}
	}

	int JointDef::setUserData(State & state, b2JointDef * object){
		int oldRef = static_cast<int>(reinterpret_cast<intptr_t>(object->userData));
		if (oldRef != LUA_NOREF && oldRef != 0){
			state.stack->unref(oldRef);
		}
		if (!state.stack->is<LUA_TNIL>(1)){
			state.stack->pushValue(1);
			int ref = state.stack->ref();

			object->userData = reinterpret_cast<void*>(ref);
		}
		return 0;
	}
};
