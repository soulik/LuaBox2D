#ifndef LUABOX2D_WHEELJOINT_H
#define LUABOX2D_WHEELJOINT_H

#include "objects/Joint.hpp"

namespace LuaBox2D {
	class WheelJoint : public Object<b2WheelJoint> {
	private:
		Joint * base;
	public:
		explicit WheelJoint(State * state) : Object<b2WheelJoint>(state){
			base = state->getInterface<Joint>("LuaBox2D_Joint");
			LUTOK_PROPERTY("type", &WheelJoint::getType, &WheelJoint::nullMethod);
			LUTOK_PROPERTY("bodyA", &WheelJoint::getBodyA, &WheelJoint::nullMethod);
			LUTOK_PROPERTY("bodyB", &WheelJoint::getBodyB, &WheelJoint::nullMethod);

			LUTOK_PROPERTY("anchorA", &WheelJoint::getAnchorA, &WheelJoint::nullMethod);
			LUTOK_PROPERTY("anchorB", &WheelJoint::getAnchorB, &WheelJoint::nullMethod);

			LUTOK_METHOD("reactionForce", &WheelJoint::getReactionForce);
			LUTOK_METHOD("reactionTorque", &WheelJoint::getReactionTorque);

			LUTOK_PROPERTY("active", &WheelJoint::getActive, &WheelJoint::nullMethod);
			LUTOK_PROPERTY("collideConnected", &WheelJoint::getCollideConnected, &WheelJoint::nullMethod);
		}

		b2WheelJoint * constructor(State & state){
			Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
			b2Joint * joint = interfaceJoint->get(1);
			if (joint != nullptr){
				if (joint->GetType() == b2JointType::e_revoluteJoint){
					return new b2WheelJoint(*dynamic_cast<b2WheelJoint*>(joint));
				}else{
					return nullptr;
				}
			}else{
				return nullptr;
			}
		}

		void destructor(State & state, b2WheelJoint * object){
			delete object;
		}

		inline int getType(State & state, b2WheelJoint * );

		inline int getBodyA(State & state, b2WheelJoint *);

		inline int getBodyB(State & state, b2WheelJoint *);

		inline int getAnchorA(State & state, b2WheelJoint *);

		inline int getAnchorB(State & state, b2WheelJoint *);

		inline int getReactionForce(State & state, b2WheelJoint *);

		inline int getReactionTorque(State & state, b2WheelJoint *);

		inline int getActive(State & state, b2WheelJoint * );

		inline int getCollideConnected(State & state, b2WheelJoint * );
	};

	void initWheelJoint(State * );
};

#endif	
