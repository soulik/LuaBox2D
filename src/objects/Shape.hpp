#ifndef LUABOX2D_SHAPE_H
#define LUABOX2D_SHAPE_H

namespace LuaBox2D {
	class Shape : public Object<b2Shape> {
	protected:
		std::forward_list<std::string> validTypes;
	public:
		explicit Shape(State * state) : Object<b2Shape>(state){
			LUTOK_PROPERTY("type", &Shape::getType, &Shape::nullMethod);
			LUTOK_PROPERTY("radius", &Shape::getRadius, &Shape::setRadius);

			LUTOK_METHOD("testPoint", &Shape::testPoint);
			LUTOK_METHOD("rayCast", &Shape::rayCast);
			LUTOK_METHOD("computeAABB", &Shape::computeAABB);
			LUTOK_METHOD("computeMass", &Shape::computeMass);

			initAllowedTypes();
		}

		void initAllowedTypes();

		b2Shape * constructor(State & state, bool & managed);

		void destructor(State & state, b2Shape * object);

		b2Shape * get(const int index);

		int getType(State & state, b2Shape * object);

		int getRadius(State & state, b2Shape * object);

		int setRadius(State & state, b2Shape * object);

		int operator_len(State & state, b2Shape * object);

		int testPoint(State & state, b2Shape * object);

		int rayCast(State & state, b2Shape * object);

		int computeAABB(State & state, b2Shape * object);

		int computeMass(State & state, b2Shape * object);
	};

	void initShape(State * );

};

#endif