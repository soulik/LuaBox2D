#ifndef LUABOX2D_CONTACTFILTER_H
#define LUABOX2D_CONTACTFILTER_H

namespace LuaBox2D {
	class LuaBox2DContactFilter : public b2ContactFilter {
	private:
		State * state;
	public:
		LuaBox2DContactFilter(State * state) : b2ContactFilter(){
			this->state = state;
			refShouldCollide = LUA_NOREF;
		}
		~LuaBox2DContactFilter();

		bool ShouldCollide(b2Fixture* fixtureA, b2Fixture* fixtureB);

		bool getCallBack(int ref);

		int refShouldCollide;

	};

	class ContactFilter : public Object<LuaBox2DContactFilter> {
	public:
		explicit ContactFilter(State * state) : Object<LuaBox2DContactFilter>(state){
			LUTOK_PROPERTY("shouldCollide", &ContactFilter::getShouldCollide, &ContactFilter::setShouldCollide);
		}

		LuaBox2DContactFilter * constructor(State & state, bool & managed);

		void destructor(State & state, LuaBox2DContactFilter * object);

		int getShouldCollide(State & state, LuaBox2DContactFilter * object);

		int setShouldCollide(State & state, LuaBox2DContactFilter * object);
	};

	void initContactFilter(State * );
};

#endif	
