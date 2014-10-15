#ifndef LUABOX2D_SWEEP_H
#define LUABOX2D_SWEEP_H

#include "objects/Transform.hpp"

namespace LuaBox2D {
	class Sweep : public Object<b2Sweep> {
	public:
		explicit Sweep(State * state) : Object<b2Sweep>(state){
			/*
			LUTOK_PROPERTY("x", &b2Sweep::getXAxis, &b2Sweep::nullMethod);
			LUTOK_PROPERTY("y", &b2Sweep::getYAxis, &b2Sweep::nullMethod);
			LUTOK_PROPERTY("angle", &b2Sweep::getAngle, &b2Sweep::setAngle);

			
			*/
			LUTOK_METHOD("transform", &Sweep::getTransform);
			LUTOK_METHOD("advance", &Sweep::advance);
			LUTOK_METHOD("normalize", &Sweep::normalize);
		}

		b2Sweep * constructor(State & state){
			b2Sweep * obj = nullptr;
			obj = new b2Sweep();
			return obj;
		}

		void destructor(State & state, b2Sweep * object){
			delete object;
		}

		int getTransform(State & state, b2Sweep * object){
			if (state.stack->is<LUA_TNUMBER>(1)){
				Transform * interfaceTransform = dynamic_cast<Transform*>(state.interfaces["LuaBox2D_Transform"]);
				b2Transform * transform = new b2Transform();
				object->GetTransform(transform, static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
				interfaceTransform->push(transform, true);
				return 1;
			}else{
				return 0;
			}
		}

		int advance(State & state, b2Sweep * object){
			if (state.stack->is<LUA_TNUMBER>(1)){
				object->Advance(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
			}
			return 0;
		}

		int normalize(State & state, b2Sweep * object){
			object->Normalize();
			return 0;
		}
	};

	void initSweep(State *);
};

#endif
