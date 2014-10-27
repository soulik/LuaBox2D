#ifndef LUABOX2D_WELDJOINTDEF_H
#define LUABOX2D_WELDJOINTDEF_H

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

		b2WeldJointDef * constructor(State & state);

		void destructor(State & state, b2WeldJointDef * object);

		int getBodyA(State & state, b2WeldJointDef * );

		int setBodyA(State & state, b2WeldJointDef * );

		int getBodyB(State & state, b2WeldJointDef * );

		int setBodyB(State & state, b2WeldJointDef * );

		int getType(State & state, b2WeldJointDef * );

		int setType(State & state, b2WeldJointDef * );

		int getCollideConnected(State & state, b2WeldJointDef * );

		int setCollideConnected(State & state, b2WeldJointDef * );
	};

	void initWeldJointDef(State * );
};

#endif	
