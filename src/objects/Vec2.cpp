#include "common.hpp"
#include "objects/Vec2.hpp"

namespace LuaBox2D {
	void initVec2(State * state){
		state->registerInterface<Vec2>("LuaBox2D_Vec2");
	}

	b2Vec2 * Vec2::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		b2Vec2 * obj = nullptr;
		Stack * stack = state.stack;
		if (stack->is<LUA_TNUMBER>(1) && stack->is<LUA_TNUMBER>(2)){
			obj = new b2Vec2(
				static_cast<float32>(stack->to<LUA_NUMBER>(1)),
				static_cast<float32>(stack->to<LUA_NUMBER>(2))
			);
		}else if (stack->is<LUA_TTABLE>(1)){
			stack->getField(1, 1);
			float32 x = static_cast<float32>(stack->to<LUA_NUMBER>());
			
			stack->getField(2, 1);
			float32 y = static_cast<float32>(stack->to<LUA_NUMBER>());
			stack->pop(2);
			obj = new b2Vec2(x, y);
		}else{
			obj = new b2Vec2();
		}

		return obj;
	}

	void Vec2::destructor(State & state, b2Vec2 * object){
		LUTOK2_NOT_USED(state);
		delete object;
	}

	int Vec2::getX(State & state, b2Vec2 * object){
		state.stack->push<LUA_NUMBER>(object->x);
		return 1;
	}

	int Vec2::setX(State & state, b2Vec2 * object){
		object->x = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int Vec2::getY(State & state, b2Vec2 * object){
		state.stack->push<LUA_NUMBER>(object->y);
		return 1;
	}

	int Vec2::setY(State & state, b2Vec2 * object){
		object->y = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int Vec2::zero(State & state, b2Vec2 * object){
		object->SetZero();
		return 0;
	}

	int Vec2::operator_add(State & state, b2Vec2 * a, b2Vec2 * b){
		Stack * stack = state.stack;
		if (a != nullptr && b!= nullptr){
			push(new b2Vec2((*a) + (*b)), true);
			return 1;
		}else if (stack->is<LUA_TNUMBER>(1) && b!=nullptr){
			b2Vec2 * tmp = new b2Vec2(*b);
			float32 value = static_cast<float32>(stack->to<LUA_NUMBER>(1));
			tmp->x += value;
			tmp->y += value;
			push(tmp, true);
			return 1;
		}else if (state.stack->is<LUA_TNUMBER>(2) && a!=nullptr){
			b2Vec2 * tmp = new b2Vec2(*a);
			float32 value = static_cast<float32>(stack->to<LUA_NUMBER>(2));
			tmp->x += value;
			tmp->y += value;
			push(tmp, true);
			return 1;
		}else{
			return 0;
		}
	}

	int Vec2::operator_sub(State & state, b2Vec2 * a, b2Vec2 * b){
		Stack * stack = state.stack;
		if (a != nullptr && b!= nullptr){
			push(new b2Vec2((*a) - (*b)), true);
			return 1;
		}else if (stack->is<LUA_TNUMBER>(1) && b!=nullptr){
			b2Vec2 * tmp = new b2Vec2(*b);
			float32 value = static_cast<float32>(stack->to<LUA_NUMBER>(1));
			tmp->x -= value;
			tmp->y -= value;
			push(tmp, true);
			return 1;
		}else if (state.stack->is<LUA_TNUMBER>(2) && a!=nullptr){
			b2Vec2 * tmp = new b2Vec2(*a);
			float32 value = static_cast<float32>(stack->to<LUA_NUMBER>(2));
			tmp->x -= value;
			tmp->y -= value;
			push(tmp, true);
			return 1;
		}else{
			return 0;
		}
	}

	/*
	Dot product/Scalar product
	*/
	int Vec2::operator_mul(State & state, b2Vec2 * a, b2Vec2 * b){
		Stack * stack = state.stack;
		//dot product
		if (a != nullptr && b != nullptr){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(b2Dot(*a, *b)));
			return 1;
		}else if (stack->is<LUA_TNUMBER>(1) && b!=nullptr){
			push(new b2Vec2(
				static_cast<float32>(stack->to<LUA_NUMBER>(1)) * (*b)
				), true);
			return 1;
		}else if (state.stack->is<LUA_TNUMBER>(2) && a!=nullptr){
			push(new b2Vec2(
				static_cast<float32>(stack->to<LUA_NUMBER>(2)) * (*a)
				), true);
			return 1;
		}
		return 0;
	}

	/*
	Cross product
	*/
	int Vec2::operator_mod(State & state, b2Vec2 * a, b2Vec2 * b){
		Stack * stack = state.stack;
		if (a != nullptr && b != nullptr){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(b2Cross(*a, *b)));
			return 1;
		}else if (stack->is<LUA_TNUMBER>(1) && b!=nullptr){
			push(new b2Vec2(
				b2Cross(static_cast<float32>(stack->to<LUA_NUMBER>(1)), (*b))
				), true);
			return 1;
		}else if (state.stack->is<LUA_TNUMBER>(2) && a!=nullptr){
			push(new b2Vec2(
				b2Cross((*a), static_cast<float32>(stack->to<LUA_NUMBER>(2)))
				), true);
			return 1;
		}
		return 0;
	}

	int Vec2::operator_unm(State & state, b2Vec2 * object){
		push(new b2Vec2(-(*object)), true);
		return 1;
	}

	int Vec2::operator_eq(State & state, b2Vec2 * a, b2Vec2 * b){
		if (a != nullptr && b != nullptr){
			state.stack->push<bool>(
				(*a) == (*b)
				);
		}else{
			state.stack->push<bool>(false);
		}
		return 1;
	}

	int Vec2::operator_getArray(State & state, b2Vec2 * object){
		if (state.stack->is<LUA_TNUMBER>(1)){
			int index = state.stack->to<int>(1);
			if (index>=0 && index <= 1){
				state.stack->push<LUA_NUMBER>((*object)(index));
				return 1;
			}
		}
		return 0;
	}

	int Vec2::operator_len(State & state, b2Vec2 * object){
		state.stack->push<LUA_NUMBER>(object->Length());
		return 1;
	}
		
	int Vec2::lengthSquared(State & state, b2Vec2 * object){
		state.stack->push<LUA_NUMBER>(object->LengthSquared());
		return 1;
	}

	int Vec2::normalize(State & state, b2Vec2 * object){
		state.stack->push<LUA_NUMBER>(object->Normalize());
		return 1;
	}

	int Vec2::normalizeTo(State & state, b2Vec2 * object){
		b2Vec2 tmp = (*object);
		tmp.Normalize();
		push(new b2Vec2(tmp), true);
		return 1;
	}

	int Vec2::skew(State & state, b2Vec2 * object){
		push(new b2Vec2(object->Skew()), true);
		return 1;
	}

	int Vec2::isValid(State & state, b2Vec2 * object){
		state.stack->push<bool>(object->IsValid());
		return 1;
	}

	int Vec2::distanceFrom(State & state, b2Vec2 * object){
		b2Vec2 * otherObject = get(1);
		if (otherObject != nullptr){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(b2Distance(*object, *otherObject)));
			return 1;
		}else{
			return 0;
		}
	}

	int Vec2::distanceSquaredFrom(State & state, b2Vec2 * object){
		b2Vec2 * otherObject = get(1);
		if (otherObject != nullptr){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(b2DistanceSquared(*object, *otherObject)));
			return 1;
		}else{
			return 0;
		}
	}

	int Vec2::clamp(State & state, b2Vec2 * object){
		Stack * stack = state.stack;
		b2Vec2 * min = get(1);
		b2Vec2 * max = get(2);
		if (object!= nullptr && min != nullptr && max != nullptr){
			push(new b2Vec2(b2Clamp(*object, *min, *max)), true);
			return 1;
		}else{
			return 0;
		}
	}

	int Vec2::min(State & state, b2Vec2 * object){
		Stack * stack = state.stack;
		b2Vec2 * otherObject = get(1);
		if (object!= nullptr && otherObject != nullptr){
			push(new b2Vec2(b2Min(*object, *otherObject)), true);
			return 1;
		}else{
			return 0;
		}
	}

	int Vec2::max(State & state, b2Vec2 * object){
		Stack * stack = state.stack;
		b2Vec2 * otherObject = get(1);
		if (object!= nullptr && otherObject != nullptr){
			push(new b2Vec2(b2Max(*object, *otherObject)), true);
			return 1;
		}else{
			return 0;
		}
	}
}