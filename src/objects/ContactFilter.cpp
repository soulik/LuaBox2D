#include "common.hpp"
#include "objects/ContactFilter.hpp"
#include "objects/Fixture.hpp"

namespace LuaBox2D {
	void initContactFilter(State * state){
		state->registerInterface<ContactFilter>("LuaBox2D_ContactFilter");
	}

	inline bool LuaBox2DContactFilter::getCallBack(int ref){
		if (ref != LUA_NOREF){
			state->stack->regValue(ref);
			return true;
		}else{
			return false;
		}
	}

	bool LuaBox2DContactFilter::ShouldCollide(b2Fixture* fixtureA, b2Fixture* fixtureB){
		if (getCallBack(refShouldCollide)){
			Fixture * interfaceFixture = state->getInterface<Fixture>("LuaBox2D_Fixture");
			interfaceFixture->push(fixtureA, false);
			interfaceFixture->push(fixtureB, false);
			state->stack->call(2, 1);
			bool retVal = state->stack->to<bool>();
			state->stack->pop(1);
			return retVal;
		}else{
			return false;
		}
	}

	LuaBox2DContactFilter::~LuaBox2DContactFilter(){
		if (refShouldCollide != LUA_NOREF){
			state->stack->unref(refShouldCollide);
		}
	}

	LuaBox2DContactFilter * ContactFilter::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		return new LuaBox2DContactFilter(&state);
	}

	void ContactFilter::destructor(State & state, LuaBox2DContactFilter * object){
		delete object;
	}

	int ContactFilter::getShouldCollide(State & state, LuaBox2DContactFilter * object){
		if (object->refShouldCollide != LUA_NOREF){
			state.stack->rawGet(object->refShouldCollide, LUA_REGISTRYINDEX);
			return 1;
		}else{
			return 0;
		}
	}

	int ContactFilter::setShouldCollide(State & state, LuaBox2DContactFilter * object){
		if (state.stack->is<LUA_TFUNCTION>(1)){
			if (object->refShouldCollide != LUA_NOREF){
				state.stack->unref(object->refShouldCollide);
			}
			state.stack->pushValue(1);
			object->refShouldCollide = state.stack->ref();
		}else{
			if (state.stack->is<LUA_TNIL>(1)){
				if (object->refShouldCollide != LUA_NOREF){
					state.stack->unref(object->refShouldCollide);
					object->refShouldCollide = LUA_NOREF;
				}
			}
		}
		return 0;
	}
};
