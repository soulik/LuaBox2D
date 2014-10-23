#ifndef LUABOX2D_CHAINSHAPE_H
#define LUABOX2D_CHAINSHAPE_H

#include "objects/VertexArray.hpp"
#include "objects/Shape.hpp"
#include "objects/EdgeShape.hpp"

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

		b2ChainShape * constructor(State & state){
			Shape * interfaceShape = state.getInterface<Shape>("LuaBox2D_Shape");
			b2Shape * shape = interfaceShape->get(1);
			if (shape != nullptr){
				if (shape->GetType() == b2Shape::e_chain){
					return new b2ChainShape(*dynamic_cast<b2ChainShape*>(shape));
				}else{
					return new b2ChainShape();
				}
			}else{
				return new b2ChainShape();
			}
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

		int operator_len(State & state, b2ChainShape * object){
			state.stack->push<int>(static_cast<int>(object->GetChildCount()));
			return 1;
		}

		int getChildEdge(State & state, b2ChainShape * object){
			if (state.stack->is<LUA_TNUMBER>(1)){
				EdgeShape * interfaceEdgeShape = state.getInterface<EdgeShape>("LuaBox2D_EdgeShape");
				b2EdgeShape * es = new b2EdgeShape();
				object->GetChildEdge(es, static_cast<int32>(state.stack->to<int>(1)));
				interfaceEdgeShape->push(es, true);
				return 1;
			}else{
				return 0;
			}
		}

		inline int createLoop(State & state, b2ChainShape * object){
			VertexArray * interfaceVA = state.getInterface<VertexArray>("LuaBox2D_VertexArray");
			b2VertexArray * va = interfaceVA->get(1);
			if (va != nullptr){
				object->CreateLoop(va->data(), va->size());
			}else{
				if (state.stack->is<LUA_TTABLE>(1)){
					va = interfaceVA->constructor(state, 1);
					object->CreateLoop(va->data(), va->size());
					delete va;
				}
			}
			return 0;
		}

		inline int createChain(State & state, b2ChainShape * object){
			VertexArray * interfaceVA = state.getInterface<VertexArray>("LuaBox2D_VertexArray");
			b2VertexArray * va = interfaceVA->get(1);
			if (va != nullptr){
				object->CreateChain(va->data(), va->size());
			}else{
				if (state.stack->is<LUA_TTABLE>(1)){
					va = interfaceVA->constructor(state, 1);
					object->CreateChain(va->data(), va->size());
					delete va;
				}
			}
			return 0;
		}

		int setPrevVertex(State & state, b2ChainShape * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			b2Vec2 * vertex = interfaceVec2->get(1);
			if (vertex != nullptr){
				object->SetPrevVertex(*vertex);
			}
			return 0;
		}

		int setNextVertex(State & state, b2ChainShape * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			b2Vec2 * vertex = interfaceVec2->get(1);
			if (vertex != nullptr){
				object->SetNextVertex(*vertex);
			}
			return 0;
		}
	};

	void initChainShape(State * );
};

#endif	
