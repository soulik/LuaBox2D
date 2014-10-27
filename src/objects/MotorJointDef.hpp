#ifndef LUABOX2D_MOTORJOINTDEF_H
#define LUABOX2D_MOTORJOINTDEF_H

#include "objects/JointDef.hpp"

namespace LuaBox2D {
	class MotorJointDef : public Object<b2MotorJointDef> {
	private:
		JointDef * base;
	public:
		explicit MotorJointDef(State * state) : Object<b2MotorJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &MotorJointDef::getType, &MotorJointDef::setType);
			LUTOK_PROPERTY("bodyA", &MotorJointDef::getBodyA, &MotorJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &MotorJointDef::getBodyB, &MotorJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &MotorJointDef::getCollideConnected, &MotorJointDef::setCollideConnected);
		}

		b2MotorJointDef * constructor(State & state){
			JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
			b2JointDef * jointDef = interfaceJointDef->get(1);
			if (jointDef != nullptr){
				if (jointDef->type == b2JointType::e_revoluteJoint){
					return new b2MotorJointDef(*(b2MotorJointDef*)(jointDef));
				}else{
					return new b2MotorJointDef();
				}
			}else{
				return new b2MotorJointDef();
			}
		}

		void destructor(State & state, b2MotorJointDef * object){
			delete object;
		}

		inline int getBodyA(State & state, b2MotorJointDef * );

		inline int setBodyA(State & state, b2MotorJointDef * );

		inline int getBodyB(State & state, b2MotorJointDef * );

		inline int setBodyB(State & state, b2MotorJointDef * );

		inline int getType(State & state, b2MotorJointDef * );

		inline int setType(State & state, b2MotorJointDef * );

		inline int getCollideConnected(State & state, b2MotorJointDef * );

		inline int setCollideConnected(State & state, b2MotorJointDef * );
	};

	void initMotorJointDef(State * );
};

#endif	
