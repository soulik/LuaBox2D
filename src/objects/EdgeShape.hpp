#ifndef LUABOX2D_EDGESHAPE_H
#define LUABOX2D_EDGESHAPE_H

#include "objects/Vec2.hpp"
#include "objects/Shape.hpp"

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

		b2EdgeShape * constructor(State & state){
			Shape * interfaceShape = state.getInterface<Shape>("LuaBox2D_Shape");
			b2Shape * shape = interfaceShape->get(1);
			if (shape != nullptr){
				if (shape->GetType() == b2Shape::e_edge){
					return new b2EdgeShape(*dynamic_cast<b2EdgeShape*>(shape));
				}else{
					return new b2EdgeShape();
				}
			}else{
				return new b2EdgeShape();
			}
		}

		void destructor(State & state, b2EdgeShape * object){
			delete object;
		}

		inline int getType(State & state, b2EdgeShape * object){
			return base->getType(state, object);
		}

		inline int getRadius(State & state, b2EdgeShape * object){
			return base->getRadius(state, object);
		}

		inline int setRadius(State & state, b2EdgeShape * object){
			return base->setRadius(state, object);
		}

		inline int testPoint(State & state, b2EdgeShape * object){
			return base->testPoint(state, object);
		}

		inline int rayCast(State & state, b2EdgeShape * object){
			return base->rayCast(state, object);
		}

		inline int computeAABB(State & state, b2EdgeShape * object){
			return base->computeAABB(state, object);
		}

		inline int computeMass(State & state, b2EdgeShape * object){
			return base->computeMass(state, object);
		}

		int operator_len(State & state, b2EdgeShape * object){
			state.stack->push<int>(static_cast<int>(object->GetChildCount()));
			return 1;
		}

		int set(State & state, b2EdgeShape * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			b2Vec2 * v1 = interfaceVec2->get(1);
			b2Vec2 * v2 = interfaceVec2->get(2);
			if (v1 != nullptr && v2 != nullptr){
				object->Set(*v1, *v2);
			}
			return 0;
		}

		int getVertex0(State & state, b2EdgeShape * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			interfaceVec2->push(&object->m_vertex0, false);
			return 1;
		}

		int setVertex0(State & state, b2EdgeShape * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			b2Vec2 * vertex = interfaceVec2->get(1);
			if (vertex != nullptr){
				object->m_vertex0 = *vertex;
			}
			return 0;
		}

		int getVertex1(State & state, b2EdgeShape * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			interfaceVec2->push(&object->m_vertex1, false);
			return 1;
		}

		int setVertex1(State & state, b2EdgeShape * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			b2Vec2 * vertex = interfaceVec2->get(1);
			if (vertex != nullptr){
				object->m_vertex1 = *vertex;
			}
			return 0;
		}

		int getVertex2(State & state, b2EdgeShape * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			interfaceVec2->push(&object->m_vertex2, false);
			return 1;
		}

		int setVertex2(State & state, b2EdgeShape * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			b2Vec2 * vertex = interfaceVec2->get(1);
			if (vertex != nullptr){
				object->m_vertex2 = *vertex;
			}
			return 0;
		}

		int getVertex3(State & state, b2EdgeShape * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			interfaceVec2->push(&object->m_vertex3, false);
			return 1;
		}

		int setVertex3(State & state, b2EdgeShape * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			b2Vec2 * vertex = interfaceVec2->get(1);
			if (vertex != nullptr){
				object->m_vertex3 = *vertex;
			}
			return 0;
		}

		int getHasVertex0(State & state, b2EdgeShape * object){
			state.stack->push<bool>(object->m_hasVertex0);
			return 1;
		}

		int setHasVertex0(State & state, b2EdgeShape * object){
			object->m_hasVertex0 = state.stack->to<bool>(1);
			return 0;
		}

		int getHasVertex3(State & state, b2EdgeShape * object){
			state.stack->push<bool>(object->m_hasVertex0);
			return 1;
		}

		int setHasVertex3(State & state, b2EdgeShape * object){
			object->m_hasVertex3 = state.stack->to<bool>(1);
			return 0;
		}
	};

	void initEdgeShape(State * );
};

#endif	
