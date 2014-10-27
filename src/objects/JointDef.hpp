#ifndef LUABOX2D_JOINTDEF_H
#define LUABOX2D_JOINTDEF_H

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
			
			ADD_VALID_STRUCT(JointDef);
			ADD_VALID_STRUCT(RevoluteJointDef);
			ADD_VALID_STRUCT(PrismaticJointDef);
			ADD_VALID_STRUCT(DistanceJointDef);
			ADD_VALID_STRUCT(PulleyJointDef);
			ADD_VALID_STRUCT(MouseJointDef);
			ADD_VALID_STRUCT(GearJointDef);
			ADD_VALID_STRUCT(WheelJointDef);
			ADD_VALID_STRUCT(WeldJointDef);
			ADD_VALID_STRUCT(FrictionJointDef);
			ADD_VALID_STRUCT(RopeJointDef);
			ADD_VALID_STRUCT(MotorJointDef);
		}

		b2JointDef * constructor(State & );

		void destructor(State & state, b2JointDef * object);

		b2JointDef * get(const int index);

		int getBodyA(State & state, b2JointDef *);

		int setBodyA(State & state, b2JointDef *);

		int getBodyB(State & state, b2JointDef *);

		int setBodyB(State & state, b2JointDef *);

		int getType(State & state, b2JointDef * object);

		int setType(State & state, b2JointDef * object);

		int getCollideConnected(State & state, b2JointDef * object);

		int setCollideConnected(State & state, b2JointDef * object);
	};

	void initJointDef(State * );
};

#endif	
