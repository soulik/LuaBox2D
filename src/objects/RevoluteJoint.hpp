#ifndef LUABOX2D_REVOLUTEJOINT_H
#define LUABOX2D_REVOLUTEJOINT_H

#include "objects/Joint.hpp"

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

		b2RevoluteJoint * constructor(State & state){
			Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
			b2Joint * joint = interfaceJoint->get(1);
			if (joint != nullptr){
				if (joint->GetType() == b2JointType::e_revoluteJoint){
					return new b2RevoluteJoint(*dynamic_cast<b2RevoluteJoint*>(joint));
				}else{
					return nullptr;
				}
			}else{
				return nullptr;
			}
		}

		void destructor(State & state, b2RevoluteJoint * object){
			delete object;
		}

		inline int getType(State & state, b2RevoluteJoint * );

		inline int getBodyA(State & state, b2RevoluteJoint *);

		inline int getBodyB(State & state, b2RevoluteJoint *);

		inline int getAnchorA(State & state, b2RevoluteJoint *);

		inline int getAnchorB(State & state, b2RevoluteJoint *);

		inline int getReactionForce(State & state, b2RevoluteJoint *);

		inline int getReactionTorque(State & state, b2RevoluteJoint *);

		inline int getActive(State & state, b2RevoluteJoint * );

		inline int getCollideConnected(State & state, b2RevoluteJoint * );
	};

	void initRevoluteJoint(State * );
};

#endif	
