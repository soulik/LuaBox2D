#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Rot.hpp"
#include "objects/Transform.hpp"

namespace LuaBox2D {
	void initTransform(State * state){
		state->registerInterface<Transform>("LuaBox2D_Transform");
	}

	b2Transform * Transform::constructor(State & state){
		b2Transform * obj = nullptr;
		Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
		Rot * interfaceRot = dynamic_cast<Rot*>(state.interfaces["LuaBox2D_Rot"]);

		Stack * stack = state.stack;
		b2Vec2 * position = interfaceVec2->get(1);
		b2Rot * rotation = interfaceRot->get(2);

		if (position != nullptr && rotation != nullptr){
			obj = new b2Transform(*position, *rotation);
		}else{
			obj = new b2Transform();
		}

		return obj;
	}

	void Transform::destructor(State & state, b2Transform * object){
		delete object;
	}

	int Transform::identity(State & state, b2Transform * object){
		object->SetIdentity();
		return 0;
	}

	int Transform::set(State & state, b2Transform * object){
		Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
		b2Vec2 * position = interfaceVec2->get(1);
		if (position != nullptr && state.stack->is<LUA_TNUMBER>(2)){
			object->Set(*position, static_cast<float32>(state.stack->to<LUA_NUMBER>(2)));
		}
		return 0;
	}
};

