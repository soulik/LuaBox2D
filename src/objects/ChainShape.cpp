#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/VertexArray.hpp"
#include "objects/Shape.hpp"
#include "objects/EdgeShape.hpp"
#include "objects/ChainShape.hpp"

namespace LuaBox2D {
	void initChainShape(State * state){
		state->registerInterface<ChainShape>("LuaBox2D_ChainShape");
	}

	b2ChainShape * ChainShape::constructor(State & state, bool & managed){
		Shape * interfaceShape = state.getInterface<Shape>("LuaBox2D_Shape");
		b2Shape * shape = interfaceShape->get(1);
		if (shape != nullptr){
			if (shape->GetType() == b2Shape::e_chain){
				managed = false;
				return dynamic_cast<b2ChainShape*>(shape);
			}else{
				return new b2ChainShape();
			}
		}else{
			return new b2ChainShape();
		}
	}

	void ChainShape::destructor(State & state, b2ChainShape * object){
		delete object;
	}

	inline int ChainShape::getType(State & state, b2ChainShape * object){
		return base->getType(state, object);
	}

	inline int ChainShape::getRadius(State & state, b2ChainShape * object){
		return base->getRadius(state, object);
	}

	inline int ChainShape::setRadius(State & state, b2ChainShape * object){
		return base->setRadius(state, object);
	}

	inline int ChainShape::testPoint(State & state, b2ChainShape * object){
		return base->testPoint(state, object);
	}

	inline int ChainShape::rayCast(State & state, b2ChainShape * object){
		return base->rayCast(state, object);
	}

	inline int ChainShape::computeAABB(State & state, b2ChainShape * object){
		return base->computeAABB(state, object);
	}

	inline int ChainShape::computeMass(State & state, b2ChainShape * object){
		return base->computeMass(state, object);
	}

	int ChainShape::operator_len(State & state, b2ChainShape * object){
		state.stack->push<int>(static_cast<int>(object->GetChildCount()));
		return 1;
	}

	int ChainShape::getChildEdge(State & state, b2ChainShape * object){
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

	int ChainShape::createLoop(State & state, b2ChainShape * object){
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

	int ChainShape::createChain(State & state, b2ChainShape * object){
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

	int ChainShape::setPrevVertex(State & state, b2ChainShape * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * vertex = interfaceVec2->get(1);
		if (vertex != nullptr){
			object->SetPrevVertex(*vertex);
		}
		return 0;
	}

	int ChainShape::setNextVertex(State & state, b2ChainShape * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * vertex = interfaceVec2->get(1);
		if (vertex != nullptr){
			object->SetNextVertex(*vertex);
		}
		return 0;
	}
};
