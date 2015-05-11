#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/MassData.hpp"

namespace LuaBox2D {
	void initMassData(State * state){
		state->registerInterface<MassData>("LuaBox2D_MassData");
	}

	b2MassData * MassData::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		b2MassData * object = new b2MassData();
		return object;
	}

	void MassData::destructor(State & state, b2MassData * object){
		delete object;
	}

	int MassData::getCenter(State & state, b2MassData * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->center, false);
		return 1;
	}

	int MassData::setCenter(State & state, b2MassData * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * bound = interfaceVec2->get(1);
		if (bound != nullptr){
			object->center = *bound;
		}
		return 0;
	}

	int MassData::getMass(State & state, b2MassData * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->mass));
		return 1;
	}

	int MassData::setMass(State & state, b2MassData * object){
		object->mass = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int MassData::getI(State & state, b2MassData * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->I));
		return 1;
	}

	int MassData::setI(State & state, b2MassData * object){
		object->I = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}
};
