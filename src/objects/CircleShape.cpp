#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Shape.hpp"
#include "objects/CircleShape.hpp"

namespace LuaBox2D {
	void initCircleShape(State * state){
		state->registerInterface<CircleShape>("LuaBox2D_CircleShape");
	}

	b2CircleShape * CircleShape::constructor(State & state, bool & managed){
		Shape * interfaceShape = state.getInterface<Shape>("LuaBox2D_Shape");
		b2Shape * shape = interfaceShape->get(1);
		if (shape != nullptr){
			if (shape->GetType() == b2Shape::e_circle){
				managed = false;
				return dynamic_cast<b2CircleShape*>(shape);
			}else{
				return new b2CircleShape();
			}
		}else{
			return new b2CircleShape();
		}
	}

	void CircleShape::destructor(State & state, b2CircleShape * object){
		delete object;
	}

	inline int CircleShape::getType(State & state, b2CircleShape * object){
		return base->getType(state, object);
	}

	inline int CircleShape::getRadius(State & state, b2CircleShape * object){
		return base->getRadius(state, object);
	}

	inline int CircleShape::setRadius(State & state, b2CircleShape * object){
		return base->setRadius(state, object);
	}

	inline int CircleShape::testPoint(State & state, b2CircleShape * object){
		return base->testPoint(state, object);
	}

	inline int CircleShape::rayCast(State & state, b2CircleShape * object){
		return base->rayCast(state, object);
	}

	inline int CircleShape::computeAABB(State & state, b2CircleShape * object){
		return base->computeAABB(state, object);
	}

	inline int CircleShape::computeMass(State & state, b2CircleShape * object){
		return base->computeMass(state, object);
	}

	int CircleShape::getMP(State & state, b2CircleShape * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->m_p, false);
		return 1;
	}

	int CircleShape::setMP(State & state, b2CircleShape * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * m_p = interfaceVec2->get(1);
		if (m_p != nullptr){
			object->m_p = *m_p;
		}
		return 0;
	}

	int CircleShape::operator_len(State & state, b2CircleShape * object){
		state.stack->push<int>(static_cast<int>(object->GetChildCount()));
		return 1;
	}

	int CircleShape::support(State & state, b2CircleShape * object){
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

	int CircleShape::supportVertex(State & state, b2CircleShape * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * d = interfaceVec2->get(1);
		if (d != nullptr){
			interfaceVec2->push(new b2Vec2(object->GetSupportVertex(*d)), true);
			return 1;
		}else{
			return 0;
		}
	}

	int CircleShape::vertex(State & state, b2CircleShape * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		if (state.stack->is<LUA_TNUMBER>(1)){
			interfaceVec2->push(new b2Vec2(object->GetVertex(static_cast<int32>(state.stack->to<LUA_NUMBER>(1)))), true);
			return 1;
		}else{
			return 0;
		}
	}

	int CircleShape::vertexCount(State & state, b2CircleShape * object){
		state.stack->push<int>(static_cast<int>(object->GetVertexCount()));
		return 1;
	}
};
