#ifndef LUABOX2D_CONTACT_H
#define LUABOX2D_CONTACT_H

namespace LuaBox2D {
	class Contact : public Object<b2Contact> {
	public:
		explicit Contact(State * state) : Object<b2Contact>(state){
			LUTOK_PROPERTY("manifold", &Contact::getManifold, &Contact::nullMethod);
			LUTOK_PROPERTY("worldManifold", &Contact::getWorldManifold, &Contact::nullMethod);
			LUTOK_PROPERTY("isTouching", &Contact::isTouching, &Contact::nullMethod);
			LUTOK_PROPERTY("enabled", &Contact::isEnabled, &Contact::setEnabled);
			LUTOK_PROPERTY("next", &Contact::getNext, &Contact::nullMethod);
			LUTOK_PROPERTY("fixtureA", &Contact::getFixtureA, &Contact::nullMethod);
			LUTOK_PROPERTY("fixtureB", &Contact::getFixtureB, &Contact::nullMethod);
			LUTOK_PROPERTY("childIndexA", &Contact::getChildIndexA, &Contact::nullMethod);
			LUTOK_PROPERTY("childIndexB", &Contact::getChildIndexB, &Contact::nullMethod);
			LUTOK_PROPERTY("friction", &Contact::getFriction, &Contact::setFriction);
			LUTOK_PROPERTY("restitution", &Contact::getRestitution, &Contact::setRestitution);
			LUTOK_PROPERTY("tangentSpeed", &Contact::getTangentSpeed, &Contact::setTangentSpeed);

			LUTOK_METHOD("resetFriction", &Contact::resetFriction);
			LUTOK_METHOD("resetRestitution", &Contact::resetRestitution);
		}

		b2Contact * constructor(State & state, bool & managed);

		void destructor(State & state, b2Contact * object);

		int getManifold(State & state, b2Contact * object);

		int getWorldManifold(State & state, b2Contact * object);

		int isTouching(State & state, b2Contact * object);

		int isEnabled(State & state, b2Contact * object);

		int setEnabled(State & state, b2Contact * object);

		int getNext(State & state, b2Contact * object);

		int getFixtureA(State & state, b2Contact * object);

		int getFixtureB(State & state, b2Contact * object);

		int getChildIndexA(State & state, b2Contact * object);

		int getChildIndexB(State & state, b2Contact * object);

		int getFriction(State & state, b2Contact * object);

		int setFriction(State & state, b2Contact * object);

		int getRestitution(State & state, b2Contact * object);

		int setRestitution(State & state, b2Contact * object);

		int getTangentSpeed(State & state, b2Contact * object);

		int setTangentSpeed(State & state, b2Contact * object);

		int resetFriction(State & state, b2Contact * object);

		int resetRestitution(State & state, b2Contact * object);
	};

	void initContact(State * );
};

#endif	
