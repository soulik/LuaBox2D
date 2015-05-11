#include "common.hpp"
#include "objects/Body.hpp"
#include "objects/Contact.hpp"
#include "objects/ContactEdge.hpp"

namespace LuaBox2D {
	void initContactEdge(State * state){
		state->registerInterface<ContactEdge>("LuaBox2D_ContactEdge");
	}

	b2ContactEdge * ContactEdge::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		b2ContactEdge * object = new b2ContactEdge();
		
		object->contact = nullptr;
		object->other = nullptr;
		object->next = nullptr;
		object->prev = nullptr;

		return object;
	}

	void ContactEdge::destructor(State & state, b2ContactEdge * object){
		delete object;
	}

	int ContactEdge::getOther(State & state, b2ContactEdge * object){
		Body * interfaceBody = state.getInterface<Body>("LuaBox2D_Body");
		if (object->other){
			interfaceBody->push(object->other, false);
			return 1;
		}else{
			return 0;
		}
	}

	int ContactEdge::getContact(State & state, b2ContactEdge * object){
		Contact * interfaceContact = state.getInterface<Contact>("LuaBox2D_Contact");
		if (object->contact){
			interfaceContact->push(object->contact, false);
			return 1;
		}else{
			return 0;
		}
	}

	int ContactEdge::getPrev(State & state, b2ContactEdge * object){
		ContactEdge * interfaceContactEdge = state.getInterface<ContactEdge>("LuaBox2D_ContactEdge");
		if (object->prev){
			interfaceContactEdge->push(object->prev, false);
			return 1;
		}else{
			return 0;
		}
	}

	int ContactEdge::getNext(State & state, b2ContactEdge * object){
		ContactEdge * interfaceContactEdge = state.getInterface<ContactEdge>("LuaBox2D_ContactEdge");
		if (object->next){
			interfaceContactEdge->push(object->next, false);
			return 1;
		}else{
			return 0;
		}
	}
};
