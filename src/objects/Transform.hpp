#ifndef LUABOX2D_TRANSFORM_H
#define LUABOX2D_TRANSFORM_H

#include "objects/Vec2.hpp"
#include "objects/Rot.hpp"

namespace LuaBox2D {
	class Transform : public Object<b2Transform> {
	public:
		explicit Transform(State * state) : Object<b2Transform>(state){
			LUTOK_METHOD("identity", &Transform::identity);
			LUTOK_METHOD("set", &Transform::set);
		}

		b2Transform * constructor(State & state){
			b2Transform * obj = nullptr;
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["Vec2"]);
			Rot * interfaceRot = dynamic_cast<Rot*>(state.interfaces["Rot"]);

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
		void destructor(State & state, b2Transform * object){
			delete object;
		}

		int identity(State & state, b2Transform * object){
			object->SetIdentity();
			return 0;
		}

		int set(State & state, b2Transform * object){
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["Vec2"]);
			b2Vec2 * position = interfaceVec2->get(1);
			if (position != nullptr && state.stack->is<LUA_TNUMBER>(2)){
				object->Set(*position, static_cast<float32>(state.stack->to<LUA_NUMBER>(2)));
			}
			return 0;
		}
	};

	void initTransform(State *);
};

#endif