#ifndef LUABOX2D_TIMER_H
#define LUABOX2D_TIMER_H

namespace LuaBox2D {
	class Timer : public Object<b2Timer> {
	public:
		explicit Timer(State * state) : Object<b2Timer>(state){
			LUTOK_PROPERTY("ms", &Timer::getMiliseconds, &Timer::nullMethod);

			LUTOK_METHOD("reset", &Timer::reset);
		}

		b2Timer * constructor(State & state){
			b2Timer * obj = nullptr;
			obj = new b2Timer();
			return obj;
		}
		void destructor(State & state, b2Timer * object){
			delete object;
		}

		int getMiliseconds(State & state, b2Timer * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetMilliseconds()));
			return 1;
		}

		int reset(State & state, b2Timer * object){
			object->Reset();
			return 0;
		}
	};

	void initTimer(State *);
};

#endif