#include "common.hpp"
#include "objects/ContactManager.hpp"
#include "objects/ContactListener.hpp"
#include "objects/ContactFilter.hpp"

namespace LuaBox2D {
	void initContactManager(State * state){
		state->registerInterface<ContactManager>("LuaBox2D_ContactManager");
	}

	b2ContactManager * ContactManager::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		return new b2ContactManager();
	}

	void ContactManager::destructor(State & state, b2ContactManager * object){
		delete object;
	}

	int ContactManager::getContactListener(State & state, b2ContactManager * object){
		ContactListener * interfaceContactListener = state.getInterface<ContactListener>("LuaBox2D_ContactListener");
		interfaceContactListener->push( dynamic_cast<LuaBox2DContactListener*>(object->m_contactListener), false);
		return 1;
	}

	int ContactManager::setContactListener(State & state, b2ContactManager * object){
		ContactListener * interfaceContactListener = state.getInterface<ContactListener>("LuaBox2D_ContactListener");
		LuaBox2DContactListener * listener = interfaceContactListener->get(1);
		if (listener != nullptr){
			object->m_contactListener = listener;
		}
		return 0;
	}

	int ContactManager::getContactFilter(State & state, b2ContactManager * object){
		ContactFilter * interfaceContactFilter = state.getInterface<ContactFilter>("LuaBox2D_ContactFilter");
		interfaceContactFilter->push( dynamic_cast<LuaBox2DContactFilter*>(object->m_contactFilter), false);
		return 1;
	}

	int ContactManager::setContactFilter(State & state, b2ContactManager * object){
		ContactFilter * interfaceContactFilter = state.getInterface<ContactFilter>("LuaBox2D_ContactFilter");
		LuaBox2DContactFilter * filter = interfaceContactFilter->get(1);
		if (filter != nullptr){
			object->m_contactFilter = filter;
		}
		return 0;
	}
};
