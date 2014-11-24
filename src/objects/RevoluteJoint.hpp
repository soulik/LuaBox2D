#ifndef LUABOX2D_REVOLUTEJOINT_H
#define LUABOX2D_REVOLUTEJOINT_H

namespace LuaBox2D {
	class RevoluteJoint : public Object<b2RevoluteJoint> {
	private:
		Joint * base;
	public:
		explicit RevoluteJoint(State * state) : Object<b2RevoluteJoint>(state){
			base = state->getInterface<Joint>("LuaBox2D_Joint");
			LUTOK_PROPERTY("type", &RevoluteJoint::getType, &RevoluteJoint::nullMethod);
			LUTOK_PROPERTY("bodyA", &RevoluteJoint::getBodyA, &RevoluteJoint::nullMethod);
			LUTOK_PROPERTY("bodyB", &RevoluteJoint::getBodyB, &RevoluteJoint::nullMethod);

			LUTOK_PROPERTY("anchorA", &RevoluteJoint::getAnchorA, &RevoluteJoint::nullMethod);
			LUTOK_PROPERTY("anchorB", &RevoluteJoint::getAnchorB, &RevoluteJoint::nullMethod);

			LUTOK_METHOD("reactionForce", &RevoluteJoint::getReactionForce);
			LUTOK_METHOD("reactionTorque", &RevoluteJoint::getReactionTorque);
			LUTOK_METHOD("motorTorque", &RevoluteJoint::getMotorTorque);

			LUTOK_PROPERTY("active", &RevoluteJoint::getActive, &RevoluteJoint::nullMethod);
			LUTOK_PROPERTY("collideConnected", &RevoluteJoint::getCollideConnected, &RevoluteJoint::nullMethod);

			LUTOK_PROPERTY("localAnchorA", &RevoluteJoint::getLocalAnchorA, &RevoluteJoint::nullMethod);
			LUTOK_PROPERTY("localAnchorB", &RevoluteJoint::getLocalAnchorB, &RevoluteJoint::nullMethod);
			LUTOK_PROPERTY("referenceAngle", &RevoluteJoint::getReferenceAngle, &RevoluteJoint::nullMethod);
			LUTOK_PROPERTY("enableLimit", &RevoluteJoint::getEnableLimit, &RevoluteJoint::setEnableLimit);
			LUTOK_PROPERTY("lowerLimit", &RevoluteJoint::getLowerLimit, &RevoluteJoint::nullMethod);
			LUTOK_PROPERTY("upperLimit", &RevoluteJoint::getUpperLimit, &RevoluteJoint::nullMethod);
			LUTOK_METHOD("setLimits", &RevoluteJoint::setLimits);
			LUTOK_PROPERTY("enableMotor", &RevoluteJoint::getEnableMotor, &RevoluteJoint::setEnableMotor);
			LUTOK_PROPERTY("motorSpeed", &RevoluteJoint::getMotorSpeed, &RevoluteJoint::setMotorSpeed);
			LUTOK_PROPERTY("maxMotorTorque", &RevoluteJoint::getMaxMotorTorque, &RevoluteJoint::setMaxMotorTorque);
			LUTOK_PROPERTY("userData", &RevoluteJoint::getUserData, &RevoluteJoint::setUserData);
		}

		b2RevoluteJoint * constructor(State & state, bool & managed);

		void destructor(State & state, b2RevoluteJoint * object);

		int getType(State & state, b2RevoluteJoint * );

		int getBodyA(State & state, b2RevoluteJoint *);

		int getBodyB(State & state, b2RevoluteJoint *);

		int getAnchorA(State & state, b2RevoluteJoint *);

		int getAnchorB(State & state, b2RevoluteJoint *);

		int getReactionForce(State & state, b2RevoluteJoint *);

		int getReactionTorque(State & state, b2RevoluteJoint *);

		int getMotorTorque(State & state, b2RevoluteJoint *);

		int getActive(State & state, b2RevoluteJoint * );

		int getCollideConnected(State & state, b2RevoluteJoint * );

		int getLocalAnchorA(State & state, b2RevoluteJoint * object);

		int getLocalAnchorB(State & state, b2RevoluteJoint * object);

		int getReferenceAngle(State & state, b2RevoluteJoint * object);

		int getEnableLimit(State & state, b2RevoluteJoint * object);

		int setEnableLimit(State & state, b2RevoluteJoint * object);

		int getLowerLimit(State & state, b2RevoluteJoint * object);

		int getUpperLimit(State & state, b2RevoluteJoint * object);

		int setLimits(State & state, b2RevoluteJoint * object);

		int getEnableMotor(State & state, b2RevoluteJoint * object);

		int setEnableMotor(State & state, b2RevoluteJoint * object);

		int getMotorSpeed(State & state, b2RevoluteJoint * object);

		int setMotorSpeed(State & state, b2RevoluteJoint * object);

		int getMaxMotorTorque(State & state, b2RevoluteJoint * object);

		int setMaxMotorTorque(State & state, b2RevoluteJoint * object);

		int getUserData(State & state, b2RevoluteJoint * object);

		int setUserData(State & state, b2RevoluteJoint * object);

	};

	void initRevoluteJoint(State * );
};

#endif	
