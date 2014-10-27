#ifndef LUABOX2D_MOTORJOINTDEF_H
#define LUABOX2D_MOTORJOINTDEF_H

namespace LuaBox2D {
	class MotorJointDef : public Object<b2MotorJointDef> {
	private:
		JointDef * base;
	public:
		explicit MotorJointDef(State * state) : Object<b2MotorJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &MotorJointDef::getType, &MotorJointDef::setType);
			LUTOK_PROPERTY("bodyA", &MotorJointDef::getBodyA, &MotorJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &MotorJointDef::getBodyB, &MotorJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &MotorJointDef::getCollideConnected, &MotorJointDef::setCollideConnected);
		}

		b2MotorJointDef * constructor(State & state);

		void destructor(State & state, b2MotorJointDef * object);

		int getBodyA(State & state, b2MotorJointDef * );

		int setBodyA(State & state, b2MotorJointDef * );

		int getBodyB(State & state, b2MotorJointDef * );

		int setBodyB(State & state, b2MotorJointDef * );

		int getType(State & state, b2MotorJointDef * );

		int setType(State & state, b2MotorJointDef * );

		int getCollideConnected(State & state, b2MotorJointDef * );

		int setCollideConnected(State & state, b2MotorJointDef * );
	};

	void initMotorJointDef(State * );
};

#endif	
