#ifndef LUABOX2D_MOUSEJOINTDEF_H
#define LUABOX2D_MOUSEJOINTDEF_H

namespace LuaBox2D {
	class MouseJointDef : public Object<b2MouseJointDef> {
	private:
		JointDef * base;
	public:
		explicit MouseJointDef(State * state) : Object<b2MouseJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &MouseJointDef::getType, &MouseJointDef::setType);
			LUTOK_PROPERTY("bodyA", &MouseJointDef::getBodyA, &MouseJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &MouseJointDef::getBodyB, &MouseJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &MouseJointDef::getCollideConnected, &MouseJointDef::setCollideConnected);
		}

		b2MouseJointDef * constructor(State & state);

		void destructor(State & state, b2MouseJointDef * object);

		int getBodyA(State & state, b2MouseJointDef * );

		int setBodyA(State & state, b2MouseJointDef * );

		int getBodyB(State & state, b2MouseJointDef * );

		int setBodyB(State & state, b2MouseJointDef * );

		int getType(State & state, b2MouseJointDef * );

		int setType(State & state, b2MouseJointDef * );

		int getCollideConnected(State & state, b2MouseJointDef * );

		int setCollideConnected(State & state, b2MouseJointDef * );
	};

	void initMouseJointDef(State * );
};

#endif	
