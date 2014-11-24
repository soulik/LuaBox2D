#ifndef LUABOX2D_MOTORJOINT_H
#define LUABOX2D_MOTORJOINT_H

namespace LuaBox2D {
	class MotorJoint : public Object<b2MotorJoint> {
	private:
		Joint * base;
	public:
		explicit MotorJoint(State * state) : Object<b2MotorJoint>(state){
			base = state->getInterface<Joint>("LuaBox2D_Joint");
			LUTOK_PROPERTY("type", &MotorJoint::getType, &MotorJoint::nullMethod);
			LUTOK_PROPERTY("bodyA", &MotorJoint::getBodyA, &MotorJoint::nullMethod);
			LUTOK_PROPERTY("bodyB", &MotorJoint::getBodyB, &MotorJoint::nullMethod);

			LUTOK_PROPERTY("anchorA", &MotorJoint::getAnchorA, &MotorJoint::nullMethod);
			LUTOK_PROPERTY("anchorB", &MotorJoint::getAnchorB, &MotorJoint::nullMethod);

			LUTOK_METHOD("reactionForce", &MotorJoint::getReactionForce);
			LUTOK_METHOD("reactionTorque", &MotorJoint::getReactionTorque);

			LUTOK_PROPERTY("active", &MotorJoint::getActive, &MotorJoint::nullMethod);
			LUTOK_PROPERTY("collideConnected", &MotorJoint::getCollideConnected, &MotorJoint::nullMethod);

			LUTOK_PROPERTY("linearOffset", &MotorJoint::getLinearOffset, &MotorJoint::setLinearOffset);
			LUTOK_PROPERTY("angularOffset", &MotorJoint::getAngularOffset, &MotorJoint::setAngularOffset);
			LUTOK_PROPERTY("maxForce", &MotorJoint::getMaxForce, &MotorJoint::setMaxForce);
			LUTOK_PROPERTY("maxTorque", &MotorJoint::getMaxTorque, &MotorJoint::setMaxTorque);
			LUTOK_PROPERTY("correctionFactor", &MotorJoint::getCorrectionFactor, &MotorJoint::setCorrectionFactor);
			LUTOK_PROPERTY("userData", &MotorJoint::getUserData, &MotorJoint::setUserData);
		}

		b2MotorJoint * constructor(State & state, bool & managed);

		void destructor(State & state, b2MotorJoint * object);

		int getType(State & state, b2MotorJoint * );

		int getBodyA(State & state, b2MotorJoint *);

		int getBodyB(State & state, b2MotorJoint *);

		int getAnchorA(State & state, b2MotorJoint *);

		int getAnchorB(State & state, b2MotorJoint *);

		int getReactionForce(State & state, b2MotorJoint *);

		int getReactionTorque(State & state, b2MotorJoint *);

		int getActive(State & state, b2MotorJoint * );

		int getCollideConnected(State & state, b2MotorJoint * );

		int getLinearOffset(State & state, b2MotorJoint * object);

		int setLinearOffset(State & state, b2MotorJoint * object);

		int getAngularOffset(State & state, b2MotorJoint * object);

		int setAngularOffset(State & state, b2MotorJoint * object);

		int getMaxForce(State & state, b2MotorJoint * object);

		int setMaxForce(State & state, b2MotorJoint * object);

		int getMaxTorque(State & state, b2MotorJoint * object);

		int setMaxTorque(State & state, b2MotorJoint * object);

		int getCorrectionFactor(State & state, b2MotorJoint * object);

		int setCorrectionFactor(State & state, b2MotorJoint * object);

		int getUserData(State & state, b2MotorJoint * object);

		int setUserData(State & state, b2MotorJoint * object);

	};

	void initMotorJoint(State * );
};

#endif	
