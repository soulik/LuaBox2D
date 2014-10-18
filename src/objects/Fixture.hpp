#ifndef LUABOX2D_FIXTURE_H
#define LUABOX2D_FIXTURE_H

namespace LuaBox2D {
	class Fixture : public Object<b2Fixture> {
	public:
		explicit Fixture(State * state) : Object<b2Fixture>(state){
		}

		b2Fixture * constructor(State & state){
			return nullptr;
		}

		void destructor(State & state, b2Fixture * object){
			delete object;
		}
	};

	void initFixture(State * );
};

#endif