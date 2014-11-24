#ifndef LUABOX2D_WELDJOINT_H
#define LUABOX2D_WELDJOINT_H

namespace LuaBox2D {
	class WeldJoint : public Object<b2WeldJoint> {
	private:
		Joint * base;
	public:
		explicit WeldJoint(State * state) : Object<b2WeldJoint>(state){
			base = state->getInterface<Joint>("LuaBox2D_Joint");
			LUTOK_PROPERTY("type", &WeldJoint::getType, &WeldJoint::nullMethod);
			LUTOK_PROPERTY("bodyA", &WeldJoint::getBodyA, &WeldJoint::nullMethod);
			LUTOK_PROPERTY("bodyB", &WeldJoint::getBodyB, &WeldJoint::nullMethod);

			LUTOK_PROPERTY("anchorA", &WeldJoint::getAnchorA, &WeldJoint::nullMethod);
			LUTOK_PROPERTY("anchorB", &WeldJoint::getAnchorB, &WeldJoint::nullMethod);

			LUTOK_METHOD("reactionForce", &WeldJoint::getReactionForce);
			LUTOK_METHOD("reactionTorque", &WeldJoint::getReactionTorque);

			LUTOK_PROPERTY("active", &WeldJoint::getActive, &WeldJoint::nullMethod);
			LUTOK_PROPERTY("collideConnected", &WeldJoint::getCollideConnected, &WeldJoint::nullMethod);

			LUTOK_PROPERTY("localAnchorA", &WeldJoint::getLocalAnchorA, &WeldJoint::nullMethod);
			LUTOK_PROPERTY("localAnchorB", &WeldJoint::getLocalAnchorB, &WeldJoint::nullMethod);
			LUTOK_PROPERTY("referenceAngle", &WeldJoint::getReferenceAngle, &WeldJoint::nullMethod);
			LUTOK_PROPERTY("frequencyHz", &WeldJoint::getFrequencyHz, &WeldJoint::setFrequencyHz);
			LUTOK_PROPERTY("dampingRatio", &WeldJoint::getDampingRatio, &WeldJoint::setDampingRatio);
			LUTOK_PROPERTY("userData", &WeldJoint::getUserData, &WeldJoint::setUserData);
		}

		b2WeldJoint * constructor(State & state, bool & managed);

		void destructor(State & state, b2WeldJoint * object);

		int getType(State & state, b2WeldJoint * );

		int getBodyA(State & state, b2WeldJoint *);

		int getBodyB(State & state, b2WeldJoint *);

		int getAnchorA(State & state, b2WeldJoint *);

		int getAnchorB(State & state, b2WeldJoint *);

		int getReactionForce(State & state, b2WeldJoint *);

		int getReactionTorque(State & state, b2WeldJoint *);

		int getActive(State & state, b2WeldJoint * );

		int getCollideConnected(State & state, b2WeldJoint * );

		int getReferenceAngle(State & state, b2WeldJoint * object);

		int getLocalAnchorA(State & state, b2WeldJoint * object);

		int getLocalAnchorB(State & state, b2WeldJoint * object);

		int getFrequencyHz(State & state, b2WeldJoint * object);

		int setFrequencyHz(State & state, b2WeldJoint * object);

		int getDampingRatio(State & state, b2WeldJoint * object);

		int setDampingRatio(State & state, b2WeldJoint * object);

		int getUserData(State & state, b2WeldJoint * object);

		int setUserData(State & state, b2WeldJoint * object);

	};

	void initWeldJoint(State * );
};

#endif	
