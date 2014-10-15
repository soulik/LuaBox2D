#ifndef LUABOX2D_FIXTUREDEF_H
#define LUABOX2D_FIXTUREDEF_H

#include "objects/Vec2.hpp"

namespace LuaBox2D {
	class FixtureDef : public Object<b2FixtureDef> {
	public:
		explicit FixtureDef(State * state) : Object<b2FixtureDef>(state){
		}

		b2FixtureDef * constructor(State & state){
			b2FixtureDef * obj = nullptr;
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);

			obj = new b2FixtureDef();

			return obj;
		}
		void destructor(State & state, b2FixtureDef * object){
			delete object;
		}
	};

	void initFixtureDef(State * );

};

#endif