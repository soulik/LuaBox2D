#include "common.hpp"
#include "objects/Contact.hpp"
#include "objects/Fixture.hpp"
#include "objects/Manifold.hpp"
#include "objects/WorldManifold.hpp"

namespace LuaBox2D {
	void initContact(State * state){
		state->registerInterface<Contact>("LuaBox2D_Contact");
	}

	b2Contact * Contact::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(state);
		LUTOK2_NOT_USED(managed);
		/*
		if (state.stack->is<LUA_TUSERDATA>(1)){
			Contact * interfaceContact = state.getInterface<Contact>("LuaBox2D_Contact");
			b2Contact * contact = interfaceContact->get(1);
			if (contact != nullptr){
				return new b2Contact(*contact);
			}else{
				return nullptr;
			}
		}else{
			return nullptr;
		}
		*/
		return nullptr;
	}

	void Contact::destructor(State & state, b2Contact * object){
		LUTOK2_NOT_USED(state);
		LUTOK2_NOT_USED(object);
	}

	int Contact::getManifold(State & state, b2Contact * object){
		Manifold * interfaceManifold = state.getInterface<Manifold>("LuaBox2D_Manifold");
		interfaceManifold->push(object->GetManifold(),false);
		return 1;
	}

	int Contact::getWorldManifold(State & state, b2Contact * object){
		WorldManifold * interfaceWorldManifold = state.getInterface<WorldManifold>("LuaBox2D_WorldManifold");
		b2WorldManifold * worldManifold = new b2WorldManifold();
		object->GetWorldManifold(worldManifold);
		interfaceWorldManifold->push(worldManifold, true);
		return 1;
	}

	int Contact::isTouching(State & state, b2Contact * object){
		state.stack->push<bool>(object->IsTouching());
		return 1;
	}

	int Contact::isEnabled(State & state, b2Contact * object){
		state.stack->push<bool>(object->IsEnabled());
		return 1;
	}

	int Contact::setEnabled(State & state, b2Contact * object){
		object->SetEnabled(state.stack->to<bool>(1));
		return 0;
	}

	int Contact::getNext(State & state, b2Contact * object){
		Contact * interfaceContact = state.getInterface<Contact>("LuaBox2D_Contact");
		b2Contact * contact = object->GetNext();
		if (contact != nullptr){
			interfaceContact->push(contact);
			return 1;
		}else{
			return 0;
		}
	}

	int Contact::getFixtureA(State & state, b2Contact * object){
		Fixture * interfaceFixture = state.getInterface<Fixture>("LuaBox2D_Fixture");
		interfaceFixture->push(object->GetFixtureA(), false);
		return 1;
	}

	int Contact::getFixtureB(State & state, b2Contact * object){
		Fixture * interfaceFixture = state.getInterface<Fixture>("LuaBox2D_Fixture");
		interfaceFixture->push(object->GetFixtureB(), false);
		return 1;
	}

	int Contact::getChildIndexA(State & state, b2Contact * object){
		state.stack->push<int>(static_cast<int>(object->GetChildIndexA()));
		return 1;
	}

	int Contact::getChildIndexB(State & state, b2Contact * object){
		state.stack->push<int>(static_cast<int>(object->GetChildIndexB()));
		return 1;
	}

	int Contact::getFriction(State & state, b2Contact * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetFriction()));
		return 1;
	}

	int Contact::setFriction(State & state, b2Contact * object){
		object->SetFriction(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int Contact::getRestitution(State & state, b2Contact * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetRestitution()));
		return 1;
	}

	int Contact::setRestitution(State & state, b2Contact * object){
		object->SetRestitution(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int Contact::getTangentSpeed(State & state, b2Contact * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetTangentSpeed()));
		return 1;
	}

	int Contact::setTangentSpeed(State & state, b2Contact * object){
		object->SetTangentSpeed(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int Contact::resetFriction(State & state, b2Contact * object){
		object->ResetFriction();
		return 0;
	}

	int Contact::resetRestitution(State & state, b2Contact * object){
		object->ResetRestitution();
		return 0;
	}
};
