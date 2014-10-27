#ifndef LUABOX2D_MOTORJOINT_H
#define LUABOX2D_MOTORJOINT_H

#include "objects/Joint.hpp"

namespace LuaBox2D {
	class MotorJoint : public Object<b2MotorJoint> {
	private:
		Joint * base;
	public:
		explicit MotorJoint(State * state) : Object<b2MotorJoint>(state){
			base = state->getInterface<Joint>("LuaBox2D_Joint");
			LUTOK_PROPERTY("type", &MotorJoint::getType, &MotorJoint::nullMethod);
			LUTOK_PROPERTY("bodyA", &MotorJoint::getBodyA, &MotorJoint::nullMethod);
			LUTOK_PROPERTY("bodyB", &MotorJoint::getBodyB, &MotorJoint::nullMethod);

			LUTOK_PROPERTY("anchorA", &MotorJoint::getAnchorA, &MotorJoint::nullMethod);
			LUTOK_PROPERTY("anchorB", &MotorJoint::getAnchorB, &MotorJoint::nullMethod);

			LUTOK_METHOD("reactionForce", &MotorJoint::getReactionForce);
			LUTOK_METHOD("reactionTorque", &MotorJoint::getReactionTorque);

			LUTOK_PROPERTY("active", &MotorJoint::getActive, &MotorJoint::nullMethod);
			LUTOK_PROPERTY("collideConnected", &MotorJoint::getCollideConnected, &MotorJoint::nullMethod);
		}

		b2MotorJoint * constructor(State & state){
			Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
			b2Joint * joint = interfaceJoint->get(1);
			if (joint != nullptr){
				if (joint->GetType() == b2JointType::e_revoluteJoint){
					return new b2MotorJoint(*dynamic_cast<b2MotorJoint*>(joint));
				}else{
					return nullptr;
				}
			}else{
				return nullptr;
			}
		}

		void destructor(State & state, b2MotorJoint * object){
			delete object;
		}

		inline int getType(State & state, b2MotorJoint * );

		inline int getBodyA(State & state, b2MotorJoint *);

		inline int getBodyB(State & state, b2MotorJoint *);

		inline int getAnchorA(State & state, b2MotorJoint *);

		inline int getAnchorB(State & state, b2MotorJoint *);

		inline int getReactionForce(State & state, b2MotorJoint *);

		inline int getReactionTorque(State & state, b2MotorJoint *);

		inline int getActive(State & state, b2MotorJoint * );

		inline int getCollideConnected(State & state, b2MotorJoint * );
	};

	void initMotorJoint(State * );
};

#endif	
