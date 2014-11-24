#ifndef LUABOX2D_PRISMATICJOINTDEF_H
#define LUABOX2D_PRISMATICJOINTDEF_H

namespace LuaBox2D {
	class PrismaticJointDef : public Object<b2PrismaticJointDef> {
	private:
		JointDef * base;
	public:
		explicit PrismaticJointDef(State * state) : Object<b2PrismaticJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &PrismaticJointDef::getType, &PrismaticJointDef::setType);
			LUTOK_PROPERTY("bodyA", &PrismaticJointDef::getBodyA, &PrismaticJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &PrismaticJointDef::getBodyB, &PrismaticJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &PrismaticJointDef::getCollideConnected, &PrismaticJointDef::setCollideConnected);
			LUTOK_METHOD("initialize", &PrismaticJointDef::initialize);

			LUTOK_PROPERTY("localAnchorA", &PrismaticJointDef::getLocalAnchorA, &PrismaticJointDef::setLocalAnchorA);
			LUTOK_PROPERTY("localAnchorB", &PrismaticJointDef::getLocalAnchorB, &PrismaticJointDef::setLocalAnchorB);
			LUTOK_PROPERTY("localAxisA", &PrismaticJointDef::getLocalAxisA, &PrismaticJointDef::setLocalAxisA);
			LUTOK_PROPERTY("referenceAngle", &PrismaticJointDef::getReferenceAngle, &PrismaticJointDef::setReferenceAngle);
			LUTOK_PROPERTY("enableLimit", &PrismaticJointDef::getEnableLimit, &PrismaticJointDef::setEnableLimit);
			LUTOK_PROPERTY("lowerTranslation", &PrismaticJointDef::getLowerTranslation, &PrismaticJointDef::setLowerTranslation);
			LUTOK_PROPERTY("upperTranslation", &PrismaticJointDef::getUpperTranslation, &PrismaticJointDef::setUpperTranslation);
			LUTOK_PROPERTY("enableMotor", &PrismaticJointDef::getEnableMotor, &PrismaticJointDef::setEnableMotor);
			LUTOK_PROPERTY("motorSpeed", &PrismaticJointDef::getMotorSpeed, &PrismaticJointDef::setMotorSpeed);
			LUTOK_PROPERTY("maxMotorForce", &PrismaticJointDef::getMaxMotorForce, &PrismaticJointDef::setMaxMotorForce);
			LUTOK_PROPERTY("userData", &PrismaticJointDef::getUserData, &PrismaticJointDef::setUserData);

		}

		b2PrismaticJointDef * constructor(State & state, bool & managed);

		void destructor(State & state, b2PrismaticJointDef * object);

		int getBodyA(State & state, b2PrismaticJointDef * );

		int setBodyA(State & state, b2PrismaticJointDef * );

		int getBodyB(State & state, b2PrismaticJointDef * );

		int setBodyB(State & state, b2PrismaticJointDef * );

		int getType(State & state, b2PrismaticJointDef * );

		int setType(State & state, b2PrismaticJointDef * );

		int getCollideConnected(State & state, b2PrismaticJointDef * );

		int setCollideConnected(State & state, b2PrismaticJointDef * );

		int initialize(State & state, b2PrismaticJointDef * );

		int getLocalAnchorA(State & state, b2PrismaticJointDef * object);

		int setLocalAnchorA(State & state, b2PrismaticJointDef * object);

		int getLocalAnchorB(State & state, b2PrismaticJointDef * object);

		int setLocalAnchorB(State & state, b2PrismaticJointDef * object);

		int getLocalAxisA(State & state, b2PrismaticJointDef * object);

		int setLocalAxisA(State & state, b2PrismaticJointDef * object);

		int getReferenceAngle(State & state, b2PrismaticJointDef * object);

		int setReferenceAngle(State & state, b2PrismaticJointDef * object);

		int getEnableLimit(State & state, b2PrismaticJointDef * object);

		int setEnableLimit(State & state, b2PrismaticJointDef * object);

		int getLowerTranslation(State & state, b2PrismaticJointDef * object);

		int setLowerTranslation(State & state, b2PrismaticJointDef * object);

		int getUpperTranslation(State & state, b2PrismaticJointDef * object);

		int setUpperTranslation(State & state, b2PrismaticJointDef * object);

		int getEnableMotor(State & state, b2PrismaticJointDef * object);

		int setEnableMotor(State & state, b2PrismaticJointDef * object);

		int getMotorSpeed(State & state, b2PrismaticJointDef * object);

		int setMotorSpeed(State & state, b2PrismaticJointDef * object);

		int getMaxMotorForce(State & state, b2PrismaticJointDef * object);

		int setMaxMotorForce(State & state, b2PrismaticJointDef * object);

		int getUserData(State & state, b2PrismaticJointDef * object);

		int setUserData(State & state, b2PrismaticJointDef * object);

	};

	void initPrismaticJointDef(State * );
};

#endif	
