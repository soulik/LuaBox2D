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
		}

		b2DistanceJoint * constructor(State & state);

		void destructor(State & state, b2DistanceJoint * object);

		int getType(State & state, b2DistanceJoint * );

		int getBodyA(State & state, b2DistanceJoint *);

		int getBodyB(State & state, b2DistanceJoint *);

		int getAnchorA(State & state, b2DistanceJoint *);

		int getAnchorB(State & state, b2DistanceJoint *);

		int getReactionForce(State & state, b2DistanceJoint *);

		int getReactionTorque(State & state, b2DistanceJoint *);

		int getActive(State & state, b2DistanceJoint * );

		int getCollideConnected(State & state, b2DistanceJoint * );
	};

	void initDistanceJoint(State * );
};

#endif	
