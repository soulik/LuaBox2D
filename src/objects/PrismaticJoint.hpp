#ifndef LUABOX2D_PRISMATICJOINT_H
#define LUABOX2D_PRISMATICJOINT_H

#include "objects/Joint.hpp"

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

		b2PrismaticJoint * constructor(State & state){
			Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
			b2Joint * joint = interfaceJoint->get(1);
			if (joint != nullptr){
				if (joint->GetType() == b2JointType::e_revoluteJoint){
					return new b2PrismaticJoint(*dynamic_cast<b2PrismaticJoint*>(joint));
				}else{
					return nullptr;
				}
			}else{
				return nullptr;
			}
		}

		void destructor(State & state, b2PrismaticJoint * object){
			delete object;
		}

		inline int getType(State & state, b2PrismaticJoint * );

		inline int getBodyA(State & state, b2PrismaticJoint *);

		inline int getBodyB(State & state, b2PrismaticJoint *);

		inline int getAnchorA(State & state, b2PrismaticJoint *);

		inline int getAnchorB(State & state, b2PrismaticJoint *);

		inline int getReactionForce(State & state, b2PrismaticJoint *);

		inline int getReactionTorque(State & state, b2PrismaticJoint *);

		inline int getActive(State & state, b2PrismaticJoint * );

		inline int getCollideConnected(State & state, b2PrismaticJoint * );
	};

	void initPrismaticJoint(State * );
};

#endif	
