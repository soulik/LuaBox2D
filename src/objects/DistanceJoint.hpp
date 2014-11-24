#ifndef LUABOX2D_DISTANCEJOINT_H
#define LUABOX2D_DISTANCEJOINT_H

namespace LuaBox2D {
	class DistanceJoint : public Object<b2DistanceJoint> {
	private:
		Joint * base;
	public:
		explicit DistanceJoint(State * state) : Object<b2DistanceJoint>(state){
			base = state->getInterface<Joint>("LuaBox2D_Joint");
			LUTOK_PROPERTY("type", &DistanceJoint::getType, &DistanceJoint::nullMethod);
			LUTOK_PROPERTY("bodyA", &DistanceJoint::getBodyA, &DistanceJoint::nullMethod);
			LUTOK_PROPERTY("bodyB", &DistanceJoint::getBodyB, &DistanceJoint::nullMethod);

			LUTOK_PROPERTY("anchorA", &DistanceJoint::getAnchorA, &DistanceJoint::nullMethod);
			LUTOK_PROPERTY("anchorB", &DistanceJoint::getAnchorB, &DistanceJoint::nullMethod);

			LUTOK_METHOD("reactionForce", &DistanceJoint::getReactionForce);
			LUTOK_METHOD("reactionTorque", &DistanceJoint::getReactionTorque);

			LUTOK_PROPERTY("active", &DistanceJoint::getActive, &DistanceJoint::nullMethod);
			LUTOK_PROPERTY("collideConnected", &DistanceJoint::getCollideConnected, &DistanceJoint::nullMethod);

			LUTOK_PROPERTY("anchorA", &DistanceJoint::getAnchorA, &DistanceJoint::nullMethod);
			LUTOK_PROPERTY("anchorB", &DistanceJoint::getAnchorB, &DistanceJoint::nullMethod);
			LUTOK_PROPERTY("localAnchorA", &DistanceJoint::getLocalAnchorA, &DistanceJoint::nullMethod);
			LUTOK_PROPERTY("localAnchorB", &DistanceJoint::getLocalAnchorB, &DistanceJoint::nullMethod);

			LUTOK_PROPERTY("length", &DistanceJoint::getLength, &DistanceJoint::setLength);
			LUTOK_PROPERTY("frequencyHz", &DistanceJoint::getFrequencyHz, &DistanceJoint::setFrequencyHz);
			LUTOK_PROPERTY("dampingRatio", &DistanceJoint::getDampingRatio, &DistanceJoint::setDampingRatio);
			LUTOK_PROPERTY("userData", &DistanceJoint::getUserData, &DistanceJoint::setUserData);
		}

		b2DistanceJoint * constructor(State & state, bool & managed);

		void destructor(State & state, b2DistanceJoint * object);

		int getType(State & state, b2DistanceJoint * );

		int getBodyA(State & state, b2DistanceJoint *);

		int getBodyB(State & state, b2DistanceJoint *);

		int getReactionForce(State & state, b2DistanceJoint *);

		int getReactionTorque(State & state, b2DistanceJoint *);

		int getActive(State & state, b2DistanceJoint * );

		int getCollideConnected(State & state, b2DistanceJoint * );

		int getAnchorA(State & state, b2DistanceJoint * object);

		int getAnchorB(State & state, b2DistanceJoint * object);

		int getLocalAnchorA(State & state, b2DistanceJoint * object);

		int getLocalAnchorB(State & state, b2DistanceJoint * object);

		int getLength(State & state, b2DistanceJoint * object);

		int setLength(State & state, b2DistanceJoint * object);

		int getFrequencyHz(State & state, b2DistanceJoint * object);

		int setFrequencyHz(State & state, b2DistanceJoint * object);

		int getDampingRatio(State & state, b2DistanceJoint * object);

		int setDampingRatio(State & state, b2DistanceJoint * object);

		int getUserData(State & state, b2DistanceJoint * object);

		int setUserData(State & state, b2DistanceJoint * object);
	};

	void initDistanceJoint(State * );
};

#endif	
