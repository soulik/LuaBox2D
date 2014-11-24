#ifndef LUABOX2D_ROT_H
#define LUABOX2D_ROT_H

namespace LuaBox2D {
	class Rot : public Object<b2Rot> {
	public:
		explicit Rot(State * state) : Object<b2Rot>(state){
			LUTOK_PROPERTY("x", &Rot::getXAxis, &Rot::nullMethod);
			LUTOK_PROPERTY("y", &Rot::getYAxis, &Rot::nullMethod);
			LUTOK_PROPERTY("angle", &Rot::getAngle, &Rot::setAngle);

			LUTOK_METHOD("identity", &Rot::identity);
		}

		b2Rot * constructor(State & state, bool & managed);

		void destructor(State & state, b2Rot * object);

		int getXAxis(State & state, b2Rot * object);

		int getYAxis(State & state, b2Rot * object);

		int getAngle(State & state, b2Rot * object);

		int setAngle(State & state, b2Rot * object);

		int identity(State & state, b2Rot * object);

	};

	void initRot(State *);
};

#endif