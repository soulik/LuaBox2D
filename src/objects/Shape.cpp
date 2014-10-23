#include "common.hpp"
#include "objects/Shape.hpp"
#include "objects/CircleShape.hpp"
#include "objects/ChainShape.hpp"
#include "objects/EdgeShape.hpp"
#include "objects/PolygonShape.hpp"

namespace LuaBox2D {
	void initShape(State * state){
		state->registerInterface<Shape>("LuaBox2D_Shape");
	}

	b2Shape * Shape::constructor(State & state){
		b2Shape *obj = get(1);
		if (obj != nullptr){
			return obj;
		}else{
			return nullptr;
		}
	}
};