#ifndef LUABOX2D_PULLEYJOINT_H
#define LUABOX2D_PULLEYJOINT_H

#include "objects/Joint.hpp"

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

		b2PulleyJoint * constructor(State & state){
			Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
			b2Joint * joint = interfaceJoint->get(1);
			if (joint != nullptr){
				if (joint->GetType() == b2JointType::e_revoluteJoint){
					return new b2PulleyJoint(*dynamic_cast<b2PulleyJoint*>(joint));
				}else{
					return nullptr;
				}
			}else{
				return nullptr;
			}
		}

		void destructor(State & state, b2PulleyJoint * object){
			delete object;
		}

		inline int getType(State & state, b2PulleyJoint * );

		inline int getBodyA(State & state, b2PulleyJoint *);

		inline int getBodyB(State & state, b2PulleyJoint *);

		inline int getAnchorA(State & state, b2PulleyJoint *);

		inline int getAnchorB(State & state, b2PulleyJoint *);

		inline int getReactionForce(State & state, b2PulleyJoint *);

		inline int getReactionTorque(State & state, b2PulleyJoint *);

		inline int getActive(State & state, b2PulleyJoint * );

		inline int getCollideConnected(State & state, b2PulleyJoint * );
	};

	void initPulleyJoint(State * );
};

#endif	
