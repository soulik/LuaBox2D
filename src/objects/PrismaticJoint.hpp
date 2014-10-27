#ifndef LUABOX2D_PRISMATICJOINT_H
#define LUABOX2D_PRISMATICJOINT_H

namespace LuaBox2D {
	class PrismaticJoint : public Object<b2PrismaticJoint> {
	private:
		Joint * base;
	public:
		explicit PrismaticJoint(State * state) : Object<b2PrismaticJoint>(state){
			base = state->getInterface<Joint>("LuaBox2D_Joint");
			LUTOK_PROPERTY("type", &PrismaticJoint::getType, &PrismaticJoint::nullMethod);
			LUTOK_PROPERTY("bodyA", &PrismaticJoint::getBodyA, &PrismaticJoint::nullMethod);
			LUTOK_PROPERTY("bodyB", &PrismaticJoint::getBodyB, &PrismaticJoint::nullMethod);

			LUTOK_PROPERTY("anchorA", &PrismaticJoint::getAnchorA, &PrismaticJoint::nullMethod);
			LUTOK_PROPERTY("anchorB", &PrismaticJoint::getAnchorB, &PrismaticJoint::nullMethod);

			LUTOK_METHOD("reactionForce", &PrismaticJoint::getReactionForce);
			LUTOK_METHOD("reactionTorque", &PrismaticJoint::getReactionTorque);

			LUTOK_PROPERTY("active", &PrismaticJoint::getActive, &PrismaticJoint::nullMethod);
			LUTOK_PROPERTY("collideConnected", &PrismaticJoint::getCollideConnected, &PrismaticJoint::nullMethod);
		}

		b2PrismaticJoint * constructor(State & state);

		void destructor(State & state, b2PrismaticJoint * object);

		int getType(State & state, b2PrismaticJoint * );

		int getBodyA(State & state, b2PrismaticJoint *);

		int getBodyB(State & state, b2PrismaticJoint *);

		int getAnchorA(State & state, b2PrismaticJoint *);

		int getAnchorB(State & state, b2PrismaticJoint *);

		int getReactionForce(State & state, b2PrismaticJoint *);

		int getReactionTorque(State & state, b2PrismaticJoint *);

		int getActive(State & state, b2PrismaticJoint * );

		int getCollideConnected(State & state, b2PrismaticJoint * );
	};

	void initPrismaticJoint(State * );
};

#endif	
