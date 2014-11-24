#ifndef LUABOX2D_POLYGONSHAPE_H
#define LUABOX2D_POLYGONSHAPE_H

namespace LuaBox2D {
	class PolygonShape : public Object<b2PolygonShape> {
	private:
		Shape * base;
	public:
		explicit PolygonShape(State * state) : Object<b2PolygonShape>(state){
			base = state->getInterface<Shape>("LuaBox2D_Shape");
			LUTOK_PROPERTY("type", &PolygonShape::getType, &PolygonShape::nullMethod);
			LUTOK_METHOD("testPoint", &PolygonShape::testPoint);
			LUTOK_METHOD("rayCast", &PolygonShape::rayCast);
			LUTOK_METHOD("computeAABB", &PolygonShape::computeAABB);
			LUTOK_METHOD("computeMass", &PolygonShape::computeMass);

			LUTOK_METHOD("set", &PolygonShape::set);
			LUTOK_METHOD("setAsBox", &PolygonShape::setAsBox);
			LUTOK_PROPERTY("vertexCount", &PolygonShape::getVertexCount, &PolygonShape::nullMethod);
			LUTOK_METHOD("vertex", &PolygonShape::getVertex);
			LUTOK_METHOD("validate", &PolygonShape::validate);
		}

		b2PolygonShape * constructor(State & state, bool & managed);

		void destructor(State & state, b2PolygonShape * object);

		int getType(State & state, b2PolygonShape * object);

		int getRadius(State & state, b2PolygonShape * object);

		int setRadius(State & state, b2PolygonShape * object);

		int testPoint(State & state, b2PolygonShape * object);

		int rayCast(State & state, b2PolygonShape * object);

		int computeAABB(State & state, b2PolygonShape * object);

		int computeMass(State & state, b2PolygonShape * object);

		int operator_len(State & state, b2PolygonShape * object);

		int set(State & state, b2PolygonShape * object);

		int setAsBox(State & state, b2PolygonShape * object);

		int getVertexCount(State & state, b2PolygonShape * object);

		int getVertex(State & state, b2PolygonShape * object);

		int validate(State & state, b2PolygonShape * object);
	};

	void initPolygonShape(State * );
};

#endif	
