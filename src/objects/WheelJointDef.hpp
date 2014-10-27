#ifndef LUABOX2D_WHEELJOINTDEF_H
#define LUABOX2D_WHEELJOINTDEF_H

#include "objects/JointDef.hpp"

namespace LuaBox2D {
	class WheelJointDef : public Object<b2WheelJointDef> {
	private:
		JointDef * base;
	public:
		explicit WheelJointDef(State * state) : Object<b2WheelJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &WheelJointDef::getType, &WheelJointDef::setType);
			LUTOK_PROPERTY("bodyA", &WheelJointDef::getBodyA, &WheelJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &WheelJointDef::getBodyB, &WheelJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &WheelJointDef::getCollideConnected, &WheelJointDef::setCollideConnected);
		}

		b2WheelJointDef * constructor(State & state){
			JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
			b2JointDef * jointDef = interfaceJointDef->get(1);
			if (jointDef != nullptr){
				if (jointDef->type == b2JointType::e_revoluteJoint){
					return new b2WheelJointDef(*(b2WheelJointDef*)(jointDef));
				}else{
					return new b2WheelJointDef();
				}
			}else{
				return new b2WheelJointDef();
			}
		}

		void destructor(State & state, b2WheelJointDef * object){
			delete object;
		}

		inline int getBodyA(State & state, b2WheelJointDef * );

		inline int setBodyA(State & state, b2WheelJointDef * );

		inline int getBodyB(State & state, b2WheelJointDef * );

		inline int setBodyB(State & state, b2WheelJointDef * );

		inline int getType(State & state, b2WheelJointDef * );

		inline int setType(State & state, b2WheelJointDef * );

		inline int getCollideConnected(State & state, b2WheelJointDef * );

		inline int setCollideConnected(State & state, b2WheelJointDef * );
	};

	void initWheelJointDef(State * );
};

#endif	
