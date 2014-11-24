#ifndef LUABOX2D_AABB_H
#define LUABOX2D_AABB_H

namespace LuaBox2D {
	class AABB : public Object<b2AABB> {
	public:
		explicit AABB(State * state) : Object<b2AABB>(state){
			LUTOK_PROPERTY("lowerBound", &AABB::getLowerBound, &AABB::setLowerBound);
			LUTOK_PROPERTY("upperBound", &AABB::getLowerBound, &AABB::setLowerBound);
			LUTOK_PROPERTY("valid", &AABB::getValid, &AABB::nullMethod);

			LUTOK_PROPERTY("center", &AABB::getCenter, &AABB::nullMethod);
			LUTOK_PROPERTY("extens", &AABB::getExtens, &AABB::nullMethod);
			LUTOK_PROPERTY("perimeter", &AABB::getPerimeter, &AABB::nullMethod);

			LUTOK_METHOD("combine", &AABB::combine);
			LUTOK_METHOD("contains", &AABB::contains);
		}

		b2AABB * constructor(State & state, bool & managed);

		void destructor(State & state, b2AABB * object);

		int getLowerBound(State & state, b2AABB * object);

		int setLowerBound(State & state, b2AABB * object);

		int getUpperBound(State & state, b2AABB * object);

		int setUpperBound(State & state, b2AABB * object);

		int getValid(State & state, b2AABB * object);

		int getCenter(State & state, b2AABB * object);

		int getExtens(State & state, b2AABB * object);

		int getPerimeter(State & state, b2AABB * object);

		int operator_add(State & state, b2AABB * a, b2AABB * b);

		int combine(State & state, b2AABB * object);

		int contains(State & state, b2AABB * object);

		int rayCast(State & state, b2AABB * object);

	};

	void initAABB(State * );
};

#endif	
