#ifndef LUABOX2D_ROPEJOINTDEF_H
#define LUABOX2D_ROPEJOINTDEF_H

#include "objects/JointDef.hpp"

namespace LuaBox2D {
	class RopeJointDef : public Object<b2RopeJointDef> {
	private:
		JointDef * base;
	public:
		explicit RopeJointDef(State * state) : Object<b2RopeJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &RopeJointDef::getType, &RopeJointDef::setType);
			LUTOK_PROPERTY("bodyA", &RopeJointDef::getBodyA, &RopeJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &RopeJointDef::getBodyB, &RopeJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &RopeJointDef::getCollideConnected, &RopeJointDef::setCollideConnected);
		}

		b2RopeJointDef * constructor(State & state){
			JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
			b2JointDef * jointDef = interfaceJointDef->get(1);
			if (jointDef != nullptr){
				if (jointDef->type == b2JointType::e_revoluteJoint){
					return new b2RopeJointDef(*(b2RopeJointDef*)(jointDef));
				}else{
					return new b2RopeJointDef();
				}
			}else{
				return new b2RopeJointDef();
			}
		}

		void destructor(State & state, b2RopeJointDef * object){
			delete object;
		}

		inline int getBodyA(State & state, b2RopeJointDef * );

		inline int setBodyA(State & state, b2RopeJointDef * );

		inline int getBodyB(State & state, b2RopeJointDef * );

		inline int setBodyB(State & state, b2RopeJointDef * );

		inline int getType(State & state, b2RopeJointDef * );

		inline int setType(State & state, b2RopeJointDef * );

		inline int getCollideConnected(State & state, b2RopeJointDef * );

		inline int setCollideConnected(State & state, b2RopeJointDef * );
	};

	void initRopeJointDef(State * );
};

#endif	
