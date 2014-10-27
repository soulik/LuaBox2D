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
		}

		b2PulleyJoint * constructor(State & state);

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
	};

	void initPulleyJoint(State * );
};

#endif	
