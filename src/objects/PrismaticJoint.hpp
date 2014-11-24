#ifndef LUABOX2D_PRISMATICJOINT_H
#define LUABOX2D_PRISMATICJOINT_H

namespace LuaBox2D {
	class PrismaticJoint : public Object<b2PrismaticJoint> {
	private:
		Joint * base;
	public:
		explicit PrismaticJoint(State * state) : Object<b2PrismaticJoint>(state){
			base = state->getInterface<Joint>("LuaBox2D_Joint");
			LUTOK_PROPERTY("type", &PrismaticJoint::getType, &PrismaticJoint::nullMethod);
			LUTOK_PROPERTY("bodyA", &PrismaticJoint::getBodyA, &PrismaticJoint::nullMethod);
			LUTOK_PROPERTY("bodyB", &PrismaticJoint::getBodyB, &PrismaticJoint::nullMethod);

			LUTOK_PROPERTY("anchorA", &PrismaticJoint::getAnchorA, &PrismaticJoint::nullMethod);
			LUTOK_PROPERTY("anchorB", &PrismaticJoint::getAnchorB, &PrismaticJoint::nullMethod);

			LUTOK_METHOD("reactionForce", &PrismaticJoint::getReactionForce);
			LUTOK_METHOD("reactionTorque", &PrismaticJoint::getReactionTorque);

			LUTOK_PROPERTY("active", &PrismaticJoint::getActive, &PrismaticJoint::nullMethod);
			LUTOK_PROPERTY("collideConnected", &PrismaticJoint::getCollideConnected, &PrismaticJoint::nullMethod);

			LUTOK_PROPERTY("localAnchorA", &PrismaticJoint::getLocalAnchorA, &PrismaticJoint::nullMethod);
			LUTOK_PROPERTY("localAnchorB", &PrismaticJoint::getLocalAnchorB, &PrismaticJoint::nullMethod);
			LUTOK_PROPERTY("localAxisA", &PrismaticJoint::getLocalAxisA, &PrismaticJoint::nullMethod);

			LUTOK_PROPERTY("referenceAngle", &PrismaticJoint::getReferenceAngle, &PrismaticJoint::nullMethod);
			LUTOK_PROPERTY("enableLimit", &PrismaticJoint::getEnableLimit, &PrismaticJoint::setEnableLimit);
			LUTOK_PROPERTY("lowerLimit", &PrismaticJoint::getLowerLimit, &PrismaticJoint::nullMethod);
			LUTOK_PROPERTY("upperLimit", &PrismaticJoint::getUpperLimit, &PrismaticJoint::nullMethod);
			LUTOK_METHOD("setLimits", &PrismaticJoint::setLimits);
			LUTOK_PROPERTY("enableMotor", &PrismaticJoint::getEnableMotor, &PrismaticJoint::setEnableMotor);
			LUTOK_PROPERTY("motorSpeed", &PrismaticJoint::getMotorSpeed, &PrismaticJoint::setMotorSpeed);
			LUTOK_PROPERTY("maxMotorForce", &PrismaticJoint::getMaxMotorForce, &PrismaticJoint::setMaxMotorForce);
			LUTOK_PROPERTY("userData", &PrismaticJoint::getUserData, &PrismaticJoint::setUserData);
		}

		b2PrismaticJoint * constructor(State & state, bool & managed);

		void destructor(State & state, b2PrismaticJoint * object);

		int getType(State & state, b2PrismaticJoint * );

		int getBodyA(State & state, b2PrismaticJoint *);

		int getBodyB(State & state, b2PrismaticJoint *);

		int getAnchorA(State & state, b2PrismaticJoint *);

		int getAnchorB(State & state, b2PrismaticJoint *);

		int getReactionForce(State & state, b2PrismaticJoint *);

		int getReactionTorque(State & state, b2PrismaticJoint *);

		int getActive(State & state, b2PrismaticJoint * );

		int getCollideConnected(State & state, b2PrismaticJoint * );

		int getLocalAnchorA(State & state, b2PrismaticJoint *);

		int getLocalAnchorB(State & state, b2PrismaticJoint *);

		int getLocalAxisA(State & state, b2PrismaticJoint *);

		int getReferenceAngle(State & state, b2PrismaticJoint * object);

		int getEnableLimit(State & state, b2PrismaticJoint * object);

		int setEnableLimit(State & state, b2PrismaticJoint * object);

		int getLowerLimit(State & state, b2PrismaticJoint * object);

		int getUpperLimit(State & state, b2PrismaticJoint * object);

		int setLimits(State & state, b2PrismaticJoint * object);

		int getEnableMotor(State & state, b2PrismaticJoint * object);

		int setEnableMotor(State & state, b2PrismaticJoint * object);

		int getMotorSpeed(State & state, b2PrismaticJoint * object);

		int setMotorSpeed(State & state, b2PrismaticJoint * object);

		int getMaxMotorForce(State & state, b2PrismaticJoint * object);

		int setMaxMotorForce(State & state, b2PrismaticJoint * object);

		int getUserData(State & state, b2PrismaticJoint * object);

		int setUserData(State & state, b2PrismaticJoint * object);

	};

	void initPrismaticJoint(State * );
};

#endif	
