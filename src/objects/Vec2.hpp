#ifndef LUABOX2D_VEC2_H
#define LUABOX2D_VEC2_H

namespace LuaBox2D {
	class Vec2 : public Object<b2Vec2> {
	public:
		explicit Vec2(State * state) : Object<b2Vec2>(state){
			LUTOK_PROPERTY("x", &Vec2::getX, &Vec2::setX);
			LUTOK_PROPERTY("y", &Vec2::getY, &Vec2::setY);
			LUTOK_PROPERTY("length", &Vec2::operator_len, &Vec2::nullMethod);
			LUTOK_PROPERTY("lengthSquared", &Vec2::lengthSquared, &Vec2::nullMethod);
			LUTOK_PROPERTY("valid", &Vec2::isValid, &Vec2::nullMethod);

			LUTOK_METHOD("zero", &Vec2::zero);
			LUTOK_METHOD("normalize", &Vec2::normalize);
			LUTOK_METHOD("normalizeTo", &Vec2::normalizeTo);
			LUTOK_METHOD("skew", &Vec2::skew);
			LUTOK_METHOD("distanceFrom", &Vec2::distanceFrom);
			LUTOK_METHOD("distanceSquaredFrom", &Vec2::distanceSquaredFrom);
			LUTOK_METHOD("clamp", &Vec2::clamp);
			LUTOK_METHOD("min", &Vec2::min);
			LUTOK_METHOD("max", &Vec2::max);
		}

		b2Vec2 * constructor(State & state, bool & managed);

		void destructor(State & state, b2Vec2 * object);

		int getX(State & state, b2Vec2 * object);

		int setX(State & state, b2Vec2 * object);

		int getY(State & state, b2Vec2 * object);

		int setY(State & state, b2Vec2 * object);

		int zero(State & state, b2Vec2 * object);

		int operator_add(State & state, b2Vec2 * a, b2Vec2 * b);

		int operator_sub(State & state, b2Vec2 * a, b2Vec2 * b);

		/*
		Dot product/Scalar product
		*/
		int operator_mul(State & state, b2Vec2 * a, b2Vec2 * b);

		/*
		Cross product
		*/
		int operator_mod(State & state, b2Vec2 * a, b2Vec2 * b);

		int operator_unm(State & state, b2Vec2 * object);

		int operator_eq(State & state, b2Vec2 * a, b2Vec2 * b);

		int operator_getArray(State & state, b2Vec2 * object);

		int operator_len(State & state, b2Vec2 * object);
		
		int lengthSquared(State & state, b2Vec2 * object);

		int normalize(State & state, b2Vec2 * object);

		int normalizeTo(State & state, b2Vec2 * object);

		int skew(State & state, b2Vec2 * object);

		int isValid(State & state, b2Vec2 * object);

		int distanceFrom(State & state, b2Vec2 * object);

		int distanceSquaredFrom(State & state, b2Vec2 * object);

		int clamp(State & state, b2Vec2 * object);

		int min(State & state, b2Vec2 * object);

		int max(State & state, b2Vec2 * object);
	};

	void initVec2(State *);

};

#endif