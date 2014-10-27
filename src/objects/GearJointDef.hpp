#ifndef LUABOX2D_GEARJOINTDEF_H
#define LUABOX2D_GEARJOINTDEF_H

#include "objects/JointDef.hpp"

namespace LuaBox2D {
	class GearJointDef : public Object<b2GearJointDef> {
	private:
		JointDef * base;
	public:
		explicit GearJointDef(State * state) : Object<b2GearJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &GearJointDef::getType, &GearJointDef::setType);
			LUTOK_PROPERTY("bodyA", &GearJointDef::getBodyA, &GearJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &GearJointDef::getBodyB, &GearJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &GearJointDef::getCollideConnected, &GearJointDef::setCollideConnected);
		}

		b2GearJointDef * constructor(State & state){
			JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
			b2JointDef * jointDef = interfaceJointDef->get(1);
			if (jointDef != nullptr){
				if (jointDef->type == b2JointType::e_revoluteJoint){
					return new b2GearJointDef(*(b2GearJointDef*)(jointDef));
				}else{
					return new b2GearJointDef();
				}
			}else{
				return new b2GearJointDef();
			}
		}

		void destructor(State & state, b2GearJointDef * object){
			delete object;
		}

		inline int getBodyA(State & state, b2GearJointDef * );

		inline int setBodyA(State & state, b2GearJointDef * );

		inline int getBodyB(State & state, b2GearJointDef * );

		inline int setBodyB(State & state, b2GearJointDef * );

		inline int getType(State & state, b2GearJointDef * );

		inline int setType(State & state, b2GearJointDef * );

		inline int getCollideConnected(State & state, b2GearJointDef * );

		inline int setCollideConnected(State & state, b2GearJointDef * );
	};

	void initGearJointDef(State * );
};

#endif	
