#ifndef LUABOX2D_JOINTDEF_H
#define LUABOX2D_JOINTDEF_H

#include "objects/Body.hpp"

namespace LuaBox2D {
	class JointDef : public Object<b2JointDef> {
	protected:
		std::forward_list<std::string> validTypes;
	public:
		explicit JointDef(State * state) : Object<b2JointDef>(state){
			LUTOK_PROPERTY("type", &JointDef::getType, &JointDef::setType);
			LUTOK_PROPERTY("bodyA", &JointDef::getBodyA, &JointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &JointDef::getBodyB, &JointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &JointDef::getCollideConnected, &JointDef::setCollideConnected);

			validTypes.push_front("JointDef");
			validTypes.push_front("RevoluteJointDef");
			validTypes.push_front("PrismaticJointDef");
			validTypes.push_front("DistanceJointDef");
			validTypes.push_front("PulleyJointDef");
			validTypes.push_front("MouseJointDef");
			validTypes.push_front("GearJointDef");
			validTypes.push_front("WheelJointDef");
			validTypes.push_front("WeldJointDef");
			validTypes.push_front("FrictionJointDef");
			validTypes.push_front("RopeJointDef");
			validTypes.push_front("MotorJointDef");
		}

		b2JointDef * constructor(State & );

		void destructor(State & state, b2JointDef * object){
			delete object;
		}

		b2JointDef * get(const int index){
			ObjWrapper * wrapper = getWrapped(index, validTypes);
			if (wrapper){
				return wrapper->instance;
			}else{

				return nullptr;
			}
		}

		int getBodyA(State & state, b2JointDef *);

		int setBodyA(State & state, b2JointDef *);

		int getBodyB(State & state, b2JointDef *);

		int setBodyB(State & state, b2JointDef *);

		int getType(State & state, b2JointDef * object){
			state.stack->push<int>(static_cast<int>(object->type));
			return 1;
		}

		int setType(State & state, b2JointDef * object){
			object->type = static_cast<b2JointType>(state.stack->to<int>(1));
			return 0;
		}

		int getCollideConnected(State & state, b2JointDef * object){
			state.stack->push<bool>(object->collideConnected);
			return 1;
		}

		int setCollideConnected(State & state, b2JointDef * object){
			object->collideConnected =  state.stack->to<bool>(1);
			return 0;
		}
	};

	void initJointDef(State * );
};

#endif	
