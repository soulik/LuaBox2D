#ifndef LUABOX2D_PULLEYJOINT_H
#define LUABOX2D_PULLEYJOINT_H

namespace LuaBox2D {
	class PulleyJoint : public Object<b2PulleyJoint> {
	private:
		Joint * base;
	public:
		explicit PulleyJoint(State * state) : Object<b2PulleyJoint>(state){
			base = state->getInterface<Joint>("LuaBox2D_Joint");
			LUTOK_PROPERTY("type", &PulleyJoint::getType, &PulleyJoint::nullMethod);
			LUTOK_PROPERTY("bodyA", &PulleyJoint::getBodyA, &PulleyJoint::nullMethod);
			LUTOK_PROPERTY("bodyB", &PulleyJoint::getBodyB, &PulleyJoint::nullMethod);

			LUTOK_PROPERTY("anchorA", &PulleyJoint::getAnchorA, &PulleyJoint::nullMethod);
			LUTOK_PROPERTY("anchorB", &PulleyJoint::getAnchorB, &PulleyJoint::nullMethod);

			LUTOK_METHOD("reactionForce", &PulleyJoint::getReactionForce);
			LUTOK_METHOD("reactionTorque", &PulleyJoint::getReactionTorque);

			LUTOK_PROPERTY("active", &PulleyJoint::getActive, &PulleyJoint::nullMethod);
			LUTOK_PROPERTY("collideConnected", &PulleyJoint::getCollideConnected, &PulleyJoint::nullMethod);

			LUTOK_PROPERTY("groundAnchorA", &PulleyJoint::getGroundAnchorA, &PulleyJoint::nullMethod);
			LUTOK_PROPERTY("groundAnchorB", &PulleyJoint::getGroundAnchorB, &PulleyJoint::nullMethod);
			LUTOK_PROPERTY("lengthA", &PulleyJoint::getLengthA, &PulleyJoint::nullMethod);
			LUTOK_PROPERTY("lengthB", &PulleyJoint::getLengthB, &PulleyJoint::nullMethod);
			LUTOK_PROPERTY("ratio", &PulleyJoint::getRatio, &PulleyJoint::nullMethod);
			LUTOK_PROPERTY("currentLengthA", &PulleyJoint::getCurrentLengthA, &PulleyJoint::nullMethod);
			LUTOK_PROPERTY("currentLengthB", &PulleyJoint::getCurrentLengthB, &PulleyJoint::nullMethod);

			LUTOK_METHOD("shiftOrigin", &PulleyJoint::shiftOrigin);
			LUTOK_PROPERTY("userData", &PulleyJoint::getUserData, &PulleyJoint::setUserData);
		}

		b2PulleyJoint * constructor(State & state, bool & managed);

		void destructor(State & state, b2PulleyJoint * object);

		int getType(State & state, b2PulleyJoint * );

		int getBodyA(State & state, b2PulleyJoint *);

		int getBodyB(State & state, b2PulleyJoint *);

		int getAnchorA(State & state, b2PulleyJoint *);

		int getAnchorB(State & state, b2PulleyJoint *);

		int getReactionForce(State & state, b2PulleyJoint *);

		int getReactionTorque(State & state, b2PulleyJoint *);

		int getActive(State & state, b2PulleyJoint * );

		int getCollideConnected(State & state, b2PulleyJoint * );

		int getGroundAnchorA(State & state, b2PulleyJoint * object);

		int getGroundAnchorB(State & state, b2PulleyJoint * object);

		int getLengthA(State & state, b2PulleyJoint * object);

		int getLengthB(State & state, b2PulleyJoint * object);

		int getRatio(State & state, b2PulleyJoint * object);

		int getCurrentLengthA(State & state, b2PulleyJoint * object);

		int getCurrentLengthB(State & state, b2PulleyJoint * object);

		int shiftOrigin(State & state, b2PulleyJoint * object);

		int getUserData(State & state, b2PulleyJoint * object);

		int setUserData(State & state, b2PulleyJoint * object);

	};

	void initPulleyJoint(State * );
};

#endif	
