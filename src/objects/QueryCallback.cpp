#include "common.hpp"
#include "objects/QueryCallback.hpp"
#include "objects/Fixture.hpp"

namespace LuaBox2D {
	void initQueryCallback(State * state){
		state->registerInterface<QueryCallback>("LuaBox2D_QueryCallback");
	}

	LuaBox2DQueryCallback * QueryCallback::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		return new LuaBox2DQueryCallback(&state);
	}

	void QueryCallback::destructor(State & state, LuaBox2DQueryCallback * object){
		delete object;
	}

	int QueryCallback::getReportFixture(State & state, LuaBox2DQueryCallback * object){
		if (object->refReportFixture != LUA_NOREF){
			state.stack->rawGet(object->refReportFixture, LUA_REGISTRYINDEX);
			return 1;
		}else{
			return 0;
		}
	}

	int QueryCallback::setReportFixture(State & state, LuaBox2DQueryCallback * object){
		if (state.stack->is<LUA_TFUNCTION>(1)){
			if (object->refReportFixture != LUA_NOREF){
				state.stack->unref(object->refReportFixture);
			}
			state.stack->pushValue(1);
			object->refReportFixture = state.stack->ref();
		}else{
			if (state.stack->is<LUA_TNIL>(1)){
				if (object->refReportFixture != LUA_NOREF){
					state.stack->unref(object->refReportFixture);
					object->refReportFixture = LUA_NOREF;
				}
			}
		}
		return 0;
	}

	inline bool LuaBox2DQueryCallback::getCallBack(int ref){
		if (ref != LUA_NOREF){
			state->stack->regValue(ref);
			if (state->stack->is<LUA_TFUNCTION>()){
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	}

	bool LuaBox2DQueryCallback::ReportFixture(b2Fixture* fixture){
		if (getCallBack(refReportFixture)){
			Fixture * interfaceFixture = state->getInterface<Fixture>("LuaBox2D_Fixture");
			interfaceFixture->push(fixture, false);
			state->stack->call(1, 1);
			bool retVal = state->stack->to<bool>();
			state->stack->pop(1);
			return retVal;
		}else{
			return false;
		}
	}

	LuaBox2DQueryCallback::~LuaBox2DQueryCallback(){
		if (refReportFixture != LUA_NOREF){
			state->stack->unref(refReportFixture);
		}
	}
};
