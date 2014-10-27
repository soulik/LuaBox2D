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
		}

		b2WeldJoint * constructor(State & state);

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
	};

	void initWeldJoint(State * );
};

#endif	
