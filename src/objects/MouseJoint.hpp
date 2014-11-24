#ifndef LUABOX2D_MOUSEJOINT_H
#define LUABOX2D_MOUSEJOINT_H

namespace LuaBox2D {
	class MouseJoint : public Object<b2MouseJoint> {
	private:
		Joint * base;
	public:
		explicit MouseJoint(State * state) : Object<b2MouseJoint>(state){
			base = state->getInterface<Joint>("LuaBox2D_Joint");
			LUTOK_PROPERTY("type", &MouseJoint::getType, &MouseJoint::nullMethod);
			LUTOK_PROPERTY("bodyA", &MouseJoint::getBodyA, &MouseJoint::nullMethod);
			LUTOK_PROPERTY("bodyB", &MouseJoint::getBodyB, &MouseJoint::nullMethod);

			LUTOK_PROPERTY("anchorA", &MouseJoint::getAnchorA, &MouseJoint::nullMethod);
			LUTOK_PROPERTY("anchorB", &MouseJoint::getAnchorB, &MouseJoint::nullMethod);

			LUTOK_METHOD("reactionForce", &MouseJoint::getReactionForce);
			LUTOK_METHOD("reactionTorque", &MouseJoint::getReactionTorque);

			LUTOK_PROPERTY("active", &MouseJoint::getActive, &MouseJoint::nullMethod);
			LUTOK_PROPERTY("collideConnected", &MouseJoint::getCollideConnected, &MouseJoint::nullMethod);

			LUTOK_PROPERTY("target", &MouseJoint::getTarget, &MouseJoint::setTarget);
			LUTOK_PROPERTY("maxForce", &MouseJoint::getMaxForce, &MouseJoint::setMaxForce);
			LUTOK_PROPERTY("frequencyHz", &MouseJoint::getFrequencyHz, &MouseJoint::setFrequencyHz);
			LUTOK_PROPERTY("dampingRatio", &MouseJoint::getDampingRatio, &MouseJoint::setDampingRatio);

			LUTOK_METHOD("shiftOrigin", &MouseJoint::shiftOrigin);
			LUTOK_PROPERTY("userData", &MouseJoint::getUserData, &MouseJoint::setUserData);
		}

		b2MouseJoint * constructor(State & state, bool & managed);

		void destructor(State & state, b2MouseJoint * object);

		int getType(State & state, b2MouseJoint * );

		int getBodyA(State & state, b2MouseJoint *);

		int getBodyB(State & state, b2MouseJoint *);

		int getAnchorA(State & state, b2MouseJoint *);

		int getAnchorB(State & state, b2MouseJoint *);

		int getActive(State & state, b2MouseJoint * );

		int getCollideConnected(State & state, b2MouseJoint * );

		int getReactionForce(State & state, b2MouseJoint *);

		int getReactionTorque(State & state, b2MouseJoint *);

		int getTarget(State & state, b2MouseJoint * object);

		int setTarget(State & state, b2MouseJoint * object);

		int getMaxForce(State & state, b2MouseJoint * object);

		int setMaxForce(State & state, b2MouseJoint * object);

		int getFrequencyHz(State & state, b2MouseJoint * object);

		int setFrequencyHz(State & state, b2MouseJoint * object);

		int getDampingRatio(State & state, b2MouseJoint * object);

		int setDampingRatio(State & state, b2MouseJoint * object);

		int shiftOrigin(State & state, b2MouseJoint * object);

		int getUserData(State & state, b2MouseJoint * object);

		int setUserData(State & state, b2MouseJoint * object);

	};

	void initMouseJoint(State * );
};

#endif	
