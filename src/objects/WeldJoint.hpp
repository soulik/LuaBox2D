#ifndef LUABOX2D_WELDJOINT_H
#define LUABOX2D_WELDJOINT_H

#include "objects/Joint.hpp"

namespace LuaBox2D {
	class WeldJoint : public Object<b2WeldJoint> {
	private:
		Joint * base;
	public:
		explicit WeldJoint(State * state) : Object<b2WeldJoint>(state){
			base = state->getInterface<Joint>("LuaBox2D_Joint");
			LUTOK_PROPERTY("type", &WeldJoint::getType, &WeldJoint::nullMethod);
			LUTOK_PROPERTY("bodyA", &WeldJoint::getBodyA, &WeldJoint::nullMethod);
			LUTOK_PROPERTY("bodyB", &WeldJoint::getBodyB, &WeldJoint::nullMethod);

			LUTOK_PROPERTY("anchorA", &WeldJoint::getAnchorA, &WeldJoint::nullMethod);
			LUTOK_PROPERTY("anchorB", &WeldJoint::getAnchorB, &WeldJoint::nullMethod);

			LUTOK_METHOD("reactionForce", &WeldJoint::getReactionForce);
			LUTOK_METHOD("reactionTorque", &WeldJoint::getReactionTorque);

			LUTOK_PROPERTY("active", &WeldJoint::getActive, &WeldJoint::nullMethod);
			LUTOK_PROPERTY("collideConnected", &WeldJoint::getCollideConnected, &WeldJoint::nullMethod);
		}

		b2WeldJoint * constructor(State & state){
			Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
			b2Joint * joint = interfaceJoint->get(1);
			if (joint != nullptr){
				if (joint->GetType() == b2JointType::e_revoluteJoint){
					return new b2WeldJoint(*dynamic_cast<b2WeldJoint*>(joint));
				}else{
					return nullptr;
				}
			}else{
				return nullptr;
			}
		}

		void destructor(State & state, b2WeldJoint * object){
			delete object;
		}

		inline int getType(State & state, b2WeldJoint * );

		inline int getBodyA(State & state, b2WeldJoint *);

		inline int getBodyB(State & state, b2WeldJoint *);

		inline int getAnchorA(State & state, b2WeldJoint *);

		inline int getAnchorB(State & state, b2WeldJoint *);

		inline int getReactionForce(State & state, b2WeldJoint *);

		inline int getReactionTorque(State & state, b2WeldJoint *);

		inline int getActive(State & state, b2WeldJoint * );

		inline int getCollideConnected(State & state, b2WeldJoint * );
	};

	void initWeldJoint(State * );
};

#endif	
