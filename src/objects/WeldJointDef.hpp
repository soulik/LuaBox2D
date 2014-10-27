#ifndef LUABOX2D_WELDJOINTDEF_H
#define LUABOX2D_WELDJOINTDEF_H

#include "objects/JointDef.hpp"

namespace LuaBox2D {
	class WeldJointDef : public Object<b2WeldJointDef> {
	private:
		JointDef * base;
	public:
		explicit WeldJointDef(State * state) : Object<b2WeldJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &WeldJointDef::getType, &WeldJointDef::setType);
			LUTOK_PROPERTY("bodyA", &WeldJointDef::getBodyA, &WeldJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &WeldJointDef::getBodyB, &WeldJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &WeldJointDef::getCollideConnected, &WeldJointDef::setCollideConnected);
		}

		b2WeldJointDef * constructor(State & state){
			JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
			b2JointDef * jointDef = interfaceJointDef->get(1);
			if (jointDef != nullptr){
				if (jointDef->type == b2JointType::e_revoluteJoint){
					return new b2WeldJointDef(*(b2WeldJointDef*)(jointDef));
				}else{
					return new b2WeldJointDef();
				}
			}else{
				return new b2WeldJointDef();
			}
		}

		void destructor(State & state, b2WeldJointDef * object){
			delete object;
		}

		inline int getBodyA(State & state, b2WeldJointDef * );

		inline int setBodyA(State & state, b2WeldJointDef * );

		inline int getBodyB(State & state, b2WeldJointDef * );

		inline int setBodyB(State & state, b2WeldJointDef * );

		inline int getType(State & state, b2WeldJointDef * );

		inline int setType(State & state, b2WeldJointDef * );

		inline int getCollideConnected(State & state, b2WeldJointDef * );

		inline int setCollideConnected(State & state, b2WeldJointDef * );
	};

	void initWeldJointDef(State * );
};

#endif	
