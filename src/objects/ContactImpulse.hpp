#ifndef LUABOX2D_CONTACTIMPULSE_H
#define LUABOX2D_CONTACTIMPULSE_H

namespace LuaBox2D {
	class ContactImpulse : public Object<b2ContactImpulse> {
	public:
		explicit ContactImpulse(State * state) : Object<b2ContactImpulse>(state){
			LUTOK_METHOD("getNormalImpulse", &ContactImpulse::getNormalImpulse);
			LUTOK_METHOD("setNormalImpulse", &ContactImpulse::setNormalImpulse);
			LUTOK_METHOD("getTangentImpulse", &ContactImpulse::getTangentImpulse);
			LUTOK_METHOD("setTangentImpulse", &ContactImpulse::setTangentImpulse);
		}

		b2ContactImpulse * constructor(State & state, bool & managed);

		void destructor(State & state, b2ContactImpulse * object);

		int operator_len(State & state, b2ContactImpulse * object);

		int getNormalImpulse(State & state, b2ContactImpulse * object);

		int setNormalImpulse(State & state, b2ContactImpulse * object);

		int getTangentImpulse(State & state, b2ContactImpulse * object);

		int setTangentImpulse(State & state, b2ContactImpulse * object);
	};

	void initContactImpulse(State * );
};

#endif	
