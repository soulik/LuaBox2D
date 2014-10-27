#ifndef LUABOX2D_PULLEYJOINTDEF_H
#define LUABOX2D_PULLEYJOINTDEF_H

#include "objects/JointDef.hpp"

namespace LuaBox2D {
	class PulleyJointDef : public Object<b2PulleyJointDef> {
	private:
		JointDef * base;
	public:
		explicit PulleyJointDef(State * state) : Object<b2PulleyJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &PulleyJointDef::getType, &PulleyJointDef::setType);
			LUTOK_PROPERTY("bodyA", &PulleyJointDef::getBodyA, &PulleyJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &PulleyJointDef::getBodyB, &PulleyJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &PulleyJointDef::getCollideConnected, &PulleyJointDef::setCollideConnected);
		}

		b2PulleyJointDef * constructor(State & state){
			JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
			b2JointDef * jointDef = interfaceJointDef->get(1);
			if (jointDef != nullptr){
				if (jointDef->type == b2JointType::e_revoluteJoint){
					return new b2PulleyJointDef(*(b2PulleyJointDef*)(jointDef));
				}else{
					return new b2PulleyJointDef();
				}
			}else{
				return new b2PulleyJointDef();
			}
		}

		void destructor(State & state, b2PulleyJointDef * object){
			delete object;
		}

		inline int getBodyA(State & state, b2PulleyJointDef * );

		inline int setBodyA(State & state, b2PulleyJointDef * );

		inline int getBodyB(State & state, b2PulleyJointDef * );

		inline int setBodyB(State & state, b2PulleyJointDef * );

		inline int getType(State & state, b2PulleyJointDef * );

		inline int setType(State & state, b2PulleyJointDef * );

		inline int getCollideConnected(State & state, b2PulleyJointDef * );

		inline int setCollideConnected(State & state, b2PulleyJointDef * );
	};

	void initPulleyJointDef(State * );
};

#endif	
