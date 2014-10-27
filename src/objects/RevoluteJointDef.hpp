#ifndef LUABOX2D_REVOLUTEJOINTDEF_H
#define LUABOX2D_REVOLUTEJOINTDEF_H

#include "objects/JointDef.hpp"

namespace LuaBox2D {
	class RevoluteJointDef : public Object<b2RevoluteJointDef> {
	private:
		JointDef * base;
	public:
		explicit RevoluteJointDef(State * state) : Object<b2RevoluteJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &RevoluteJointDef::getType, &RevoluteJointDef::setType);
			LUTOK_PROPERTY("bodyA", &RevoluteJointDef::getBodyA, &RevoluteJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &RevoluteJointDef::getBodyB, &RevoluteJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &RevoluteJointDef::getCollideConnected, &RevoluteJointDef::setCollideConnected);
		}

		b2RevoluteJointDef * constructor(State & state){
			JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
			b2JointDef * jointDef = interfaceJointDef->get(1);
			if (jointDef != nullptr){
				if (jointDef->type == b2JointType::e_revoluteJoint){
					return new b2RevoluteJointDef(*(b2RevoluteJointDef*)(jointDef));
				}else{
					return new b2RevoluteJointDef();
				}
			}else{
				return new b2RevoluteJointDef();
			}
		}

		void destructor(State & state, b2RevoluteJointDef * object){
			delete object;
		}

		inline int getBodyA(State & state, b2RevoluteJointDef * );

		inline int setBodyA(State & state, b2RevoluteJointDef * );

		inline int getBodyB(State & state, b2RevoluteJointDef * );

		inline int setBodyB(State & state, b2RevoluteJointDef * );

		inline int getType(State & state, b2RevoluteJointDef * );

		inline int setType(State & state, b2RevoluteJointDef * );

		inline int getCollideConnected(State & state, b2RevoluteJointDef * );

		inline int setCollideConnected(State & state, b2RevoluteJointDef * );
	};

	void initRevoluteJointDef(State * );
};

#endif	
