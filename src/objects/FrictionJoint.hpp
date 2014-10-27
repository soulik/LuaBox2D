#ifndef LUABOX2D_FRICTIONJOINT_H
#define LUABOX2D_FRICTIONJOINT_H

#include "objects/Joint.hpp"

namespace LuaBox2D {
	class FrictionJoint : public Object<b2FrictionJoint> {
	private:
		Joint * base;
	public:
		explicit FrictionJoint(State * state) : Object<b2FrictionJoint>(state){
			base = state->getInterface<Joint>("LuaBox2D_Joint");
			LUTOK_PROPERTY("type", &FrictionJoint::getType, &FrictionJoint::nullMethod);
			LUTOK_PROPERTY("bodyA", &FrictionJoint::getBodyA, &FrictionJoint::nullMethod);
			LUTOK_PROPERTY("bodyB", &FrictionJoint::getBodyB, &FrictionJoint::nullMethod);

			LUTOK_PROPERTY("anchorA", &FrictionJoint::getAnchorA, &FrictionJoint::nullMethod);
			LUTOK_PROPERTY("anchorB", &FrictionJoint::getAnchorB, &FrictionJoint::nullMethod);

			LUTOK_METHOD("reactionForce", &FrictionJoint::getReactionForce);
			LUTOK_METHOD("reactionTorque", &FrictionJoint::getReactionTorque);

			LUTOK_PROPERTY("active", &FrictionJoint::getActive, &FrictionJoint::nullMethod);
			LUTOK_PROPERTY("collideConnected", &FrictionJoint::getCollideConnected, &FrictionJoint::nullMethod);
		}

		b2FrictionJoint * constructor(State & state){
			Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
			b2Joint * joint = interfaceJoint->get(1);
			if (joint != nullptr){
				if (joint->GetType() == b2JointType::e_revoluteJoint){
					return new b2FrictionJoint(*dynamic_cast<b2FrictionJoint*>(joint));
				}else{
					return nullptr;
				}
			}else{
				return nullptr;
			}
		}

		void destructor(State & state, b2FrictionJoint * object){
			delete object;
		}

		inline int getType(State & state, b2FrictionJoint * );

		inline int getBodyA(State & state, b2FrictionJoint *);

		inline int getBodyB(State & state, b2FrictionJoint *);

		inline int getAnchorA(State & state, b2FrictionJoint *);

		inline int getAnchorB(State & state, b2FrictionJoint *);

		inline int getReactionForce(State & state, b2FrictionJoint *);

		inline int getReactionTorque(State & state, b2FrictionJoint *);

		inline int getActive(State & state, b2FrictionJoint * );

		inline int getCollideConnected(State & state, b2FrictionJoint * );
	};

	void initFrictionJoint(State * );
};

#endif	
