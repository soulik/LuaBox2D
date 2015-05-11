#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Rot.hpp"

namespace LuaBox2D {
	void initRot(State * state){
		state->registerInterface<Rot>("LuaBox2D_Rot");
	}

	b2Rot * Rot::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		b2Rot * obj = nullptr;

		Stack * stack = state.stack;
		if (stack->is<LUA_TNUMBER>(1)){
			obj = new b2Rot(
				static_cast<float32>(stack->to<LUA_NUMBER>(1))
				);
		}else{
			obj = new b2Rot();
		}

		return obj;
	}

	void Rot::destructor(State & state, b2Rot * object){
		delete object;
	}

	int Rot::getXAxis(State & state, b2Rot * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetXAxis()));
		return 1;
	}

	int Rot::getYAxis(State & state, b2Rot * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetYAxis()));
		return 1;
	}

	int Rot::getAngle(State & state, b2Rot * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetAngle()));
		return 1;
	}

	int Rot::setAngle(State & state, b2Rot * object){
		if (state.stack->is<LUA_TNUMBER>(1)){
			object->Set(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		}
		return 0;
	}

	int Rot::identity(State & state, b2Rot * object){
		object->SetIdentity();
		return 0;
	}
};

