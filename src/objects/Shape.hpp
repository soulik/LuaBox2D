#ifndef LUABOX2D_SHAPE_H
#define LUABOX2D_SHAPE_H

#include "objects/Vec2.hpp"

namespace LuaBox2D {
	class Shape : public Object<b2Shape> {
	public:
		explicit Shape(State * state) : Object<b2Shape>(state){
		}

		b2Shape * constructor(State & state){
			b2Shape * obj = nullptr;
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);

			//obj = new b2Shape();

			return obj;
		}
		void destructor(State & state, b2Shape * object){
			delete object;
		}
	};

	void initShape(State * );

};

#endif