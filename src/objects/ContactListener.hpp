#ifndef LUABOX2D_CONTACTLISTENER_H
#define LUABOX2D_CONTACTLISTENER_H

namespace LuaBox2D {
	class LuaBox2DContactListener : public b2ContactListener {
	private:
		State * state;
	public:
		LuaBox2DContactListener(State * state) : b2ContactListener(){
			this->state = state;
			refBeginContact = LUA_NOREF;
			refEndContact = LUA_NOREF;
			refPreSolve = LUA_NOREF;
			refPostSolve = LUA_NOREF;
		}
		~LuaBox2DContactListener();

		void BeginContact(b2Contact* contact);
		void EndContact(b2Contact* contact);
		void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);
		void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);

		bool getCallBack(int ref);
		
		int refBeginContact;
		int refEndContact;
		int refPreSolve;
		int refPostSolve;
	};

	class ContactListener : public Object<LuaBox2DContactListener> {
	public:
		explicit ContactListener(State * state) : Object<LuaBox2DContactListener>(state){
			LUTOK_PROPERTY("beginContact", &ContactListener::getBeginContact, &ContactListener::setBeginContact);
			LUTOK_PROPERTY("endContact", &ContactListener::getEndContact, &ContactListener::setEndContact);
			LUTOK_PROPERTY("preSolve", &ContactListener::getPreSolve, &ContactListener::setPreSolve);
			LUTOK_PROPERTY("postSolve", &ContactListener::getPostSolve, &ContactListener::setPostSolve);
		}

		LuaBox2DContactListener * constructor(State & state, bool & managed);

		void destructor(State & state, LuaBox2DContactListener * object);

		int getBeginContact(State & state, LuaBox2DContactListener * object);

		int setBeginContact(State & state, LuaBox2DContactListener * object);

		int getEndContact(State & state, LuaBox2DContactListener * object);

		int setEndContact(State & state, LuaBox2DContactListener * object);

		int getPreSolve(State & state, LuaBox2DContactListener * object);

		int setPreSolve(State & state, LuaBox2DContactListener * object);

		int getPostSolve(State & state, LuaBox2DContactListener * object);

		int setPostSolve(State & state, LuaBox2DContactListener * object);
	};

	void initContactListener(State * );
};

#endif	
