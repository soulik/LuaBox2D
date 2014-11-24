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

			LUTOK_PROPERTY("joint1", &GearJointDef::getJoint1, &GearJointDef::setJoint1);
			LUTOK_PROPERTY("joint2", &GearJointDef::getJoint2, &GearJointDef::setJoint2);
			LUTOK_PROPERTY("ratio", &GearJointDef::getRatio, &GearJointDef::setRatio);
			LUTOK_PROPERTY("userData", &GearJointDef::getUserData, &GearJointDef::setUserData);
		}

		b2GearJointDef * constructor(State & state, bool & managed);

		void destructor(State & state, b2GearJointDef * object);

		int getBodyA(State & state, b2GearJointDef * );

		int setBodyA(State & state, b2GearJointDef * );

		int getBodyB(State & state, b2GearJointDef * );

		int setBodyB(State & state, b2GearJointDef * );

		int getType(State & state, b2GearJointDef * );

		int setType(State & state, b2GearJointDef * );

		int getCollideConnected(State & state, b2GearJointDef * );

		int setCollideConnected(State & state, b2GearJointDef * );

		int getJoint1(State & state, b2GearJointDef * object);

		int setJoint1(State & state, b2GearJointDef * object);

		int getJoint2(State & state, b2GearJointDef * object);

		int setJoint2(State & state, b2GearJointDef * object);

		int getRatio(State & state, b2GearJointDef * object);

		int setRatio(State & state, b2GearJointDef * object);

		int getUserData(State & state, b2GearJointDef * object);

		int setUserData(State & state, b2GearJointDef * object);
	};

	void initGearJointDef(State * );
};

#endif	
