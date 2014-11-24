#ifndef LUABOX2D_EDGESHAPE_H
#define LUABOX2D_EDGESHAPE_H

namespace LuaBox2D {
	class EdgeShape : public Object<b2EdgeShape> {
	private:
		Shape * base;
	public:
		explicit EdgeShape(State * state) : Object<b2EdgeShape>(state){
			base = state->getInterface<Shape>("LuaBox2D_Shape");
			LUTOK_PROPERTY("type", &EdgeShape::getType, &EdgeShape::nullMethod);
			LUTOK_PROPERTY("radius", &EdgeShape::getRadius, &EdgeShape::setRadius);
			LUTOK_METHOD("testPoint", &EdgeShape::testPoint);
			LUTOK_METHOD("rayCast", &EdgeShape::rayCast);
			LUTOK_METHOD("computeAABB", &EdgeShape::computeAABB);
			LUTOK_METHOD("computeMass", &EdgeShape::computeMass);

			LUTOK_METHOD("set", &EdgeShape::set);
			LUTOK_PROPERTY("vertex0", &EdgeShape::getVertex0, &EdgeShape::setVertex0);
			LUTOK_PROPERTY("vertex1", &EdgeShape::getVertex1, &EdgeShape::setVertex1);
			LUTOK_PROPERTY("vertex2", &EdgeShape::getVertex2, &EdgeShape::setVertex2);
			LUTOK_PROPERTY("vertex3", &EdgeShape::getVertex3, &EdgeShape::setVertex3);

			LUTOK_PROPERTY("hasVertex0", &EdgeShape::getHasVertex0, &EdgeShape::setHasVertex0);
			LUTOK_PROPERTY("hasVertex3", &EdgeShape::getHasVertex3, &EdgeShape::setHasVertex3);
		}

		b2EdgeShape * constructor(State & state, bool & managed);

		void destructor(State & state, b2EdgeShape * object);

		int getType(State & state, b2EdgeShape * object);

		int getRadius(State & state, b2EdgeShape * object);

		int setRadius(State & state, b2EdgeShape * object);

		int testPoint(State & state, b2EdgeShape * object);

		int rayCast(State & state, b2EdgeShape * object);

		int computeAABB(State & state, b2EdgeShape * object);

		int computeMass(State & state, b2EdgeShape * object);

		int operator_len(State & state, b2EdgeShape * object);

		int set(State & state, b2EdgeShape * object);

		int getVertex0(State & state, b2EdgeShape * object);

		int setVertex0(State & state, b2EdgeShape * object);

		int getVertex1(State & state, b2EdgeShape * object);

		int setVertex1(State & state, b2EdgeShape * object);

		int getVertex2(State & state, b2EdgeShape * object);

		int setVertex2(State & state, b2EdgeShape * object);

		int getVertex3(State & state, b2EdgeShape * object);

		int setVertex3(State & state, b2EdgeShape * object);

		int getHasVertex0(State & state, b2EdgeShape * object);

		int setHasVertex0(State & state, b2EdgeShape * object);

		int getHasVertex3(State & state, b2EdgeShape * object);

		int setHasVertex3(State & state, b2EdgeShape * object);
	};

	void initEdgeShape(State * );
};

#endif	
