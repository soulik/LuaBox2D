#ifndef LUABOX2D_ROPEJOINT_H
#define LUABOX2D_ROPEJOINT_H

namespace LuaBox2D {
	class RopeJoint : public Object<b2RopeJoint> {
	private:
		Joint * base;
	public:
		explicit RopeJoint(State * state) : Object<b2RopeJoint>(state){
			base = state->getInterface<Joint>("LuaBox2D_Joint");
			LUTOK_PROPERTY("type", &RopeJoint::getType, &RopeJoint::nullMethod);
			LUTOK_PROPERTY("bodyA", &RopeJoint::getBodyA, &RopeJoint::nullMethod);
			LUTOK_PROPERTY("bodyB", &RopeJoint::getBodyB, &RopeJoint::nullMethod);

			LUTOK_PROPERTY("anchorA", &RopeJoint::getAnchorA, &RopeJoint::nullMethod);
			LUTOK_PROPERTY("anchorB", &RopeJoint::getAnchorB, &RopeJoint::nullMethod);

			LUTOK_METHOD("reactionForce", &RopeJoint::getReactionForce);
			LUTOK_METHOD("reactionTorque", &RopeJoint::getReactionTorque);

			LUTOK_PROPERTY("active", &RopeJoint::getActive, &RopeJoint::nullMethod);
			LUTOK_PROPERTY("collideConnected", &RopeJoint::getCollideConnected, &RopeJoint::nullMethod);

			LUTOK_PROPERTY("localAnchorA", &RopeJoint::getLocalAnchorA, &RopeJoint::nullMethod);
			LUTOK_PROPERTY("localAnchorB", &RopeJoint::getLocalAnchorB, &RopeJoint::nullMethod);
			LUTOK_PROPERTY("maxLength", &RopeJoint::getMaxLength, &RopeJoint::setMaxLength);

			LUTOK_PROPERTY("limitState", &RopeJoint::getLimitState, &RopeJoint::nullMethod);
			LUTOK_PROPERTY("userData", &RopeJoint::getUserData, &RopeJoint::setUserData);
		}

		b2RopeJoint * constructor(State & state, bool & managed);

		void destructor(State & state, b2RopeJoint * object);

		int getType(State & state, b2RopeJoint * );

		int getBodyA(State & state, b2RopeJoint *);

		int getBodyB(State & state, b2RopeJoint *);

		int getAnchorA(State & state, b2RopeJoint *);

		int getAnchorB(State & state, b2RopeJoint *);

		int getReactionForce(State & state, b2RopeJoint *);

		int getReactionTorque(State & state, b2RopeJoint *);

		int getActive(State & state, b2RopeJoint * );

		int getCollideConnected(State & state, b2RopeJoint * );

		int getLocalAnchorA(State & state, b2RopeJoint * object);

		int getLocalAnchorB(State & state, b2RopeJoint * object);

		int getMaxLength(State & state, b2RopeJoint * object);

		int setMaxLength(State & state, b2RopeJoint * object);

		int getLimitState(State & state, b2RopeJoint * object);

		int getUserData(State & state, b2RopeJoint * object);

		int setUserData(State & state, b2RopeJoint * object);

	};

	void initRopeJoint(State * );
};

#endif	
