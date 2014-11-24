#ifndef LUABOX2D_FIXTUREDEF_H
#define LUABOX2D_FIXTUREDEF_H

namespace LuaBox2D {
	class FixtureDef : public Object<b2FixtureDef> {
	public:
		explicit FixtureDef(State * state) : Object<b2FixtureDef>(state){
			LUTOK_PROPERTY("friction", &FixtureDef::getFriction, &FixtureDef::setFriction);
			LUTOK_PROPERTY("restitution", &FixtureDef::getRestitution, &FixtureDef::setRestitution);
			LUTOK_PROPERTY("density", &FixtureDef::getDensity, &FixtureDef::setDensity);
			LUTOK_PROPERTY("sensor", &FixtureDef::getSensor, &FixtureDef::setSensor);
			LUTOK_PROPERTY("filter", &FixtureDef::getFilter, &FixtureDef::setFilter);
			LUTOK_PROPERTY("shape", &FixtureDef::getShape, &FixtureDef::setShape);

			LUTOK_PROPERTY("userData", &FixtureDef::getUserData, &FixtureDef::setUserData);
		}

		b2FixtureDef * constructor(State & state, bool & managed);

		void destructor(State & state, b2FixtureDef * object);

		int getFriction(State & state, b2FixtureDef * object);

		int setFriction(State & state, b2FixtureDef * object);

		int getRestitution(State & state, b2FixtureDef * object);

		int setRestitution(State & state, b2FixtureDef * object);

		int getDensity(State & state, b2FixtureDef * object);

		int setDensity(State & state, b2FixtureDef * object);

		int getSensor(State & state, b2FixtureDef * object);

		int setSensor(State & state, b2FixtureDef * object);

		int getFilter(State & state, b2FixtureDef * object);

		int setFilter(State & state, b2FixtureDef * object);

		int getShape(State & state, b2FixtureDef * object);

		int setShape(State & state, b2FixtureDef * object);

		int getUserData(State & state, b2FixtureDef * object);

		int setUserData(State & state, b2FixtureDef * object);

};

	void initFixtureDef(State * );

};

#endif