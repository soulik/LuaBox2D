#ifndef LUABOX2D_RAYCASTCALLBACK_H
#define LUABOX2D_RAYCASTCALLBACK_H

namespace LuaBox2D {
	class LuaBox2DRayCastCallback : public b2RayCastCallback {
	private:
		State * state;
	public:
		LuaBox2DRayCastCallback(State * state) : b2RayCastCallback(){
			this->state = state;
			refReportFixture = LUA_NOREF;
		}
		~LuaBox2DRayCastCallback();

		float32 ReportFixture(	b2Fixture* fixture, const b2Vec2& point, const b2Vec2& normal, float32 fraction);

		bool getCallBack(int ref);

		int refReportFixture;

	};

	class RayCastCallback : public Object<LuaBox2DRayCastCallback> {
	public:
		explicit RayCastCallback(State * state) : Object<LuaBox2DRayCastCallback>(state){
			LUTOK_PROPERTY("reportFixture", &RayCastCallback::getReportFixture, &RayCastCallback::setReportFixture);
		}

		LuaBox2DRayCastCallback * constructor(State & state, bool & managed);

		void destructor(State & state, LuaBox2DRayCastCallback * object);

		int getReportFixture(State & state, LuaBox2DRayCastCallback * object);

		int setReportFixture(State & state, LuaBox2DRayCastCallback * object);
	};

	void initRayCastCallback(State * );
};

#endif	
