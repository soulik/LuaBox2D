#ifndef LUABOX2D_RAYCASTINPUT_H
#define LUABOX2D_RAYCASTINPUT_H

namespace LuaBox2D {
	class RayCastInput : public Object<b2RayCastInput> {
	public:
		explicit RayCastInput(State * state) : Object<b2RayCastInput>(state){
			LUTOK_PROPERTY("p1", &RayCastInput::getP1, &RayCastInput::setP1);
			LUTOK_PROPERTY("p2", &RayCastInput::getP2, &RayCastInput::setP2);
			LUTOK_PROPERTY("maxFraction", &RayCastInput::getMaxFraction, &RayCastInput::setMaxFraction);
		}

		b2RayCastInput * constructor(State & state, bool & managed);

		void destructor(State & state, b2RayCastInput * object);

		int getP1(State & state, b2RayCastInput * object);

		int setP1(State & state, b2RayCastInput * object);

		int getP2(State & state, b2RayCastInput * object);

		int setP2(State & state, b2RayCastInput * object);

		int getMaxFraction(State & state, b2RayCastInput * object);

		int setMaxFraction(State & state, b2RayCastInput * object);
	};

	void initRayCastInput(State * );
};

#endif	
