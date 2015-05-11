#include "common.hpp"
#include "objects/ContactID.hpp"
#include "objects/ContactFeature.hpp"

namespace LuaBox2D {
	void initContactID(State * state){
		state->registerInterface<ContactID>("LuaBox2D_ContactID");
	}

	b2ContactID * ContactID::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		return new b2ContactID();
	}

	void ContactID::destructor(State & state, b2ContactID * object){
		delete object;
	}

	int ContactID::getContactFeature(State & state, b2ContactID * object){
		ContactFeature * interfaceContactFeature = state.getInterface<ContactFeature>("LuaBox2D_ContactFeature");
		interfaceContactFeature->push(& object->cf, false);
		return 1;
	}

	int ContactID::setContactFeature(State & state, b2ContactID * object){
		ContactFeature * interfaceContactFeature = state.getInterface<ContactFeature>("LuaBox2D_ContactFeature");
		b2ContactFeature * cf = interfaceContactFeature->get(1);
		if (cf != nullptr){
			object->cf = *cf;
		}
		return 0;
	}

	int ContactID::getKey(State & state, b2ContactID * object){
		state.stack->push<int>(static_cast<int>(object->key));
		return 1;
	}

	int ContactID::setKey(State & state, b2ContactID * object){
		object->key = static_cast<int32>(state.stack->to<int>(1));
		return 0;
	}
};
