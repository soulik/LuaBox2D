#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Rot.hpp"
#include "objects/Transform.hpp"

namespace LuaBox2D {
	void initTransform(State * state){
		state->registerInterface<Transform>("LuaBox2D_Transform");
	}

	b2Transform * Transform::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		b2Transform * obj = nullptr;
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		Rot * interfaceRot = state.getInterface<Rot>("LuaBox2D_Rot");

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
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * position = interfaceVec2->get(1);
		if (position != nullptr && state.stack->is<LUA_TNUMBER>(2)){
			object->Set(*position, static_cast<float32>(state.stack->to<LUA_NUMBER>(2)));
		}
		return 0;
	}

	int Transform::getP(State & state, b2Transform * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->p, false);
		return 1;
	}

	int Transform::setP(State & state, b2Transform * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * p = interfaceVec2->get(1);
		if (p != nullptr){
			object->p = *p;
		}
		return 0;
	}

	int Transform::getQ(State & state, b2Transform * object){
		Rot * interfaceRot = state.getInterface<Rot>("LuaBox2D_Rot");
		interfaceRot->push(&object->q, false);
		return 1;
	}

	int Transform::setQ(State & state, b2Transform * object){
		Rot * interfaceRot = state.getInterface<Rot>("LuaBox2D_Rot");
		b2Rot * q = interfaceRot->get(1);
		if (q != nullptr){
			object->q = *q;
		}
		return 0;
	}
};

