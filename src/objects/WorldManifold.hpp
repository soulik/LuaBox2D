#ifndef LUABOX2D_WORLDMANIFOLD_H
#define LUABOX2D_WORLDMANIFOLD_H

namespace LuaBox2D {
	class WorldManifold : public Object<b2WorldManifold> {
	public:
		explicit WorldManifold(State * state) : Object<b2WorldManifold>(state){
			LUTOK_PROPERTY("normal", &WorldManifold::getNormal, &WorldManifold::setNormal);
			LUTOK_METHOD("initialize", &WorldManifold::initialize);
			LUTOK_METHOD("getSeparation", &WorldManifold::getSeparation);
			LUTOK_METHOD("setSeparation", &WorldManifold::setSeparation);
		}

		b2WorldManifold * constructor(State & state, bool & managed);

		void destructor(State & state, b2WorldManifold * object);

		int getNormal(State & state, b2WorldManifold * object);

		int setNormal(State & state, b2WorldManifold * object);

		int initialize(State & state, b2WorldManifold * object);

		int getSeparation(State & state, b2WorldManifold * object);

		int setSeparation(State & state, b2WorldManifold * object);

		int operator_getArray(State & state, b2WorldManifold * object);

		void operator_setArray(State & state, b2WorldManifold * object);
	};

	void initWorldManifold(State * );
};

#endif	
