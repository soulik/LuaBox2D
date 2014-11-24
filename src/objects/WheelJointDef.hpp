#ifndef LUABOX2D_WHEELJOINTDEF_H
#define LUABOX2D_WHEELJOINTDEF_H

namespace LuaBox2D {
	class WheelJointDef : public Object<b2WheelJointDef> {
	private:
		JointDef * base;
	public:
		explicit WheelJointDef(State * state) : Object<b2WheelJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &WheelJointDef::getType, &WheelJointDef::setType);
			LUTOK_PROPERTY("bodyA", &WheelJointDef::getBodyA, &WheelJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &WheelJointDef::getBodyB, &WheelJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &WheelJointDef::getCollideConnected, &WheelJointDef::setCollideConnected);
			LUTOK_METHOD("initialize", &WheelJointDef::initialize);

			LUTOK_PROPERTY("localAnchorA", &WheelJointDef::getLocalAnchorA, &WheelJointDef::setLocalAnchorA);
			LUTOK_PROPERTY("localAnchorB", &WheelJointDef::getLocalAnchorB, &WheelJointDef::setLocalAnchorB);
			LUTOK_PROPERTY("localAxisA", &WheelJointDef::getLocalAxisA, &WheelJointDef::setLocalAxisA);
			LUTOK_PROPERTY("enableMotor", &WheelJointDef::getEnableMotor, &WheelJointDef::setEnableMotor);
			LUTOK_PROPERTY("motorSpeed", &WheelJointDef::getMotorSpeed, &WheelJointDef::setMotorSpeed);
			LUTOK_PROPERTY("maxMotorTorque", &WheelJointDef::getMaxMotorTorque, &WheelJointDef::setMaxMotorTorque);
			LUTOK_PROPERTY("frequencyHz", &WheelJointDef::getFrequencyHz, &WheelJointDef::setFrequencyHz);
			LUTOK_PROPERTY("dampingRatio", &WheelJointDef::getDampingRatio, &WheelJointDef::setDampingRatio);
			LUTOK_PROPERTY("userData", &WheelJointDef::getUserData, &WheelJointDef::setUserData);
		}

		b2WheelJointDef * constructor(State & state, bool & managed);

		void destructor(State & state, b2WheelJointDef * object);

		int getBodyA(State & state, b2WheelJointDef * );

		int setBodyA(State & state, b2WheelJointDef * );

		int getBodyB(State & state, b2WheelJointDef * );

		int setBodyB(State & state, b2WheelJointDef * );

		int getType(State & state, b2WheelJointDef * );

		int setType(State & state, b2WheelJointDef * );

		int getCollideConnected(State & state, b2WheelJointDef * );

		int setCollideConnected(State & state, b2WheelJointDef * );

		int initialize(State & state, b2WheelJointDef * );

		int getLocalAnchorA(State & state, b2WheelJointDef * object);

		int setLocalAnchorA(State & state, b2WheelJointDef * object);

		int getLocalAnchorB(State & state, b2WheelJointDef * object);

		int setLocalAnchorB(State & state, b2WheelJointDef * object);

		int getLocalAxisA(State & state, b2WheelJointDef * object);

		int setLocalAxisA(State & state, b2WheelJointDef * object);

		int getEnableMotor(State & state, b2WheelJointDef * object);

		int setEnableMotor(State & state, b2WheelJointDef * object);

		int getMotorSpeed(State & state, b2WheelJointDef * object);

		int setMotorSpeed(State & state, b2WheelJointDef * object);

		int getMaxMotorTorque(State & state, b2WheelJointDef * object);

		int setMaxMotorTorque(State & state, b2WheelJointDef * object);

		int getFrequencyHz(State & state, b2WheelJointDef * object);

		int setFrequencyHz(State & state, b2WheelJointDef * object);

		int getDampingRatio(State & state, b2WheelJointDef * object);

		int setDampingRatio(State & state, b2WheelJointDef * object);

		int getUserData(State & state, b2WheelJointDef * object);

		int setUserData(State & state, b2WheelJointDef * object);
	};

	void initWheelJointDef(State * );
};

#endif	
