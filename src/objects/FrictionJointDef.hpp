#ifndef LUABOX2D_FRICTIONJOINTDEF_H
#define LUABOX2D_FRICTIONJOINTDEF_H

namespace LuaBox2D {
	class FrictionJointDef : public Object<b2FrictionJointDef> {
	private:
		JointDef * base;
	public:
		explicit FrictionJointDef(State * state) : Object<b2FrictionJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &FrictionJointDef::getType, &FrictionJointDef::setType);
			LUTOK_PROPERTY("bodyA", &FrictionJointDef::getBodyA, &FrictionJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &FrictionJointDef::getBodyB, &FrictionJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &FrictionJointDef::getCollideConnected, &FrictionJointDef::setCollideConnected);
		}

		b2FrictionJointDef * constructor(State & state);

		void destructor(State & state, b2FrictionJointDef * object);

		int getBodyA(State & state, b2FrictionJointDef * );

		int setBodyA(State & state, b2FrictionJointDef * );

		int getBodyB(State & state, b2FrictionJointDef * );

		int setBodyB(State & state, b2FrictionJointDef * );

		int getType(State & state, b2FrictionJointDef * );

		int setType(State & state, b2FrictionJointDef * );

		int getCollideConnected(State & state, b2FrictionJointDef * );

		int setCollideConnected(State & state, b2FrictionJointDef * );
	};

	void initFrictionJointDef(State * );
};

#endif	
