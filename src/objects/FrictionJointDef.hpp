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
			LUTOK_METHOD("initialize", &FrictionJointDef::initialize);

			LUTOK_PROPERTY("localAnchorA", &FrictionJointDef::getLocalAnchorA, &FrictionJointDef::setLocalAnchorA);
			LUTOK_PROPERTY("localAnchorB", &FrictionJointDef::getLocalAnchorB, &FrictionJointDef::setLocalAnchorB);
			LUTOK_PROPERTY("maxForce", &FrictionJointDef::getMaxForce, &FrictionJointDef::setMaxForce);
			LUTOK_PROPERTY("maxTorque", &FrictionJointDef::getMaxTorque, &FrictionJointDef::setMaxTorque);
			LUTOK_PROPERTY("userData", &FrictionJointDef::getUserData, &FrictionJointDef::setUserData);
		}

		b2FrictionJointDef * constructor(State & state, bool & managed);

		void destructor(State & state, b2FrictionJointDef * object);

		int getBodyA(State & state, b2FrictionJointDef * );

		int setBodyA(State & state, b2FrictionJointDef * );

		int getBodyB(State & state, b2FrictionJointDef * );

		int setBodyB(State & state, b2FrictionJointDef * );

		int getType(State & state, b2FrictionJointDef * );

		int setType(State & state, b2FrictionJointDef * );

		int getCollideConnected(State & state, b2FrictionJointDef * );

		int setCollideConnected(State & state, b2FrictionJointDef * );

		int initialize(State & state, b2FrictionJointDef * );

		int getLocalAnchorA(State & state, b2FrictionJointDef * object);

		int setLocalAnchorA(State & state, b2FrictionJointDef * object);

		int getLocalAnchorB(State & state, b2FrictionJointDef * object);

		int setLocalAnchorB(State & state, b2FrictionJointDef * object);

		int getMaxForce(State & state, b2FrictionJointDef * object);

		int setMaxForce(State & state, b2FrictionJointDef * object);

		int getMaxTorque(State & state, b2FrictionJointDef * object);

		int setMaxTorque(State & state, b2FrictionJointDef * object);

		int getUserData(State & state, b2FrictionJointDef * object);

		int setUserData(State & state, b2FrictionJointDef * object);
	};

	void initFrictionJointDef(State * );
};

#endif	
