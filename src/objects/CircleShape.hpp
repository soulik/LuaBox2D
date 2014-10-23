#ifndef LUABOX2D_CIRCLESHAPE_H
#define LUABOX2D_CIRCLESHAPE_H

#include "objects/Vec2.hpp"
#include "objects/Shape.hpp"

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

		b2CircleShape * constructor(State & state){
			Shape * interfaceShape = state.getInterface<Shape>("LuaBox2D_Shape");
			b2Shape * shape = interfaceShape->get(1);
			if (shape != nullptr){
				if (shape->GetType() == b2Shape::e_circle){
					return new b2CircleShape(*dynamic_cast<b2CircleShape*>(shape));
				}else{
					return new b2CircleShape();
				}
			}else{
				return new b2CircleShape();
			}
		}

		void destructor(State & state, b2CircleShape * object){
			delete object;
		}
		
		inline int getType(State & state, b2CircleShape * object){
			return base->getType(state, object);
		}

		inline int getRadius(State & state, b2CircleShape * object){
			return base->getRadius(state, object);
		}

		inline int setRadius(State & state, b2CircleShape * object){
			return base->setRadius(state, object);
		}

		inline int testPoint(State & state, b2CircleShape * object){
			return base->testPoint(state, object);
		}

		inline int rayCast(State & state, b2CircleShape * object){
			return base->rayCast(state, object);
		}

		inline int computeAABB(State & state, b2CircleShape * object){
			return base->computeAABB(state, object);
		}

		inline int computeMass(State & state, b2CircleShape * object){
			return base->computeMass(state, object);
		}
		
		int getMP(State & state, b2CircleShape * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			interfaceVec2->push(&object->m_p, false);
			return 1;
		}

		int setMP(State & state, b2CircleShape * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			b2Vec2 * m_p = interfaceVec2->get(1);
			if (m_p != nullptr){
				object->m_p = *m_p;
			}
			return 0;
		}

		int operator_len(State & state, b2CircleShape * object){
			state.stack->push<int>(static_cast<int>(object->GetChildCount()));
			return 1;
		}

		int support(State & state, b2CircleShape * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			b2Vec2 * d = interfaceVec2->get(1);
			if (d != nullptr){
				int32 index = object->GetSupport(*d);
				state.stack->push<int>(static_cast<int>(index));
				return 1;
			}else{
				return 0;
			}
		}

		int supportVertex(State & state, b2CircleShape * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			b2Vec2 * d = interfaceVec2->get(1);
			if (d != nullptr){
				interfaceVec2->push(new b2Vec2(object->GetSupportVertex(*d)), true);
				return 1;
			}else{
				return 0;
			}
		}

		int vertex(State & state, b2CircleShape * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			if (state.stack->is<LUA_TNUMBER>(1)){
				interfaceVec2->push(new b2Vec2(object->GetVertex(static_cast<int32>(state.stack->to<LUA_NUMBER>(1)))), true);
				return 1;
			}else{
				return 0;
			}
		}

		int vertexCount(State & state, b2CircleShape * object){
			state.stack->push<int>(static_cast<int>(object->GetVertexCount()));
			return 1;
		}
	};

	void initCircleShape(State * );
};

#endif	
