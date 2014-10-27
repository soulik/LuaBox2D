#ifndef LUABOX2D_WHEELJOINTDEF_H
#define LUABOX2D_WHEELJOINTDEF_H

namespace LuaBox2D {
	class WheelJointDef : public Object<b2WheelJointDef> {
	private:
		JointDef * base;
	public:
		explicit WheelJointDef(State * state) : Object<b2WheelJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &WheelJointDef::getType, &WheelJointDef::setType);
			LUTOK_PROPERTY("bodyA", &WheelJointDef::getBodyA, &WheelJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &WheelJointDef::getBodyB, &WheelJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &WheelJointDef::getCollideConnected, &WheelJointDef::setCollideConnected);
		}

		b2WheelJointDef * constructor(State & state);

		void destructor(State & state, b2WheelJointDef * object);

		int getBodyA(State & state, b2WheelJointDef * );

		int setBodyA(State & state, b2WheelJointDef * );

		int getBodyB(State & state, b2WheelJointDef * );

		int setBodyB(State & state, b2WheelJointDef * );

		int getType(State & state, b2WheelJointDef * );

		int setType(State & state, b2WheelJointDef * );

		int getCollideConnected(State & state, b2WheelJointDef * );

		int setCollideConnected(State & state, b2WheelJointDef * );
	};

	void initWheelJointDef(State * );
};

#endif	
