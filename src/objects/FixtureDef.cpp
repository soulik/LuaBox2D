#include "common.hpp"
#include "objects/Filter.hpp"
#include "objects/Shape.hpp"
#include "objects/FixtureDef.hpp"

namespace LuaBox2D {
	void initFixtureDef(State * state){
		state->registerInterface<FixtureDef>("LuaBox2D_FixtureDef");
	}

	b2FixtureDef * FixtureDef::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		b2FixtureDef * obj = nullptr;
		obj = new b2FixtureDef();

		return obj;
	}

	void FixtureDef::destructor(State & state, b2FixtureDef * object){
		delete object;
	}

	int FixtureDef::getFriction(State & state, b2FixtureDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->friction));
		return 1;
	}

	int FixtureDef::setFriction(State & state, b2FixtureDef * object){
		object->friction = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int FixtureDef::getRestitution(State & state, b2FixtureDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->restitution));
		return 1;
	}

	int FixtureDef::setRestitution(State & state, b2FixtureDef * object){
		object->restitution = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int FixtureDef::getDensity(State & state, b2FixtureDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->density));
		return 1;
	}

	int FixtureDef::setDensity(State & state, b2FixtureDef * object){
		object->density = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int FixtureDef::getSensor(State & state, b2FixtureDef * object){
		state.stack->push<bool>(object->isSensor);
		return 1;
	}

	int FixtureDef::setSensor(State & state, b2FixtureDef * object){
		object->isSensor = state.stack->to<bool>(1);
		return 0;
	}

	int FixtureDef::getFilter(State & state, b2FixtureDef * object){
		Filter * interfaceFilter = state.getInterface<Filter>("LuaBox2D_Filter");
		interfaceFilter->push(&object->filter, false);
		return 1;
	}

	int FixtureDef::setFilter(State & state, b2FixtureDef * object){
		Filter * interfaceFilter = state.getInterface<Filter>("LuaBox2D_Filter");
		b2Filter * filter = interfaceFilter->get(1);
		if (filter != nullptr){
			object->filter = *filter;
		}
		return 0;
	}

	int FixtureDef::getShape(State & state, b2FixtureDef * object){
		Shape * interfaceShape = state.getInterface<Shape>("LuaBox2D_Shape");
		interfaceShape->push(const_cast<b2Shape *>(object->shape), false);
		return 1;
	}

	int FixtureDef::setShape(State & state, b2FixtureDef * object){
		Shape * interfaceShape = state.getInterface<Shape>("LuaBox2D_Shape");
		b2Shape * shape = interfaceShape->get(1);
		if (shape != nullptr){
			object->shape = shape;
		}
		return 0;
	}

	int FixtureDef::getUserData(State & state, b2FixtureDef * object){
		int ref = static_cast<int>(reinterpret_cast<intptr_t>(object->userData));
		if (ref != LUA_NOREF && ref != 0){
			state.stack->regValue(ref);
			return 1;
		}else{
			return 0;
		}
	}

	int FixtureDef::setUserData(State & state, b2FixtureDef * object){
		int oldRef = static_cast<int>(reinterpret_cast<intptr_t>(object->userData));
		if (oldRef != LUA_NOREF && oldRef != 0){
			state.stack->unref(oldRef);
		}
		if (!state.stack->is<LUA_TNIL>(1)){
			state.stack->pushValue(1);
			int ref = state.stack->ref();

			object->userData = reinterpret_cast<void*>(ref);
		}
		return 0;
	}
};