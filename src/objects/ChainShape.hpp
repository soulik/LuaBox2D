#ifndef LUABOX2D_CHAINSHAPE_H
#define LUABOX2D_CHAINSHAPE_H

namespace LuaBox2D {
	class ChainShape : public Object<b2ChainShape> {
	private:
		Shape * base;
	public:
		explicit ChainShape(State * state) : Object<b2ChainShape>(state){
			base = state->getInterface<Shape>("LuaBox2D_Shape");
			LUTOK_PROPERTY("type", &ChainShape::getType, &ChainShape::nullMethod);
			LUTOK_METHOD("testPoint", &ChainShape::testPoint);
			LUTOK_METHOD("rayCast", &ChainShape::rayCast);
			LUTOK_METHOD("computeAABB", &ChainShape::computeAABB);
			LUTOK_METHOD("computeMass", &ChainShape::computeMass);

			LUTOK_METHOD("createLoop", &ChainShape::createLoop);
			LUTOK_METHOD("createChain", &ChainShape::createChain);
			LUTOK_METHOD("childEdge", &ChainShape::getChildEdge);
			LUTOK_METHOD("prevVertex", &ChainShape::setPrevVertex);
			LUTOK_METHOD("nextVertex", &ChainShape::setNextVertex);
		}

		b2ChainShape * constructor(State & state, bool & managed);

		void destructor(State & state, b2ChainShape * object);

		int getType(State & state, b2ChainShape * object);

		int getRadius(State & state, b2ChainShape * object);

		int setRadius(State & state, b2ChainShape * object);

		int testPoint(State & state, b2ChainShape * object);

		int rayCast(State & state, b2ChainShape * object);

		int computeAABB(State & state, b2ChainShape * object);

		int computeMass(State & state, b2ChainShape * object);

		int operator_len(State & state, b2ChainShape * object);

		int getChildEdge(State & state, b2ChainShape * object);

		int createLoop(State & state, b2ChainShape * object);

		int createChain(State & state, b2ChainShape * object);

		int setPrevVertex(State & state, b2ChainShape * object);

		int setNextVertex(State & state, b2ChainShape * object);
	};

	void initChainShape(State * );
};

#endif	
