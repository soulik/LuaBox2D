#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Body.hpp"
#include "objects/Joint.hpp"

namespace LuaBox2D {
	void initJoint(State * state){
		state->registerInterface<Joint>("LuaBox2D_Joint");
	}

	b2Joint * Joint::constructor(State & state){
		b2Joint *obj = get(1);
		if (obj != nullptr){
			return obj;
		}else{
			return nullptr;
		}
	}

	int Joint::getBodyA(State & state, b2Joint * object){
		Body * interfaceBody = dynamic_cast<Body*>(state.interfaces["LuaBox2D_Body"]);
		interfaceBody->push(object->GetBodyA(), false);
		return 1;
	}

	int Joint::getBodyB(State & state, b2Joint * object){
		Body * interfaceBody = dynamic_cast<Body*>(state.interfaces["LuaBox2D_Body"]);
		interfaceBody->push(object->GetBodyB(), false);
		return 1;
	}

	int Joint::getAnchorA(State & state, b2Joint * object){
		Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
		interfaceVec2->push(new b2Vec2(object->GetAnchorA()), true);
		return 1;
	}

	int Joint::getAnchorB(State & state, b2Joint * object){
		Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
		interfaceVec2->push(new b2Vec2(object->GetAnchorB()), true);
		return 1;
	}


	int Joint::getReactionForce(State & state, b2Joint * object){
		Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
		if (state.stack->is<LUA_TNUMBER>(1)){
			interfaceVec2->push(new b2Vec2(object->GetReactionForce(
				static_cast<float32>(state.stack->to<LUA_NUMBER>(1))
				)), true);
			return 1;
		}else{
			return 0;
		}
	}

	int Joint::getReactionTorque(State & state, b2Joint * object){
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

	b2Joint * Joint::get(const int index){
		ObjWrapper * wrapper = getWrapped(index, validTypes);
		if (wrapper){
			return wrapper->instance;
		}else{

			return nullptr;
		}
	}

	void Joint::destructor(State & state, b2Joint * object){
		object->GetBodyA()->GetWorld()->DestroyJoint(object);
	}

	int Joint::getType(State & state, b2Joint * object){
		state.stack->push<int>(static_cast<int>(object->GetType()));
		return 1;
	}

	int Joint::getActive(State & state, b2Joint * object){
		state.stack->push<bool>(object->IsActive());
		return 1;
	}

	int Joint::getCollideConnected(State & state, b2Joint * object){
		state.stack->push<bool>(object->GetCollideConnected());
		return 1;
	}

};
