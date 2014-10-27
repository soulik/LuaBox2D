#ifndef LUABOX2D_GEARJOINTDEF_H
#define LUABOX2D_GEARJOINTDEF_H

namespace LuaBox2D {
	class GearJointDef : public Object<b2GearJointDef> {
	private:
		JointDef * base;
	public:
		explicit GearJointDef(State * state) : Object<b2GearJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &GearJointDef::getType, &GearJointDef::setType);
			LUTOK_PROPERTY("bodyA", &GearJointDef::getBodyA, &GearJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &GearJointDef::getBodyB, &GearJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &GearJointDef::getCollideConnected, &GearJointDef::setCollideConnected);
		}

		b2GearJointDef * constructor(State & state);

		void destructor(State & state, b2GearJointDef * object);

		int getBodyA(State & state, b2GearJointDef * );

		int setBodyA(State & state, b2GearJointDef * );

		int getBodyB(State & state, b2GearJointDef * );

		int setBodyB(State & state, b2GearJointDef * );

		int getType(State & state, b2GearJointDef * );

		int setType(State & state, b2GearJointDef * );

		int getCollideConnected(State & state, b2GearJointDef * );

		int setCollideConnected(State & state, b2GearJointDef * );
	};

	void initGearJointDef(State * );
};

#endif	
