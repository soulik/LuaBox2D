#ifndef LUABOX2D_RAYCASTOUTPUT_H
#define LUABOX2D_RAYCASTOUTPUT_H

#include "objects/Vec2.hpp"

namespace LuaBox2D {
	class RayCastOutput : public Object<b2RayCastOutput> {
	public:
		explicit RayCastOutput(State * state) : Object<b2RayCastOutput>(state){
			LUTOK_PROPERTY("normal", &RayCastOutput::getNormal, &RayCastOutput::setNormal);
			LUTOK_PROPERTY("fraction", &RayCastOutput::getFraction, &RayCastOutput::setFraction);
		}

		b2RayCastOutput * constructor(State & state){
			b2RayCastOutput * object = new b2RayCastOutput();
			return object;
		}

		void destructor(State & state, b2RayCastOutput * object){
			delete object;
		}

		int getNormal(State & state, b2RayCastOutput * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			interfaceVec2->push(&object->normal, false);
			return 1;
		}

		int setNormal(State & state, b2RayCastOutput * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			b2Vec2 * point = interfaceVec2->get(1);
			if (point != nullptr){
				object->normal = *point;
			}
			return 0;
		}

		int getFraction(State & state, b2RayCastOutput * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->fraction));
			return 1;
		}

		int setFraction(State & state, b2RayCastOutput * object){
			object->fraction = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
			return 0;
		}
	};

	void initRayCastOutput(State * );
};

#endif	
