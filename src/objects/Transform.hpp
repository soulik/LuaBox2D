#ifndef LUABOX2D_TRANSFORM_H
#define LUABOX2D_TRANSFORM_H

namespace LuaBox2D {
	class Transform : public Object<b2Transform> {
	public:
		explicit Transform(State * state) : Object<b2Transform>(state){
			LUTOK_METHOD("identity", &Transform::identity);
			LUTOK_METHOD("set", &Transform::set);
		}

		b2Transform * constructor(State & state);

		void destructor(State & state, b2Transform * object);

		int identity(State & state, b2Transform * object);

		int set(State & state, b2Transform * object);
	};

	void initTransform(State *);
};

#endif