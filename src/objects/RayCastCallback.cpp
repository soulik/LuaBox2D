#include "common.hpp"
#include "objects/RayCastCallback.hpp"
#include "objects/Fixture.hpp"
#include "objects/Vec2.hpp"

namespace LuaBox2D {
	void initRayCastCallback(State * state){
		state->registerInterface<RayCastCallback>("LuaBox2D_RayCastCallback");
	}

	LuaBox2DRayCastCallback * RayCastCallback::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		return new LuaBox2DRayCastCallback(&state);
	}

	void RayCastCallback::destructor(State & state, LuaBox2DRayCastCallback * object){
		delete object;
	}


	int RayCastCallback::getReportFixture(State & state, LuaBox2DRayCastCallback * object){
		if (object->refReportFixture != LUA_NOREF){
			state.stack->rawGet(object->refReportFixture, LUA_REGISTRYINDEX);
			return 1;
		}else{
			return 0;
		}
	}

	int RayCastCallback::setReportFixture(State & state, LuaBox2DRayCastCallback * object){
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

	inline bool LuaBox2DRayCastCallback::getCallBack(int ref){
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

	float32 LuaBox2DRayCastCallback::ReportFixture(b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float32 fraction){
		if (getCallBack(refReportFixture)){
			Fixture * interfaceFixture = state->getInterface<Fixture>("LuaBox2D_Fixture");
			Vec2 * interfaceVec2 = state->getInterface<Vec2>("LuaBox2D_Vec2");

			interfaceFixture->push(fixture, false);
			interfaceVec2->push(new b2Vec2(point), true);
			interfaceVec2->push(new b2Vec2(normal), true);
			state->stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(fraction));

			state->stack->call(4, 1);
			float32 retVal = static_cast<float32>(state->stack->to<LUA_NUMBER>());
			state->stack->pop(1);
			return retVal;
		}else{
			return 0.0f;
		}
	}

	LuaBox2DRayCastCallback::~LuaBox2DRayCastCallback(){
		if (refReportFixture != LUA_NOREF){
			state->stack->unref(refReportFixture);
		}
	}
};
