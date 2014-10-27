#ifndef LUABOX2D_GEARJOINT_H
#define LUABOX2D_GEARJOINT_H

#include "objects/Joint.hpp"

namespace LuaBox2D {
	class GearJoint : public Object<b2GearJoint> {
	private:
		Joint * base;
	public:
		explicit GearJoint(State * state) : Object<b2GearJoint>(state){
			base = state->getInterface<Joint>("LuaBox2D_Joint");
			LUTOK_PROPERTY("type", &GearJoint::getType, &GearJoint::nullMethod);
			LUTOK_PROPERTY("bodyA", &GearJoint::getBodyA, &GearJoint::nullMethod);
			LUTOK_PROPERTY("bodyB", &GearJoint::getBodyB, &GearJoint::nullMethod);

			LUTOK_PROPERTY("anchorA", &GearJoint::getAnchorA, &GearJoint::nullMethod);
			LUTOK_PROPERTY("anchorB", &GearJoint::getAnchorB, &GearJoint::nullMethod);

			LUTOK_METHOD("reactionForce", &GearJoint::getReactionForce);
			LUTOK_METHOD("reactionTorque", &GearJoint::getReactionTorque);

			LUTOK_PROPERTY("active", &GearJoint::getActive, &GearJoint::nullMethod);
			LUTOK_PROPERTY("collideConnected", &GearJoint::getCollideConnected, &GearJoint::nullMethod);
		}

		b2GearJoint * constructor(State & state){
			Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
			b2Joint * joint = interfaceJoint->get(1);
			if (joint != nullptr){
				if (joint->GetType() == b2JointType::e_revoluteJoint){
					return new b2GearJoint(*dynamic_cast<b2GearJoint*>(joint));
				}else{
					return nullptr;
				}
			}else{
				return nullptr;
			}
		}

		void destructor(State & state, b2GearJoint * object){
			delete object;
		}

		inline int getType(State & state, b2GearJoint * );

		inline int getBodyA(State & state, b2GearJoint *);

		inline int getBodyB(State & state, b2GearJoint *);

		inline int getAnchorA(State & state, b2GearJoint *);

		inline int getAnchorB(State & state, b2GearJoint *);

		inline int getReactionForce(State & state, b2GearJoint *);

		inline int getReactionTorque(State & state, b2GearJoint *);

		inline int getActive(State & state, b2GearJoint * );

		inline int getCollideConnected(State & state, b2GearJoint * );
	};

	void initGearJoint(State * );
};

#endif	
