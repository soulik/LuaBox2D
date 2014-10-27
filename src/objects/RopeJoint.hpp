#ifndef LUABOX2D_ROPEJOINT_H
#define LUABOX2D_ROPEJOINT_H

#include "objects/Joint.hpp"

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
		}

		b2RopeJoint * constructor(State & state){
			Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
			b2Joint * joint = interfaceJoint->get(1);
			if (joint != nullptr){
				if (joint->GetType() == b2JointType::e_revoluteJoint){
					return new b2RopeJoint(*dynamic_cast<b2RopeJoint*>(joint));
				}else{
					return nullptr;
				}
			}else{
				return nullptr;
			}
		}

		void destructor(State & state, b2RopeJoint * object){
			delete object;
		}

		inline int getType(State & state, b2RopeJoint * );

		inline int getBodyA(State & state, b2RopeJoint *);

		inline int getBodyB(State & state, b2RopeJoint *);

		inline int getAnchorA(State & state, b2RopeJoint *);

		inline int getAnchorB(State & state, b2RopeJoint *);

		inline int getReactionForce(State & state, b2RopeJoint *);

		inline int getReactionTorque(State & state, b2RopeJoint *);

		inline int getActive(State & state, b2RopeJoint * );

		inline int getCollideConnected(State & state, b2RopeJoint * );
	};

	void initRopeJoint(State * );
};

#endif	
