#ifndef LUABOX2D_CONTACTMANAGER_H
#define LUABOX2D_CONTACTMANAGER_H

namespace LuaBox2D {
	class ContactManager : public Object<b2ContactManager> {
	public:
		explicit ContactManager(State * state) : Object<b2ContactManager>(state){
			LUTOK_PROPERTY("contactListener", &ContactManager::getContactListener, &ContactManager::setContactListener);
			LUTOK_PROPERTY("contactFilter", &ContactManager::getContactFilter, &ContactManager::setContactFilter);
		}

		b2ContactManager * constructor(State & state, bool & managed);

		void destructor(State & state, b2ContactManager * object);

		int getContactListener(State & state, b2ContactManager * object);

		int setContactListener(State & state, b2ContactManager * object);

		int getContactFilter(State & state, b2ContactManager * object);

		int setContactFilter(State & state, b2ContactManager * object);

	};

	void initContactManager(State * );
};

#endif	
