#ifndef LUABOX2D_DISTANCEJOINTDEF_H
#define LUABOX2D_DISTANCEJOINTDEF_H

#include "objects/JointDef.hpp"

namespace LuaBox2D {
	class DistanceJointDef : public Object<b2DistanceJointDef> {
	private:
		JointDef * base;
	public:
		explicit DistanceJointDef(State * state) : Object<b2DistanceJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &DistanceJointDef::getType, &DistanceJointDef::setType);
			LUTOK_PROPERTY("bodyA", &DistanceJointDef::getBodyA, &DistanceJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &DistanceJointDef::getBodyB, &DistanceJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &DistanceJointDef::getCollideConnected, &DistanceJointDef::setCollideConnected);
		}

		b2DistanceJointDef * constructor(State & state){
			JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
			b2JointDef * jointDef = interfaceJointDef->get(1);
			if (jointDef != nullptr){
				if (jointDef->type == b2JointType::e_revoluteJoint){
					return new b2DistanceJointDef(*(b2DistanceJointDef*)(jointDef));
				}else{
					return new b2DistanceJointDef();
				}
			}else{
				return new b2DistanceJointDef();
			}
		}

		void destructor(State & state, b2DistanceJointDef * object){
			delete object;
		}

		inline int getBodyA(State & state, b2DistanceJointDef * );

		inline int setBodyA(State & state, b2DistanceJointDef * );

		inline int getBodyB(State & state, b2DistanceJointDef * );

		inline int setBodyB(State & state, b2DistanceJointDef * );

		inline int getType(State & state, b2DistanceJointDef * );

		inline int setType(State & state, b2DistanceJointDef * );

		inline int getCollideConnected(State & state, b2DistanceJointDef * );

		inline int setCollideConnected(State & state, b2DistanceJointDef * );
	};

	void initDistanceJointDef(State * );
};

#endif	
