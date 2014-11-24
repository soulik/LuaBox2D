#ifndef LUABOX2D_CONTACTEDGE_H
#define LUABOX2D_CONTACTEDGE_H

namespace LuaBox2D {
	class ContactEdge : public Object<b2ContactEdge> {
	public:
		explicit ContactEdge(State * state) : Object<b2ContactEdge>(state){
			LUTOK_PROPERTY("other", &ContactEdge::getOther, &ContactEdge::nullMethod);
			LUTOK_PROPERTY("contact", &ContactEdge::getContact, &ContactEdge::nullMethod);
			LUTOK_PROPERTY("prev", &ContactEdge::getPrev, &ContactEdge::nullMethod);
			LUTOK_PROPERTY("next", &ContactEdge::getNext, &ContactEdge::nullMethod);
		}

		b2ContactEdge * constructor(State & state, bool & managed);

		void destructor(State & state, b2ContactEdge * object);

		int getOther(State & state, b2ContactEdge * object);
		int getContact(State & state, b2ContactEdge * object);
		int getPrev(State & state, b2ContactEdge * object);
		int getNext(State & state, b2ContactEdge * object);

	};

	void initContactEdge(State * );
};

#endif	
