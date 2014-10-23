#ifndef LUABOX2D_POLYGONSHAPE_H
#define LUABOX2D_POLYGONSHAPE_H

#include "objects/Shape.hpp"
#include "objects/VertexArray.hpp"
#include "objects/Vec2.hpp"

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

		b2PolygonShape * constructor(State & state){
			Shape * interfaceShape = state.getInterface<Shape>("LuaBox2D_Shape");
			b2Shape * shape = interfaceShape->get(1);
			if (shape != nullptr){
				if (shape->GetType() == b2Shape::e_polygon){
					return new b2PolygonShape(*dynamic_cast<b2PolygonShape*>(shape));
				}else{
					return new b2PolygonShape();
				}
			}else{
				return new b2PolygonShape();
			}
		}

		void destructor(State & state, b2PolygonShape * object){
			delete object;
		}

		inline int getType(State & state, b2PolygonShape * object){
			return base->getType(state, object);
		}

		inline int getRadius(State & state, b2PolygonShape * object){
			return base->getRadius(state, object);
		}

		inline int setRadius(State & state, b2PolygonShape * object){
			return base->setRadius(state, object);
		}

		inline int testPoint(State & state, b2PolygonShape * object){
			return base->testPoint(state, object);
		}

		inline int rayCast(State & state, b2PolygonShape * object){
			return base->rayCast(state, object);
		}

		inline int computeAABB(State & state, b2PolygonShape * object){
			return base->computeAABB(state, object);
		}

		inline int computeMass(State & state, b2PolygonShape * object){
			return base->computeMass(state, object);
		}

		int operator_len(State & state, b2PolygonShape * object){
			state.stack->push<int>(static_cast<int>(object->GetChildCount()));
			return 1;
		}

		inline int set(State & state, b2PolygonShape * object){
			VertexArray * interfaceVA = state.getInterface<VertexArray>("LuaBox2D_VertexArray");
			b2VertexArray * va = interfaceVA->get(1);
			if (va != nullptr){
				object->Set(va->data(), va->size());
			}else{
				if (state.stack->is<LUA_TTABLE>(1)){
					va = interfaceVA->constructor(state, 1);
					object->Set(va->data(), va->size());
					delete va;
				}
			}
			return 0;
		}

		int setAsBox(State & state, b2PolygonShape * object){
			Stack * stack = state.stack;
			if (stack->is<LUA_TNUMBER>(1) && stack->is<LUA_TNUMBER>(2)){
				object->SetAsBox(
					static_cast<float32>(stack->to<LUA_NUMBER>(1)),
					static_cast<float32>(stack->to<LUA_NUMBER>(2))
					);
			}
			return 0;
		}

		int getVertexCount(State & state, b2PolygonShape * object){
			state.stack->push<int>(
				static_cast<int>(object->GetVertexCount())
				);
			return 1;
		}

		int getVertex(State & state, b2PolygonShape * object){
			Stack * stack = state.stack;
			if (stack->is<LUA_TNUMBER>(1)){
				Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
				
				interfaceVec2->push(new b2Vec2(object->GetVertex(
					static_cast<int32>(stack->to<int>(1)-1)
					)), true);
				return 1;
			}
			return 0;
		}

		int validate(State & state, b2PolygonShape * object){
			state.stack->push<bool>(object->Validate());
			return 1;
		}
	};

	void initPolygonShape(State * );
};

#endif	
