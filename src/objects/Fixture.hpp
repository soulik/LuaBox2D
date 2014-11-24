#ifndef LUABOX2D_FIXTURE_H
#define LUABOX2D_FIXTURE_H

namespace LuaBox2D {
	class Fixture : public Object<b2Fixture> {
	public:
		explicit Fixture(State * state) : Object<b2Fixture>(state){
			LUTOK_PROPERTY("type", &Fixture::getType, &Fixture::nullMethod);
			LUTOK_PROPERTY("shape", &Fixture::getShape, &Fixture::nullMethod);
			LUTOK_PROPERTY("sensor", &Fixture::getSensor, &Fixture::setSensor);
			LUTOK_PROPERTY("filter", &Fixture::getFilter, &Fixture::setFilter);
			LUTOK_PROPERTY("body", &Fixture::getBody, &Fixture::nullMethod);
			LUTOK_PROPERTY("friction", &Fixture::getFriction, &Fixture::setFriction);
			LUTOK_PROPERTY("restitution", &Fixture::getRestitution, &Fixture::setRestitution);
			LUTOK_PROPERTY("density", &Fixture::getDensity, &Fixture::setDensity);
			LUTOK_PROPERTY("AABB", &Fixture::getAABB, &Fixture::nullMethod);
			LUTOK_PROPERTY("massData", &Fixture::getMassData, &Fixture::nullMethod);
			LUTOK_PROPERTY("next", &Fixture::getNext, &Fixture::nullMethod);

			LUTOK_METHOD("refilter", &Fixture::refilter);
			LUTOK_METHOD("testPoint", &Fixture::testPoint);
			LUTOK_METHOD("rayCast", &Fixture::rayCast);

			LUTOK_PROPERTY("userData", &Fixture::getUserData, &Fixture::setUserData);
		}

		b2Fixture * constructor(State & state, bool & managed);

		void destructor(State & state, b2Fixture * object);

		int getType(State & state, b2Fixture * object);

		int getShape(State & state, b2Fixture * object);

		int getSensor(State & state, b2Fixture * object);

		int setSensor(State & state, b2Fixture * object);

		int getFilter(State & state, b2Fixture * object);

		int setFilter(State & state, b2Fixture * object);

		int refilter(State & state, b2Fixture * object);

		int getBody(State & state, b2Fixture * object);

		int getFriction(State & state, b2Fixture * object);

		int setFriction(State & state, b2Fixture * object);

		int getRestitution(State & state, b2Fixture * object);

		int setRestitution(State & state, b2Fixture * object);

		int getDensity(State & state, b2Fixture * object);

		int setDensity(State & state, b2Fixture * object);

		int getAABB(State & state, b2Fixture * object);

		int testPoint(State & state, b2Fixture * object);

		int rayCast(State & state, b2Fixture * object);

		int getMassData(State & state, b2Fixture * object);

		int getNext(State & state, b2Fixture * object);

		int getUserData(State & state, b2Fixture * object);

		int setUserData(State & state, b2Fixture * object);
	};

	void initFixture(State * );
};

#endif