#ifndef LUABOX2D_ROT_H
#define LUABOX2D_ROT_H

#include "objects/Vec2.hpp"

namespace LuaBox2D {
	class Rot : public Object<b2Rot> {
	public:
		explicit Rot(State * state) : Object<b2Rot>(state){
			LUTOK_PROPERTY("x", &Rot::getXAxis, &Rot::nullMethod);
			LUTOK_PROPERTY("y", &Rot::getYAxis, &Rot::nullMethod);
			LUTOK_PROPERTY("angle", &Rot::getAngle, &Rot::setAngle);

			LUTOK_METHOD("identity", &Rot::identity);
		}

		b2Rot * constructor(State & state){
			b2Rot * obj = nullptr;
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["Vec2"]);

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
		void destructor(State & state, b2Rot * object){
			delete object;
		}

		int getXAxis(State & state, b2Rot * object){
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["Vec2"]);
			interfaceVec2->push(new b2Vec2(object->GetXAxis()));
			return 1;
		}

		int getYAxis(State & state, b2Rot * object){
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["Vec2"]);
			interfaceVec2->push(new b2Vec2(object->GetYAxis()));
			return 1;
		}

		int getAngle(State & state, b2Rot * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetAngle()));
			return 1;
		}

		int setAngle(State & state, b2Rot * object){
			if (state.stack->is<LUA_TNUMBER>(1)){
				object->Set(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
			}
			return 0;
		}

		int identity(State & state, b2Rot * object){
			object->SetIdentity();
			return 0;
		}

	};

	void initRot(State *);
};

#endif