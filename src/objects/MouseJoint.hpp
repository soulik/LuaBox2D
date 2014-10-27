#ifndef LUABOX2D_MOUSEJOINT_H
#define LUABOX2D_MOUSEJOINT_H

#include "objects/Joint.hpp"

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

		b2MouseJoint * constructor(State & state){
			Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
			b2Joint * joint = interfaceJoint->get(1);
			if (joint != nullptr){
				if (joint->GetType() == b2JointType::e_revoluteJoint){
					return new b2MouseJoint(*dynamic_cast<b2MouseJoint*>(joint));
				}else{
					return nullptr;
				}
			}else{
				return nullptr;
			}
		}

		void destructor(State & state, b2MouseJoint * object){
			delete object;
		}

		inline int getType(State & state, b2MouseJoint * );

		inline int getBodyA(State & state, b2MouseJoint *);

		inline int getBodyB(State & state, b2MouseJoint *);

		inline int getAnchorA(State & state, b2MouseJoint *);

		inline int getAnchorB(State & state, b2MouseJoint *);

		inline int getReactionForce(State & state, b2MouseJoint *);

		inline int getReactionTorque(State & state, b2MouseJoint *);

		inline int getActive(State & state, b2MouseJoint * );

		inline int getCollideConnected(State & state, b2MouseJoint * );
	};

	void initMouseJoint(State * );
};

#endif	
