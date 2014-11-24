#ifndef LUABOX2D_WHEELJOINT_H
#define LUABOX2D_WHEELJOINT_H

namespace LuaBox2D {
	class WheelJoint : public Object<b2WheelJoint> {
	private:
		Joint * base;
	public:
		explicit WheelJoint(State * state) : Object<b2WheelJoint>(state){
			base = state->getInterface<Joint>("LuaBox2D_Joint");
			LUTOK_PROPERTY("type", &WheelJoint::getType, &WheelJoint::nullMethod);
			LUTOK_PROPERTY("bodyA", &WheelJoint::getBodyA, &WheelJoint::nullMethod);
			LUTOK_PROPERTY("bodyB", &WheelJoint::getBodyB, &WheelJoint::nullMethod);

			LUTOK_PROPERTY("anchorA", &WheelJoint::getAnchorA, &WheelJoint::nullMethod);
			LUTOK_PROPERTY("anchorB", &WheelJoint::getAnchorB, &WheelJoint::nullMethod);

			LUTOK_METHOD("reactionForce", &WheelJoint::getReactionForce);
			LUTOK_METHOD("reactionTorque", &WheelJoint::getReactionTorque);
			LUTOK_METHOD("motorTorque", &WheelJoint::getMotorTorque);

			LUTOK_PROPERTY("active", &WheelJoint::getActive, &WheelJoint::nullMethod);
			LUTOK_PROPERTY("collideConnected", &WheelJoint::getCollideConnected, &WheelJoint::nullMethod);

			LUTOK_PROPERTY("localAnchorA", &WheelJoint::getLocalAnchorA, &WheelJoint::nullMethod);
			LUTOK_PROPERTY("localAnchorB", &WheelJoint::getLocalAnchorB, &WheelJoint::nullMethod);
			LUTOK_PROPERTY("localAxisA", &WheelJoint::getLocalAxisA, &WheelJoint::nullMethod);
			LUTOK_PROPERTY("enableMotor", &WheelJoint::getEnableMotor, &WheelJoint::setEnableMotor);
			LUTOK_PROPERTY("motorSpeed", &WheelJoint::getMotorSpeed, &WheelJoint::setMotorSpeed);
			LUTOK_PROPERTY("maxMotorTorque", &WheelJoint::getMaxMotorTorque, &WheelJoint::setMaxMotorTorque);
			LUTOK_PROPERTY("springFrequencyHz", &WheelJoint::getSpringFrequencyHz, &WheelJoint::setSpringFrequencyHz);
			LUTOK_PROPERTY("springDampingRatio", &WheelJoint::getSpringDampingRatio, &WheelJoint::setSpringDampingRatio);

			LUTOK_PROPERTY("jointTranslation", &WheelJoint::getJointTranslation, &WheelJoint::nullMethod);
			LUTOK_PROPERTY("jointSpeed", &WheelJoint::getJointSpeed, &WheelJoint::nullMethod);
			LUTOK_PROPERTY("userData", &WheelJoint::getUserData, &WheelJoint::setUserData);
		}

		b2WheelJoint * constructor(State & state, bool & managed);

		void destructor(State & state, b2WheelJoint * object);

		int getType(State & state, b2WheelJoint * );

		int getBodyA(State & state, b2WheelJoint *);

		int getBodyB(State & state, b2WheelJoint *);

		int getAnchorA(State & state, b2WheelJoint *);

		int getAnchorB(State & state, b2WheelJoint *);

		int getReactionForce(State & state, b2WheelJoint *);

		int getReactionTorque(State & state, b2WheelJoint *);

		int getMotorTorque(State & state, b2WheelJoint *);

		int getActive(State & state, b2WheelJoint * );

		int getCollideConnected(State & state, b2WheelJoint * );

		int getLocalAnchorA(State & state, b2WheelJoint * object);

		int getLocalAnchorB(State & state, b2WheelJoint * object);

		int getLocalAxisA(State & state, b2WheelJoint * object);

		int getEnableMotor(State & state, b2WheelJoint * object);

		int setEnableMotor(State & state, b2WheelJoint * object);

		int getMotorSpeed(State & state, b2WheelJoint * object);

		int setMotorSpeed(State & state, b2WheelJoint * object);

		int getMaxMotorTorque(State & state, b2WheelJoint * object);

		int setMaxMotorTorque(State & state, b2WheelJoint * object);

		int getSpringFrequencyHz(State & state, b2WheelJoint * object);

		int setSpringFrequencyHz(State & state, b2WheelJoint * object);

		int getSpringDampingRatio(State & state, b2WheelJoint * object);

		int setSpringDampingRatio(State & state, b2WheelJoint * object);

		int getJointTranslation(State & state, b2WheelJoint * object);

		int getJointSpeed(State & state, b2WheelJoint * object);

		int getUserData(State & state, b2WheelJoint * object);

		int setUserData(State & state, b2WheelJoint * object);

	};

	void initWheelJoint(State * );
};

#endif	
