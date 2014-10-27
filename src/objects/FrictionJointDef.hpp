#ifndef LUABOX2D_FRICTIONJOINTDEF_H
#define LUABOX2D_FRICTIONJOINTDEF_H

#include "objects/JointDef.hpp"

namespace LuaBox2D {
	class FrictionJointDef : public Object<b2FrictionJointDef> {
	private:
		JointDef * base;
	public:
		explicit FrictionJointDef(State * state) : Object<b2FrictionJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &FrictionJointDef::getType, &FrictionJointDef::setType);
			LUTOK_PROPERTY("bodyA", &FrictionJointDef::getBodyA, &FrictionJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &FrictionJointDef::getBodyB, &FrictionJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &FrictionJointDef::getCollideConnected, &FrictionJointDef::setCollideConnected);
		}

		b2FrictionJointDef * constructor(State & state){
			JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
			b2JointDef * jointDef = interfaceJointDef->get(1);
			if (jointDef != nullptr){
				if (jointDef->type == b2JointType::e_revoluteJoint){
					return new b2FrictionJointDef(*(b2FrictionJointDef*)(jointDef));
				}else{
					return new b2FrictionJointDef();
				}
			}else{
				return new b2FrictionJointDef();
			}
		}

		void destructor(State & state, b2FrictionJointDef * object){
			delete object;
		}

		inline int getBodyA(State & state, b2FrictionJointDef * );

		inline int setBodyA(State & state, b2FrictionJointDef * );

		inline int getBodyB(State & state, b2FrictionJointDef * );

		inline int setBodyB(State & state, b2FrictionJointDef * );

		inline int getType(State & state, b2FrictionJointDef * );

		inline int setType(State & state, b2FrictionJointDef * );

		inline int getCollideConnected(State & state, b2FrictionJointDef * );

		inline int setCollideConnected(State & state, b2FrictionJointDef * );
	};

	void initFrictionJointDef(State * );
};

#endif	
