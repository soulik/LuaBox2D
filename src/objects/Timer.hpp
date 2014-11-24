#ifndef LUABOX2D_TIMER_H
#define LUABOX2D_TIMER_H

namespace LuaBox2D {
	class Timer : public Object<b2Timer> {
	public:
		explicit Timer(State * state) : Object<b2Timer>(state){
			LUTOK_PROPERTY("ms", &Timer::getMiliseconds, &Timer::nullMethod);

			LUTOK_METHOD("reset", &Timer::reset);
		}

		b2Timer * constructor(State & state, bool & managed);

		void destructor(State & state, b2Timer * object);

		int getMiliseconds(State & state, b2Timer * object);

		int reset(State & state, b2Timer * object);
	};

	void initTimer(State *);
};

#endif