#ifndef LUABOX2D_REVOLUTEJOINT_H
#define LUABOX2D_REVOLUTEJOINT_H

namespace LuaBox2D {
	class RevoluteJoint : public Object<b2RevoluteJoint> {
	private:
		Joint * base;
	public:
		explicit RevoluteJoint(State * state) : Object<b2RevoluteJoint>(state){
			base = state->getInterface<Joint>("LuaBox2D_Joint");
			LUTOK_PROPERTY("type", &RevoluteJoint::getType, &RevoluteJoint::nullMethod);
			LUTOK_PROPERTY("bodyA", &RevoluteJoint::getBodyA, &RevoluteJoint::nullMethod);
			LUTOK_PROPERTY("bodyB", &RevoluteJoint::getBodyB, &RevoluteJoint::nullMethod);

			LUTOK_PROPERTY("anchorA", &RevoluteJoint::getAnchorA, &RevoluteJoint::nullMethod);
			LUTOK_PROPERTY("anchorB", &RevoluteJoint::getAnchorB, &RevoluteJoint::nullMethod);

			LUTOK_METHOD("reactionForce", &RevoluteJoint::getReactionForce);
			LUTOK_METHOD("reactionTorque", &RevoluteJoint::getReactionTorque);

			LUTOK_PROPERTY("active", &RevoluteJoint::getActive, &RevoluteJoint::nullMethod);
			LUTOK_PROPERTY("collideConnected", &RevoluteJoint::getCollideConnected, &RevoluteJoint::nullMethod);
		}

		b2RevoluteJoint * constructor(State & state);

		void destructor(State & state, b2RevoluteJoint * object);

		int getType(State & state, b2RevoluteJoint * );

		int getBodyA(State & state, b2RevoluteJoint *);

		int getBodyB(State & state, b2RevoluteJoint *);

		int getAnchorA(State & state, b2RevoluteJoint *);

		int getAnchorB(State & state, b2RevoluteJoint *);

		int getReactionForce(State & state, b2RevoluteJoint *);

		int getReactionTorque(State & state, b2RevoluteJoint *);

		int getActive(State & state, b2RevoluteJoint * );

		int getCollideConnected(State & state, b2RevoluteJoint * );
	};

	void initRevoluteJoint(State * );
};

#endif	
