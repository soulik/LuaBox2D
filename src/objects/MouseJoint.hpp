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
		}

		b2MouseJoint * constructor(State & state);

		void destructor(State & state, b2MouseJoint * object);

		int getType(State & state, b2MouseJoint * );

		int getBodyA(State & state, b2MouseJoint *);

		int getBodyB(State & state, b2MouseJoint *);

		int getAnchorA(State & state, b2MouseJoint *);

		int getAnchorB(State & state, b2MouseJoint *);

		int getReactionForce(State & state, b2MouseJoint *);

		int getReactionTorque(State & state, b2MouseJoint *);

		int getActive(State & state, b2MouseJoint * );

		int getCollideConnected(State & state, b2MouseJoint * );
	};

	void initMouseJoint(State * );
};

#endif	
