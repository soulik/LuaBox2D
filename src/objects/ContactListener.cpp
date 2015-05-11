#include "common.hpp"
#include "objects/ContactListener.hpp"
#include "objects/Contact.hpp"
#include "objects/ContactImpulse.hpp"
#include "objects/Manifold.hpp"

namespace LuaBox2D {
	void initContactListener(State * state){
		state->registerInterface<ContactListener>("LuaBox2D_ContactListener");
	}

	inline bool LuaBox2DContactListener::getCallBack(int ref){
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

	void LuaBox2DContactListener::BeginContact(b2Contact* contact){
		if (getCallBack(refBeginContact)){
			Contact * interfaceContact = state->getInterface<Contact>("LuaBox2D_Contact");
			interfaceContact->push(contact, false);
			state->stack->call(1, 0);
		}
	}

	void LuaBox2DContactListener::EndContact(b2Contact* contact){
		if (getCallBack(refEndContact)){
			Contact * interfaceContact = state->getInterface<Contact>("LuaBox2D_Contact");
			interfaceContact->push(contact, false);
			state->stack->call(1, 0);
		}

	}

	void LuaBox2DContactListener::PreSolve(b2Contact* contact, const b2Manifold* oldManifold){
		if (getCallBack(refPreSolve)){
			Contact * interfaceContact = state->getInterface<Contact>("LuaBox2D_Contact");
			Manifold * interfaceManifold = state->getInterface<Manifold>("LuaBox2D_Manifold");
			interfaceContact->push(contact, false);
			interfaceManifold->push(new b2Manifold(*oldManifold), true);
			state->stack->call(2, 0);
		}
	}

	void LuaBox2DContactListener::PostSolve(b2Contact* contact, const b2ContactImpulse* impulse){
		if (getCallBack(refPostSolve)){
			Contact * interfaceContact = state->getInterface<Contact>("LuaBox2D_Contact");
			ContactImpulse * interfaceContactImpulse = state->getInterface<ContactImpulse>("LuaBox2D_ContactImpulse");
			interfaceContact->push(contact, false);
			interfaceContactImpulse->push(new b2ContactImpulse(*impulse), true);
			state->stack->call(2, 0);
		}
	}

	LuaBox2DContactListener::~LuaBox2DContactListener(){
		if (refBeginContact != LUA_NOREF){
			state->stack->unref(refBeginContact);
		}
		if (refEndContact != LUA_NOREF){
			state->stack->unref(refEndContact);
		}
		if (refPreSolve != LUA_NOREF){
			state->stack->unref(refPreSolve);
		}
		if (refPostSolve != LUA_NOREF){
			state->stack->unref(refPostSolve);
		}
	}

	LuaBox2DContactListener * ContactListener::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		return new LuaBox2DContactListener(&state);
	}

	void ContactListener::destructor(State & state, LuaBox2DContactListener * object){
		delete object;
	}


	int ContactListener::getBeginContact(State & state, LuaBox2DContactListener * object){
		if (object->refBeginContact != LUA_NOREF){
			state.stack->rawGet(object->refBeginContact, LUA_REGISTRYINDEX);
			return 1;
		}else{
			return 0;
		}
	}

	int ContactListener::setBeginContact(State & state, LuaBox2DContactListener * object){
		if (state.stack->is<LUA_TFUNCTION>(1)){
			if (object->refBeginContact != LUA_NOREF){
				state.stack->unref(object->refBeginContact);
			}
			state.stack->pushValue(1);
			object->refBeginContact = state.stack->ref();
		}else{
			if (state.stack->is<LUA_TNIL>(1)){
				if (object->refBeginContact != LUA_NOREF){
					state.stack->unref(object->refBeginContact);
					object->refBeginContact = LUA_NOREF;
				}
			}
		}
		return 0;
	}

	int ContactListener::getEndContact(State & state, LuaBox2DContactListener * object){
		if (object->refEndContact != LUA_NOREF){
			state.stack->rawGet(object->refEndContact, LUA_REGISTRYINDEX);
			return 1;
		}else{
			return 0;
		}
	}

	int ContactListener::setEndContact(State & state, LuaBox2DContactListener * object){
		if (state.stack->is<LUA_TFUNCTION>(1)){
			if (object->refEndContact != LUA_NOREF){
				state.stack->unref(object->refEndContact);
			}
			state.stack->pushValue(1);
			object->refEndContact = state.stack->ref();
		}else{
			if (state.stack->is<LUA_TNIL>(1)){
				if (object->refEndContact != LUA_NOREF){
					state.stack->unref(object->refEndContact);
					object->refEndContact = LUA_NOREF;
				}
			}
		}
		return 0;
	}

	int ContactListener::getPreSolve(State & state, LuaBox2DContactListener * object){
		if (object->refPreSolve != LUA_NOREF){
			state.stack->rawGet(object->refPreSolve, LUA_REGISTRYINDEX);
			return 1;
		}else{
			return 0;
		}
	}

	int ContactListener::setPreSolve(State & state, LuaBox2DContactListener * object){
		if (state.stack->is<LUA_TFUNCTION>(1)){
			if (object->refPreSolve != LUA_NOREF){
				state.stack->unref(object->refPreSolve);
			}
			state.stack->pushValue(1);
			object->refPreSolve = state.stack->ref();
		}else{
			if (state.stack->is<LUA_TNIL>(1)){
				if (object->refPreSolve != LUA_NOREF){
					state.stack->unref(object->refPreSolve);
					object->refPreSolve = LUA_NOREF;
				}
			}
		}
		return 0;
	}

	int ContactListener::getPostSolve(State & state, LuaBox2DContactListener * object){
		if (object->refPostSolve != LUA_NOREF){
			state.stack->rawGet(object->refPostSolve, LUA_REGISTRYINDEX);
			return 1;
		}else{
			return 0;
		}
	}

	int ContactListener::setPostSolve(State & state, LuaBox2DContactListener * object){
		if (state.stack->is<LUA_TFUNCTION>(1)){
			if (object->refPostSolve != LUA_NOREF){
				state.stack->unref(object->refPostSolve);
			}
			state.stack->pushValue(1);
			object->refPostSolve = state.stack->ref();
		}else{
			if (state.stack->is<LUA_TNIL>(1)){
				if (object->refPostSolve != LUA_NOREF){
					state.stack->unref(object->refPostSolve);
					object->refPostSolve = LUA_NOREF;
				}
			}
		}
		return 0;
	}
};
