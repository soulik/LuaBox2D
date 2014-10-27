#ifndef LUABOX2D_MOUSEJOINTDEF_H
#define LUABOX2D_MOUSEJOINTDEF_H

#include "objects/JointDef.hpp"

namespace LuaBox2D {
	class MouseJointDef : public Object<b2MouseJointDef> {
	private:
		JointDef * base;
	public:
		explicit MouseJointDef(State * state) : Object<b2MouseJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &MouseJointDef::getType, &MouseJointDef::setType);
			LUTOK_PROPERTY("bodyA", &MouseJointDef::getBodyA, &MouseJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &MouseJointDef::getBodyB, &MouseJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &MouseJointDef::getCollideConnected, &MouseJointDef::setCollideConnected);
		}

		b2MouseJointDef * constructor(State & state){
			JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
			b2JointDef * jointDef = interfaceJointDef->get(1);
			if (jointDef != nullptr){
				if (jointDef->type == b2JointType::e_revoluteJoint){
					return new b2MouseJointDef(*(b2MouseJointDef*)(jointDef));
				}else{
					return new b2MouseJointDef();
				}
			}else{
				return new b2MouseJointDef();
			}
		}

		void destructor(State & state, b2MouseJointDef * object){
			delete object;
		}

		inline int getBodyA(State & state, b2MouseJointDef * );

		inline int setBodyA(State & state, b2MouseJointDef * );

		inline int getBodyB(State & state, b2MouseJointDef * );

		inline int setBodyB(State & state, b2MouseJointDef * );

		inline int getType(State & state, b2MouseJointDef * );

		inline int setType(State & state, b2MouseJointDef * );

		inline int getCollideConnected(State & state, b2MouseJointDef * );

		inline int setCollideConnected(State & state, b2MouseJointDef * );
	};

	void initMouseJointDef(State * );
};

#endif	
