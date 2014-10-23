#ifndef LUABOX2D_CHAINSHAPE_H
#define LUABOX2D_CHAINSHAPE_H

#include "objects/VertexArray.hpp"
#include "objects/Shape.hpp"

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
		}

		b2ChainShape * constructor(State & state){
			return nullptr;
		}

		void destructor(State & state, b2ChainShape * object){
			delete object;
		}

		inline int getType(State & state, b2ChainShape * object){
			return base->getType(state, object);
		}

		inline int getRadius(State & state, b2ChainShape * object){
			return base->getRadius(state, object);
		}

		inline int setRadius(State & state, b2ChainShape * object){
			return base->setRadius(state, object);
		}

		inline int testPoint(State & state, b2ChainShape * object){
			return base->testPoint(state, object);
		}

		inline int rayCast(State & state, b2ChainShape * object){
			return base->rayCast(state, object);
		}

		inline int computeAABB(State & state, b2ChainShape * object){
			return base->computeAABB(state, object);
		}

		inline int computeMass(State & state, b2ChainShape * object){
			return base->computeMass(state, object);
		}
	};

	void initChainShape(State * );
};

#endif	
