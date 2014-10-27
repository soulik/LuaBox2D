#ifndef LUABOX2D_PULLEYJOINTDEF_H
#define LUABOX2D_PULLEYJOINTDEF_H

namespace LuaBox2D {
	class PulleyJointDef : public Object<b2PulleyJointDef> {
	private:
		JointDef * base;
	public:
		explicit PulleyJointDef(State * state) : Object<b2PulleyJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &PulleyJointDef::getType, &PulleyJointDef::setType);
			LUTOK_PROPERTY("bodyA", &PulleyJointDef::getBodyA, &PulleyJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &PulleyJointDef::getBodyB, &PulleyJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &PulleyJointDef::getCollideConnected, &PulleyJointDef::setCollideConnected);
		}

		b2PulleyJointDef * constructor(State & state);

		void destructor(State & state, b2PulleyJointDef * object);

		int getBodyA(State & state, b2PulleyJointDef * );

		int setBodyA(State & state, b2PulleyJointDef * );

		int getBodyB(State & state, b2PulleyJointDef * );

		int setBodyB(State & state, b2PulleyJointDef * );

		int getType(State & state, b2PulleyJointDef * );

		int setType(State & state, b2PulleyJointDef * );

		int getCollideConnected(State & state, b2PulleyJointDef * );

		int setCollideConnected(State & state, b2PulleyJointDef * );
	};

	void initPulleyJointDef(State * );
};

#endif	
