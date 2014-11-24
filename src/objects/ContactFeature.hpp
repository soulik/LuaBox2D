#ifndef LUABOX2D_CONTACTFEATURE_H
#define LUABOX2D_CONTACTFEATURE_H

namespace LuaBox2D {
	class ContactFeature : public Object<b2ContactFeature> {
	public:
		explicit ContactFeature(State * state) : Object<b2ContactFeature>(state){
			LUTOK_PROPERTY("indexA", &ContactFeature::getIndexA, &ContactFeature::setIndexA);
			LUTOK_PROPERTY("indexB", &ContactFeature::getIndexB, &ContactFeature::setIndexB);
			LUTOK_PROPERTY("typeA", &ContactFeature::getTypeA, &ContactFeature::setTypeA);
			LUTOK_PROPERTY("typeB", &ContactFeature::getTypeB, &ContactFeature::setTypeB);
		}

		b2ContactFeature * constructor(State & state, bool & managed);

		void destructor(State & state, b2ContactFeature * object);

		int getIndexA(State & state, b2ContactFeature * object);

		int setIndexA(State & state, b2ContactFeature * object);

		int getIndexB(State & state, b2ContactFeature * object);

		int setIndexB(State & state, b2ContactFeature * object);

		int getTypeA(State & state, b2ContactFeature * object);

		int setTypeA(State & state, b2ContactFeature * object);

		int getTypeB(State & state, b2ContactFeature * object);

		int setTypeB(State & state, b2ContactFeature * object);
	};

	void initContactFeature(State * );
};

#endif	
