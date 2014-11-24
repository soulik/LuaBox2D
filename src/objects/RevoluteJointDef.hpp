#ifndef LUABOX2D_REVOLUTEJOINTDEF_H
#define LUABOX2D_REVOLUTEJOINTDEF_H

namespace LuaBox2D {
	class RevoluteJointDef : public Object<b2RevoluteJointDef> {
	private:
		JointDef * base;
	public:
		explicit RevoluteJointDef(State * state) : Object<b2RevoluteJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &RevoluteJointDef::getType, &RevoluteJointDef::setType);
			LUTOK_PROPERTY("bodyA", &RevoluteJointDef::getBodyA, &RevoluteJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &RevoluteJointDef::getBodyB, &RevoluteJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &RevoluteJointDef::getCollideConnected, &RevoluteJointDef::setCollideConnected);
			LUTOK_METHOD("initialize", &RevoluteJointDef::initialize);

			LUTOK_PROPERTY("localAnchorA", &RevoluteJointDef::getLocalAnchorA, &RevoluteJointDef::setLocalAnchorA);
			LUTOK_PROPERTY("localAnchorB", &RevoluteJointDef::getLocalAnchorB, &RevoluteJointDef::setLocalAnchorB);
			LUTOK_PROPERTY("referenceAngle", &RevoluteJointDef::getReferenceAngle, &RevoluteJointDef::setReferenceAngle);
			LUTOK_PROPERTY("enableLimit", &RevoluteJointDef::getEnableLimit, &RevoluteJointDef::setEnableLimit);
			LUTOK_PROPERTY("lowerAngle", &RevoluteJointDef::getLowerAngle, &RevoluteJointDef::setLowerAngle);
			LUTOK_PROPERTY("upperAngle", &RevoluteJointDef::getUpperAngle, &RevoluteJointDef::setUpperAngle);
			LUTOK_PROPERTY("enableMotor", &RevoluteJointDef::getEnableMotor, &RevoluteJointDef::setEnableMotor);
			LUTOK_PROPERTY("motorSpeed", &RevoluteJointDef::getMotorSpeed, &RevoluteJointDef::setMotorSpeed);
			LUTOK_PROPERTY("maxMotorTorque", &RevoluteJointDef::getMaxMotorTorque, &RevoluteJointDef::setMaxMotorTorque);
			LUTOK_PROPERTY("userData", &RevoluteJointDef::getUserData, &RevoluteJointDef::setUserData);
		}

		b2RevoluteJointDef * constructor(State & state, bool & managed);

		void destructor(State & state, b2RevoluteJointDef * object);

		int getBodyA(State & state, b2RevoluteJointDef * );

		int setBodyA(State & state, b2RevoluteJointDef * );

		int getBodyB(State & state, b2RevoluteJointDef * );

		int setBodyB(State & state, b2RevoluteJointDef * );

		int getType(State & state, b2RevoluteJointDef * );

		int setType(State & state, b2RevoluteJointDef * );

		int getCollideConnected(State & state, b2RevoluteJointDef * );

		int setCollideConnected(State & state, b2RevoluteJointDef * );

		int initialize(State & state, b2RevoluteJointDef * );

		int getLocalAnchorA(State & state, b2RevoluteJointDef * object);

		int setLocalAnchorA(State & state, b2RevoluteJointDef * object);

		int getLocalAnchorB(State & state, b2RevoluteJointDef * object);

		int setLocalAnchorB(State & state, b2RevoluteJointDef * object);

		int getReferenceAngle(State & state, b2RevoluteJointDef * object);

		int setReferenceAngle(State & state, b2RevoluteJointDef * object);

		int getEnableLimit(State & state, b2RevoluteJointDef * object);

		int setEnableLimit(State & state, b2RevoluteJointDef * object);

		int getLowerAngle(State & state, b2RevoluteJointDef * object);

		int setLowerAngle(State & state, b2RevoluteJointDef * object);

		int getUpperAngle(State & state, b2RevoluteJointDef * object);

		int setUpperAngle(State & state, b2RevoluteJointDef * object);

		int getEnableMotor(State & state, b2RevoluteJointDef * object);

		int setEnableMotor(State & state, b2RevoluteJointDef * object);

		int getMotorSpeed(State & state, b2RevoluteJointDef * object);

		int setMotorSpeed(State & state, b2RevoluteJointDef * object);

		int getMaxMotorTorque(State & state, b2RevoluteJointDef * object);

		int setMaxMotorTorque(State & state, b2RevoluteJointDef * object);

		int getUserData(State & state, b2RevoluteJointDef * object);

		int setUserData(State & state, b2RevoluteJointDef * object);
	};

	void initRevoluteJointDef(State * );
};

#endif	
