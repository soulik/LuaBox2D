#ifndef LUABOX2D_RAYCASTOUTPUT_H
#define LUABOX2D_RAYCASTOUTPUT_H

namespace LuaBox2D {
	class RayCastOutput : public Object<b2RayCastOutput> {
	public:
		explicit RayCastOutput(State * state) : Object<b2RayCastOutput>(state){
			LUTOK_PROPERTY("normal", &RayCastOutput::getNormal, &RayCastOutput::setNormal);
			LUTOK_PROPERTY("fraction", &RayCastOutput::getFraction, &RayCastOutput::setFraction);
		}

		b2RayCastOutput * constructor(State & state, bool & managed);

		void destructor(State & state, b2RayCastOutput * object);

		int getNormal(State & state, b2RayCastOutput * object);

		int setNormal(State & state, b2RayCastOutput * object);

		int getFraction(State & state, b2RayCastOutput * object);

		int setFraction(State & state, b2RayCastOutput * object);
	};

	void initRayCastOutput(State * );
};

#endif	
