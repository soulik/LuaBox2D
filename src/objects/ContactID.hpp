#ifndef LUABOX2D_CONTACTID_H
#define LUABOX2D_CONTACTID_H

namespace LuaBox2D {
	class ContactID : public Object<b2ContactID> {
	public:
		explicit ContactID(State * state) : Object<b2ContactID>(state){
			LUTOK_PROPERTY("cf", &ContactID::getContactFeature, &ContactID::setContactFeature);
			LUTOK_PROPERTY("key", &ContactID::getKey, &ContactID::setKey);
		}

		b2ContactID * constructor(State & state, bool & managed);

		void destructor(State & state, b2ContactID * object);

		int getContactFeature(State & state, b2ContactID * object);

		int setContactFeature(State & state, b2ContactID * object);

		int getKey(State & state, b2ContactID * object);

		int setKey(State & state, b2ContactID * object);
	};

	void initContactID(State * );
};

#endif	
