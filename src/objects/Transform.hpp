#ifndef LUABOX2D_TRANSFORM_H
#define LUABOX2D_TRANSFORM_H

namespace LuaBox2D {
	class Transform : public Object<b2Transform> {
	public:
		explicit Transform(State * state) : Object<b2Transform>(state){
			LUTOK_METHOD("identity", &Transform::identity);
			LUTOK_METHOD("set", &Transform::set);
			LUTOK_PROPERTY("p", &Transform::getP, &Transform::setP);
			LUTOK_PROPERTY("q", &Transform::getQ, &Transform::setQ);
		}

		b2Transform * constructor(State & state, bool & managed);

		void destructor(State & state, b2Transform * object);

		int identity(State & state, b2Transform * object);

		int set(State & state, b2Transform * object);

		int getP(State & state, b2Transform * object);

		int setP(State & state, b2Transform * object);

		int getQ(State & state, b2Transform * object);

		int setQ(State & state, b2Transform * object);

	};

	void initTransform(State *);
};

#endif