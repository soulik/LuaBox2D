#ifndef LUABOX2D_BODY_H
#define LUABOX2D_BODY_H

namespace LuaBox2D {
	class Body : public Object<b2Body> {
	public:
		explicit Body(State * state) : Object<b2Body>(state){
			LUTOK_PROPERTY("position", &Body::getPosition, &Body::nullMethod);
			LUTOK_PROPERTY("angle", &Body::getAngle, &Body::nullMethod);
			LUTOK_PROPERTY("worldCenter", &Body::getWorldCenter, &Body::nullMethod);
			LUTOK_PROPERTY("localCenter", &Body::getLocalCenter, &Body::nullMethod);

			LUTOK_PROPERTY("linearVelocity", &Body::getLinearVelocity, &Body::setLinearVelocity);
			LUTOK_PROPERTY("angularVelocity", &Body::getAngularVelocity, &Body::setAngularVelocity);

			LUTOK_METHOD("getTransform", &Body::getTransform);
			LUTOK_METHOD("setTransform", &Body::setTransform);

			LUTOK_METHOD("applyForce", &Body::applyForce);
			LUTOK_METHOD("applyForceToCenter", &Body::applyForceToCenter);
			LUTOK_METHOD("applyTorque", &Body::applyTorque);
			LUTOK_METHOD("applyLinearImpulse", &Body::applyLinearImpulse);
			LUTOK_METHOD("applyAngularImpulse", &Body::applyAngularImpulse);
			

			LUTOK_PROPERTY("mass", &Body::getMass, &Body::nullMethod);
			LUTOK_PROPERTY("inertia", &Body::getInertia, &Body::nullMethod);
			LUTOK_PROPERTY("massData", &Body::getMassData, &Body::setMassData);
			LUTOK_METHOD("resetMassData", &Body::resetMassData);
			
			LUTOK_METHOD("localPoint", &Body::getLocalPoint);
			LUTOK_METHOD("localVector", &Body::getLocalVector);
			LUTOK_METHOD("worldPoint", &Body::getWorldPoint);
			LUTOK_METHOD("worldVector", &Body::getWorldVector);
			LUTOK_METHOD("linearVelocityFromWorldPoint", &Body::getLinearVelocityFromWorldPoint);
			LUTOK_METHOD("linearVelocityFromLocalPoint", &Body::getLinearVelocityFromLocalPoint);

			LUTOK_PROPERTY("linearDamping", &Body::getLinearDamping, &Body::setLinearDamping);
			LUTOK_PROPERTY("angularDamping", &Body::getAngularDamping, &Body::setAngularDamping);
			LUTOK_PROPERTY("gravityScale", &Body::getGravityScale, &Body::setGravityScale);
			LUTOK_PROPERTY("type", &Body::getType, &Body::setType);
			LUTOK_PROPERTY("bullet", &Body::getBullet, &Body::setBullet);
			LUTOK_PROPERTY("allowSleeping", &Body::getSleepingAllowed, &Body::setSleepingAllowed);
			LUTOK_PROPERTY("awake", &Body::getAwake, &Body::setAwake);
			LUTOK_PROPERTY("active", &Body::getActive, &Body::setActive);
			LUTOK_PROPERTY("fixedRotation", &Body::getFixedRotation, &Body::setFixedRotation);

			LUTOK_PROPERTY("world", &Body::getWorld, &Body::nullMethod);
			LUTOK_METHOD("createFixture", &Body::createFixture);

			LUTOK_PROPERTY("fixture", &Body::getFixture, &Body::nullMethod);
			LUTOK_PROPERTY("joint", &Body::getJoint, &Body::nullMethod);
			LUTOK_PROPERTY("contact", &Body::getContact, &Body::nullMethod);

			LUTOK_PROPERTY("next", &Body::getNext, &Body::nullMethod);
			LUTOK_PROPERTY("userData", &Body::getUserData, &Body::setUserData);
		}

		b2Body * constructor(State & state, bool & managed);

		void destructor(State & state, b2Body * object);

		int getTransform(State & state, b2Body * object);

		int setTransform(State & state, b2Body * object);

		int getPosition(State & state, b2Body * object);

		int getAngle(State & state, b2Body * object);

		int getWorldCenter(State & state, b2Body * object);

		int getLocalCenter(State & state, b2Body * object);
		
		int getLinearVelocity(State & state, b2Body * object);

		int setLinearVelocity(State & state, b2Body * object);

		int getAngularVelocity(State & state, b2Body * object);

		int setAngularVelocity(State & state, b2Body * object);

		int applyForce(State & state, b2Body * object);

		int applyForceToCenter(State & state, b2Body * object);

		int applyTorque(State & state, b2Body * object);

		int applyLinearImpulse(State & state, b2Body * object);

		int applyAngularImpulse(State & state, b2Body * object);

		int getMass(State & state, b2Body * object);

		int getInertia(State & state, b2Body * object);

		int createFixture(State & state, b2Body * object);

		int getMassData(State & state, b2Body * object);

		int setMassData(State & state, b2Body * object);

		int resetMassData(State & state, b2Body * object);

		int getWorldPoint(State & state, b2Body * object);

		int getWorldVector(State & state, b2Body * object);

		int getLocalPoint(State & state, b2Body * object);

		int getLocalVector(State & state, b2Body * object);

		int getLinearVelocityFromWorldPoint(State & state, b2Body * object);
		
		int getLinearVelocityFromLocalPoint(State & state, b2Body * object);

		int getLinearDamping(State & state, b2Body * object);

		int setLinearDamping(State & state, b2Body * object);

		int getAngularDamping(State & state, b2Body * object);

		int setAngularDamping(State & state, b2Body * object);

		int getGravityScale(State & state, b2Body * object);

		int setGravityScale(State & state, b2Body * object);

		int getType(State & state, b2Body * object);

		int setType(State & state, b2Body * object);

		int getBullet(State & state, b2Body * object);

		int setBullet(State & state, b2Body * object);

		int getSleepingAllowed(State & state, b2Body * object);

		int setSleepingAllowed(State & state, b2Body * object);

		int getAwake(State & state, b2Body * object);

		int setAwake(State & state, b2Body * object);

		int getActive(State & state, b2Body * object);

		int setActive(State & state, b2Body * object);

		int getFixedRotation(State & state, b2Body * object);

		int setFixedRotation(State & state, b2Body * object);

		int getWorld(State & state, b2Body * object);

		int getFixture(State & state, b2Body * object);

		int getJoint(State & state, b2Body * object);

		int getContact(State & state, b2Body * object);

		int getNext(State & state, b2Body * object);

		int getUserData(State & state, b2Body * object);

		int setUserData(State & state, b2Body * object);

	};

	void initBody(State *);
};

#endif
