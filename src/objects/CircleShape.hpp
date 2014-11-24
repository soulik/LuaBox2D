#ifndef LUABOX2D_CIRCLESHAPE_H
#define LUABOX2D_CIRCLESHAPE_H

namespace LuaBox2D {
	class CircleShape : public Object<b2CircleShape> {
	private:
		Shape * base;
	public:
		explicit CircleShape(State * state) : Object<b2CircleShape>(state){
			base = state->getInterface<Shape>("LuaBox2D_Shape");
			LUTOK_PROPERTY("type", &CircleShape::getType, &CircleShape::nullMethod);
			LUTOK_PROPERTY("radius", &CircleShape::getRadius, &CircleShape::setRadius);
			LUTOK_PROPERTY("m_p", &CircleShape::getMP, &CircleShape::setMP);
			LUTOK_METHOD("testPoint", &CircleShape::testPoint);
			LUTOK_METHOD("rayCast", &CircleShape::rayCast);
			LUTOK_METHOD("computeAABB", &CircleShape::computeAABB);
			LUTOK_METHOD("computeMass", &CircleShape::computeMass);
			
			LUTOK_METHOD("support", &CircleShape::support);
			LUTOK_METHOD("supportVertex", &CircleShape::supportVertex);
			LUTOK_METHOD("vertex", &CircleShape::vertex);
			LUTOK_METHOD("vertexCount", &CircleShape::vertex);
		}

		b2CircleShape * constructor(State & state, bool & managed);

		void destructor(State & state, b2CircleShape * object);
		
		int getType(State & state, b2CircleShape * object);

		int getRadius(State & state, b2CircleShape * object);

		int setRadius(State & state, b2CircleShape * object);

		int testPoint(State & state, b2CircleShape * object);

		int rayCast(State & state, b2CircleShape * object);

		int computeAABB(State & state, b2CircleShape * object);

		int computeMass(State & state, b2CircleShape * object);
		
		int getMP(State & state, b2CircleShape * object);

		int setMP(State & state, b2CircleShape * object);

		int operator_len(State & state, b2CircleShape * object);

		int support(State & state, b2CircleShape * object);

		int supportVertex(State & state, b2CircleShape * object);

		int vertex(State & state, b2CircleShape * object);

		int vertexCount(State & state, b2CircleShape * object);
	};

	void initCircleShape(State * );
};

#endif	
