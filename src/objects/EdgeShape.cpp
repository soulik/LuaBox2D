#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Shape.hpp"
#include "objects/EdgeShape.hpp"

namespace LuaBox2D {
	void initEdgeShape(State * state){
		state->registerInterface<EdgeShape>("LuaBox2D_EdgeShape");
	}

	b2EdgeShape * EdgeShape::constructor(State & state, bool & managed){
		Shape * interfaceShape = state.getInterface<Shape>("LuaBox2D_Shape");
		b2Shape * shape = interfaceShape->get(1);
		if (shape != nullptr){
			if (shape->GetType() == b2Shape::e_edge){
				managed = false;
				return dynamic_cast<b2EdgeShape*>(shape);
			}else{
				return new b2EdgeShape();
			}
		}else{
			if (state.stack->is<LUA_TUSERDATA>(1) && state.stack->is<LUA_TUSERDATA>(2)){
				Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
				b2Vec2 * v1 = interfaceVec2->get(1);
				b2Vec2 * v2 = interfaceVec2->get(2);
				if (v1 != nullptr && v2 != nullptr){
					b2EdgeShape * object = new b2EdgeShape();
					object->Set(*v1, *v2);
					return object;
				}else{
					return nullptr;
				}
			}else{
				return new b2EdgeShape();
			}
		}
	}

	void EdgeShape::destructor(State & state, b2EdgeShape * object){
		delete object;
	}

	inline int EdgeShape::getType(State & state, b2EdgeShape * object){
		return base->getType(state, object);
	}

	inline int EdgeShape::getRadius(State & state, b2EdgeShape * object){
		return base->getRadius(state, object);
	}

	inline int EdgeShape::setRadius(State & state, b2EdgeShape * object){
		return base->setRadius(state, object);
	}

	inline int EdgeShape::testPoint(State & state, b2EdgeShape * object){
		return base->testPoint(state, object);
	}

	inline int EdgeShape::rayCast(State & state, b2EdgeShape * object){
		return base->rayCast(state, object);
	}

	inline int EdgeShape::computeAABB(State & state, b2EdgeShape * object){
		return base->computeAABB(state, object);
	}

	inline int EdgeShape::computeMass(State & state, b2EdgeShape * object){
		return base->computeMass(state, object);
	}

	int EdgeShape::operator_len(State & state, b2EdgeShape * object){
		state.stack->push<int>(static_cast<int>(object->GetChildCount()));
		return 1;
	}

	int EdgeShape::set(State & state, b2EdgeShape * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * v1 = interfaceVec2->get(1);
		b2Vec2 * v2 = interfaceVec2->get(2);
		if (v1 != nullptr && v2 != nullptr){
			object->Set(*v1, *v2);
		}
		return 0;
	}

	int EdgeShape::getVertex0(State & state, b2EdgeShape * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->m_vertex0, false);
		return 1;
	}

	int EdgeShape::setVertex0(State & state, b2EdgeShape * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * vertex = interfaceVec2->get(1);
		if (vertex != nullptr){
			object->m_vertex0 = *vertex;
		}
		return 0;
	}

	int EdgeShape::getVertex1(State & state, b2EdgeShape * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->m_vertex1, false);
		return 1;
	}

	int EdgeShape::setVertex1(State & state, b2EdgeShape * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * vertex = interfaceVec2->get(1);
		if (vertex != nullptr){
			object->m_vertex1 = *vertex;
		}
		return 0;
	}

	int EdgeShape::getVertex2(State & state, b2EdgeShape * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->m_vertex2, false);
		return 1;
	}

	int EdgeShape::setVertex2(State & state, b2EdgeShape * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * vertex = interfaceVec2->get(1);
		if (vertex != nullptr){
			object->m_vertex2 = *vertex;
		}
		return 0;
	}

	int EdgeShape::getVertex3(State & state, b2EdgeShape * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->m_vertex3, false);
		return 1;
	}

	int EdgeShape::setVertex3(State & state, b2EdgeShape * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * vertex = interfaceVec2->get(1);
		if (vertex != nullptr){
			object->m_vertex3 = *vertex;
		}
		return 0;
	}

	int EdgeShape::getHasVertex0(State & state, b2EdgeShape * object){
		state.stack->push<bool>(object->m_hasVertex0);
		return 1;
	}

	int EdgeShape::setHasVertex0(State & state, b2EdgeShape * object){
		object->m_hasVertex0 = state.stack->to<bool>(1);
		return 0;
	}

	int EdgeShape::getHasVertex3(State & state, b2EdgeShape * object){
		state.stack->push<bool>(object->m_hasVertex0);
		return 1;
	}

	int EdgeShape::setHasVertex3(State & state, b2EdgeShape * object){
		object->m_hasVertex3 = state.stack->to<bool>(1);
		return 0;
	}
};
