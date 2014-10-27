#ifndef LUABOX2D_ROPEJOINTDEF_H
#define LUABOX2D_ROPEJOINTDEF_H

namespace LuaBox2D {
	class RopeJointDef : public Object<b2RopeJointDef> {
	private:
		JointDef * base;
	public:
		explicit RopeJointDef(State * state) : Object<b2RopeJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &RopeJointDef::getType, &RopeJointDef::setType);
			LUTOK_PROPERTY("bodyA", &RopeJointDef::getBodyA, &RopeJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &RopeJointDef::getBodyB, &RopeJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &RopeJointDef::getCollideConnected, &RopeJointDef::setCollideConnected);
		}

		b2RopeJointDef * constructor(State & state);

		void destructor(State & state, b2RopeJointDef * object);

		int getBodyA(State & state, b2RopeJointDef * );

		int setBodyA(State & state, b2RopeJointDef * );

		int getBodyB(State & state, b2RopeJointDef * );

		int setBodyB(State & state, b2RopeJointDef * );

		int getType(State & state, b2RopeJointDef * );

		int setType(State & state, b2RopeJointDef * );

		int getCollideConnected(State & state, b2RopeJointDef * );

		int setCollideConnected(State & state, b2RopeJointDef * );
	};

	void initRopeJointDef(State * );
};

#endif	
