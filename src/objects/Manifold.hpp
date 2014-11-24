#ifndef LUABOX2D_MANIFOLD_H
#define LUABOX2D_MANIFOLD_H

namespace LuaBox2D {
	class Manifold : public Object<b2Manifold> {
	public:
		explicit Manifold(State * state) : Object<b2Manifold>(state){
			LUTOK_PROPERTY("localNormal", &Manifold::getLocalNormal, &Manifold::setLocalNormal);
			LUTOK_PROPERTY("localPoint", &Manifold::getLocalPoint, &Manifold::setLocalPoint);
			LUTOK_PROPERTY("type", &Manifold::getType, &Manifold::setType);
		}

		b2Manifold * constructor(State & state, bool & managed);

		void destructor(State & state, b2Manifold * object);

		int operator_len(State & state, b2Manifold * object);

		int getLocalNormal(State & state, b2Manifold * object);

		int setLocalNormal(State & state, b2Manifold * object);

		int getLocalPoint(State & state, b2Manifold * object);

		int setLocalPoint(State & state, b2Manifold * object);

		int getType(State & state, b2Manifold * object);

		int setType(State & state, b2Manifold * object);

		int operator_getArray(State & state, b2Manifold * object);

		void operator_setArray(State & state, b2Manifold * object);
	};

	void initManifold(State * );
};

#endif	
