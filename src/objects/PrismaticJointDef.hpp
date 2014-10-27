#ifndef LUABOX2D_PRISMATICJOINTDEF_H
#define LUABOX2D_PRISMATICJOINTDEF_H

#include "objects/JointDef.hpp"

namespace LuaBox2D {
	class PrismaticJointDef : public Object<b2PrismaticJointDef> {
	private:
		JointDef * base;
	public:
		explicit PrismaticJointDef(State * state) : Object<b2PrismaticJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &PrismaticJointDef::getType, &PrismaticJointDef::setType);
			LUTOK_PROPERTY("bodyA", &PrismaticJointDef::getBodyA, &PrismaticJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &PrismaticJointDef::getBodyB, &PrismaticJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &PrismaticJointDef::getCollideConnected, &PrismaticJointDef::setCollideConnected);
		}

		b2PrismaticJointDef * constructor(State & state){
			JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
			b2JointDef * jointDef = interfaceJointDef->get(1);
			if (jointDef != nullptr){
				if (jointDef->type == b2JointType::e_revoluteJoint){
					return new b2PrismaticJointDef(*(b2PrismaticJointDef*)(jointDef));
				}else{
					return new b2PrismaticJointDef();
				}
			}else{
				return new b2PrismaticJointDef();
			}
		}

		void destructor(State & state, b2PrismaticJointDef * object){
			delete object;
		}

		inline int getBodyA(State & state, b2PrismaticJointDef * );

		inline int setBodyA(State & state, b2PrismaticJointDef * );

		inline int getBodyB(State & state, b2PrismaticJointDef * );

		inline int setBodyB(State & state, b2PrismaticJointDef * );

		inline int getType(State & state, b2PrismaticJointDef * );

		inline int setType(State & state, b2PrismaticJointDef * );

		inline int getCollideConnected(State & state, b2PrismaticJointDef * );

		inline int setCollideConnected(State & state, b2PrismaticJointDef * );
	};

	void initPrismaticJointDef(State * );
};

#endif	
