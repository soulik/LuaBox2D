#ifndef LUABOX2D_SWEEP_H
#define LUABOX2D_SWEEP_H

namespace LuaBox2D {
	class Sweep : public Object<b2Sweep> {
	public:
		explicit Sweep(State * state) : Object<b2Sweep>(state){
			/*
			LUTOK_PROPERTY("x", &b2Sweep::getXAxis, &b2Sweep::nullMethod);
			LUTOK_PROPERTY("y", &b2Sweep::getYAxis, &b2Sweep::nullMethod);
			LUTOK_PROPERTY("angle", &b2Sweep::getAngle, &b2Sweep::setAngle);

			
			*/
			LUTOK_METHOD("transform", &Sweep::getTransform);
			LUTOK_METHOD("advance", &Sweep::advance);
			LUTOK_METHOD("normalize", &Sweep::normalize);
		}

		b2Sweep * constructor(State & state, bool & managed);

		void destructor(State & state, b2Sweep * object);

		int getTransform(State & state, b2Sweep * object);

		int advance(State & state, b2Sweep * object);

		int normalize(State & state, b2Sweep * object);
	};

	void initSweep(State *);
};

#endif
