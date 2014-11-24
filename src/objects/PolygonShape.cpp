#include "common.hpp"
#include "objects/Shape.hpp"
#include "objects/VertexArray.hpp"
#include "objects/Vec2.hpp"
#include "objects/PolygonShape.hpp"

namespace LuaBox2D {
	void initPolygonShape(State * state){
		state->registerInterface<PolygonShape>("LuaBox2D_PolygonShape");
	}

	b2PolygonShape * PolygonShape::constructor(State & state, bool & managed){
		Shape * interfaceShape = state.getInterface<Shape>("LuaBox2D_Shape");
		b2Shape * shape = interfaceShape->get(1);
		if (shape != nullptr){
			if (shape->GetType() == b2Shape::e_polygon){
				managed = false;
				return dynamic_cast<b2PolygonShape*>(shape);
			}else{
				return new b2PolygonShape();
			}
		}else{
			if (state.stack->is<LUA_TNUMBER>(1) && state.stack->is<LUA_TNUMBER>(2)){
				if (state.stack->is<LUA_TUSERDATA>(3) && state.stack->is<LUA_TNUMBER>(4)){
					Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
					b2Vec2 * center = interfaceVec2->get(3);
					if (center != nullptr){
						b2PolygonShape * object = new b2PolygonShape();
						object->SetAsBox(
							static_cast<float32>(state.stack->to<LUA_NUMBER>(1)),
							static_cast<float32>(state.stack->to<LUA_NUMBER>(2)),
							*center,
							static_cast<float32>(state.stack->to<LUA_NUMBER>(4))
							);
						return object;
					}else{
						return nullptr;
					}
				}else{
					b2PolygonShape * object = new b2PolygonShape();
					object->SetAsBox(
						static_cast<float32>(state.stack->to<LUA_NUMBER>(1)),
						static_cast<float32>(state.stack->to<LUA_NUMBER>(2))
						);
					return object;
				}
			}else{
				return new b2PolygonShape();
			}
		}
	}

	void PolygonShape::destructor(State & state, b2PolygonShape * object){
		delete object;
	}

	inline int PolygonShape::getType(State & state, b2PolygonShape * object){
		return base->getType(state, object);
	}

	inline int PolygonShape::getRadius(State & state, b2PolygonShape * object){
		return base->getRadius(state, object);
	}

	inline int PolygonShape::setRadius(State & state, b2PolygonShape * object){
		return base->setRadius(state, object);
	}

	inline int PolygonShape::testPoint(State & state, b2PolygonShape * object){
		return base->testPoint(state, object);
	}

	inline int PolygonShape::rayCast(State & state, b2PolygonShape * object){
		return base->rayCast(state, object);
	}

	inline int PolygonShape::computeAABB(State & state, b2PolygonShape * object){
		return base->computeAABB(state, object);
	}

	inline int PolygonShape::computeMass(State & state, b2PolygonShape * object){
		return base->computeMass(state, object);
	}

	int PolygonShape::operator_len(State & state, b2PolygonShape * object){
		state.stack->push<int>(static_cast<int>(object->GetChildCount()));
		return 1;
	}

	inline int PolygonShape::set(State & state, b2PolygonShape * object){
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

	int PolygonShape::setAsBox(State & state, b2PolygonShape * object){
		Stack * stack = state.stack;
		if (stack->is<LUA_TNUMBER>(1) && stack->is<LUA_TNUMBER>(2)){
			object->SetAsBox(
				static_cast<float32>(stack->to<LUA_NUMBER>(1)),
				static_cast<float32>(stack->to<LUA_NUMBER>(2))
				);
		}
		return 0;
	}

	int PolygonShape::getVertexCount(State & state, b2PolygonShape * object){
		state.stack->push<int>(
			static_cast<int>(object->GetVertexCount())
			);
		return 1;
	}

	int PolygonShape::getVertex(State & state, b2PolygonShape * object){
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

	int PolygonShape::validate(State & state, b2PolygonShape * object){
		state.stack->push<bool>(object->Validate());
		return 1;
	}
};
