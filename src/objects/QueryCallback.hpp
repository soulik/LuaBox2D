#ifndef LUABOX2D_QUERYCALLBACK_H
#define LUABOX2D_QUERYCALLBACK_H

namespace LuaBox2D {
	class LuaBox2DQueryCallback : public b2QueryCallback {
	private:
		State * state;
	public:
		LuaBox2DQueryCallback(State * state) : b2QueryCallback(){
			this->state = state;
			refReportFixture = LUA_NOREF;
		}
		~LuaBox2DQueryCallback();

		bool ReportFixture(b2Fixture* fixture);

		bool getCallBack(int ref);

		int refReportFixture;

	};

	class QueryCallback : public Object<LuaBox2DQueryCallback> {
	public:
		explicit QueryCallback(State * state) : Object<LuaBox2DQueryCallback>(state){
			LUTOK_PROPERTY("reportFixture", &QueryCallback::getReportFixture, &QueryCallback::setReportFixture);
		}

		LuaBox2DQueryCallback * constructor(State & state, bool & managed);

		void destructor(State & state, LuaBox2DQueryCallback * object);

		int getReportFixture(State & state, LuaBox2DQueryCallback * object);

		int setReportFixture(State & state, LuaBox2DQueryCallback * object);
	};

	void initQueryCallback(State * );
};

#endif	
