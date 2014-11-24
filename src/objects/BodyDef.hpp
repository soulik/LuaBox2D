#ifndef LUABOX2D_BODYDEF_H
#define LUABOX2D_BODYDEF_H

namespace LuaBox2D {
	b2BodyType stringToBodyType(const std::string &);
	std::string bodyTypeToString(const b2BodyType);

	class BodyDef : public Object<b2BodyDef> {
	public:
		explicit BodyDef(State * state) : Object<b2BodyDef>(state){
			LUTOK_PROPERTY("type", &BodyDef::getBodyType, &BodyDef::setBodyType);
			LUTOK_PROPERTY("position", &BodyDef::getPosition, &BodyDef::setPosition);
			LUTOK_PROPERTY("angle", &BodyDef::getAngle, &BodyDef::setAngle);
			LUTOK_PROPERTY("linearVelocity", &BodyDef::getLinearVelocity, &BodyDef::setLinearVelocity);
			LUTOK_PROPERTY("angularVelocity", &BodyDef::getAngularVelocity, &BodyDef::setAngularVelocity);
			LUTOK_PROPERTY("linearDamping", &BodyDef::getLinearDamping, &BodyDef::setLinearDamping);
			LUTOK_PROPERTY("angularDamping", &BodyDef::getAngularDamping, &BodyDef::setAngularDamping);

			LUTOK_PROPERTY("allowSleep", &BodyDef::getAllowSleep, &BodyDef::setAllowSleep);
			LUTOK_PROPERTY("awake", &BodyDef::getAwake, &BodyDef::setAwake);
			LUTOK_PROPERTY("fixedRotation", &BodyDef::getFixedRotation, &BodyDef::setFixedRotation);
			LUTOK_PROPERTY("bullet", &BodyDef::getBullet, &BodyDef::setBullet);
			LUTOK_PROPERTY("active", &BodyDef::getActive, &BodyDef::setActive);

			LUTOK_PROPERTY("gravityScale", &BodyDef::getGravityScale, &BodyDef::setGravityScale);

			LUTOK_PROPERTY("userData", &BodyDef::getUserData, &BodyDef::setUserData);
		}

		b2BodyDef * constructor(State & state, bool & managed);

		void destructor(State & state, b2BodyDef * object);

		int getBodyType(State & state, b2BodyDef * object);

		int setBodyType(State & state, b2BodyDef * object);

		int getPosition(State & state, b2BodyDef * object);

		int setPosition(State & state, b2BodyDef * object);

		int getAngle(State & state, b2BodyDef * object);

		int setAngle(State & state, b2BodyDef * object);

		int getLinearVelocity(State & state, b2BodyDef * object);

		int setLinearVelocity(State & state, b2BodyDef * object);

		int getAngularVelocity(State & state, b2BodyDef * object);

		int setAngularVelocity(State & state, b2BodyDef * object);

		int getLinearDamping(State & state, b2BodyDef * object);

		int setLinearDamping(State & state, b2BodyDef * object);

		int getAngularDamping(State & state, b2BodyDef * object);

		int setAngularDamping(State & state, b2BodyDef * object);

		int getAllowSleep(State & state, b2BodyDef * object);

		int setAllowSleep(State & state, b2BodyDef * object);

		int getAwake(State & state, b2BodyDef * object);

		int setAwake(State & state, b2BodyDef * object);

		int getFixedRotation(State & state, b2BodyDef * object);

		int setFixedRotation(State & state, b2BodyDef * object);

		int getBullet(State & state, b2BodyDef * object);

		int setBullet(State & state, b2BodyDef * object);

		int getActive(State & state, b2BodyDef * object);

		int setActive(State & state, b2BodyDef * object);

		int getGravityScale(State & state, b2BodyDef * object);

		int setGravityScale(State & state, b2BodyDef * object);

		int getUserData(State & state, b2BodyDef * object);

		int setUserData(State & state, b2BodyDef * object);
	};

	void initBodyDef(State *);
};

#endif
