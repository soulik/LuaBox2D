#ifndef LUABOX2D_MOTORJOINTDEF_H
#define LUABOX2D_MOTORJOINTDEF_H

namespace LuaBox2D {
	class MotorJointDef : public Object<b2MotorJointDef> {
	private:
		JointDef * base;
	public:
		explicit MotorJointDef(State * state) : Object<b2MotorJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &MotorJointDef::getType, &MotorJointDef::setType);
			LUTOK_PROPERTY("bodyA", &MotorJointDef::getBodyA, &MotorJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &MotorJointDef::getBodyB, &MotorJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &MotorJointDef::getCollideConnected, &MotorJointDef::setCollideConnected);
			LUTOK_METHOD("initialize", &MotorJointDef::initialize);

			LUTOK_PROPERTY("linearOffset", &MotorJointDef::getLinearOffset, &MotorJointDef::setLinearOffset);
			LUTOK_PROPERTY("angularOffset", &MotorJointDef::getAngularOffset, &MotorJointDef::setAngularOffset);
			LUTOK_PROPERTY("maxForce", &MotorJointDef::getMaxForce, &MotorJointDef::setMaxForce);
			LUTOK_PROPERTY("maxTorque", &MotorJointDef::getMaxTorque, &MotorJointDef::setMaxTorque);
			LUTOK_PROPERTY("correctionFactor", &MotorJointDef::getCorrectionFactor, &MotorJointDef::setCorrectionFactor);
			LUTOK_PROPERTY("userData", &MotorJointDef::getUserData, &MotorJointDef::setUserData);
		}

		b2MotorJointDef * constructor(State & state, bool & managed);

		void destructor(State & state, b2MotorJointDef * object);

		int getBodyA(State & state, b2MotorJointDef * );

		int setBodyA(State & state, b2MotorJointDef * );

		int getBodyB(State & state, b2MotorJointDef * );

		int setBodyB(State & state, b2MotorJointDef * );

		int getType(State & state, b2MotorJointDef * );

		int setType(State & state, b2MotorJointDef * );

		int getCollideConnected(State & state, b2MotorJointDef * );

		int setCollideConnected(State & state, b2MotorJointDef * );

		int initialize(State & state, b2MotorJointDef * object);

		int getLinearOffset(State & state, b2MotorJointDef * object);

		int setLinearOffset(State & state, b2MotorJointDef * object);

		int getAngularOffset(State & state, b2MotorJointDef * object);

		int setAngularOffset(State & state, b2MotorJointDef * object);

		int getMaxForce(State & state, b2MotorJointDef * object);

		int setMaxForce(State & state, b2MotorJointDef * object);

		int getMaxTorque(State & state, b2MotorJointDef * object);

		int setMaxTorque(State & state, b2MotorJointDef * object);

		int getCorrectionFactor(State & state, b2MotorJointDef * object);

		int setCorrectionFactor(State & state, b2MotorJointDef * object);

		int getUserData(State & state, b2MotorJointDef * object);

		int setUserData(State & state, b2MotorJointDef * object);
	};

	void initMotorJointDef(State * );
};

#endif	
