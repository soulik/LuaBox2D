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
			LUTOK_METHOD("initialize", &WeldJointDef::initialize);

			LUTOK_PROPERTY("localAnchorA", &WeldJointDef::getLocalAnchorA, &WeldJointDef::setLocalAnchorA);
			LUTOK_PROPERTY("localAnchorB", &WeldJointDef::getLocalAnchorB, &WeldJointDef::setLocalAnchorB);
			LUTOK_PROPERTY("referenceAngle", &WeldJointDef::getReferenceAngle, &WeldJointDef::setReferenceAngle);
			LUTOK_PROPERTY("frequencyHz", &WeldJointDef::getFrequencyHz, &WeldJointDef::setFrequencyHz);
			LUTOK_PROPERTY("dampingRatio", &WeldJointDef::getDampingRatio, &WeldJointDef::setDampingRatio);
			LUTOK_PROPERTY("userData", &WeldJointDef::getUserData, &WeldJointDef::setUserData);
		}

		b2WeldJointDef * constructor(State & state, bool & managed);

		void destructor(State & state, b2WeldJointDef * object);

		int getBodyA(State & state, b2WeldJointDef * );

		int setBodyA(State & state, b2WeldJointDef * );

		int getBodyB(State & state, b2WeldJointDef * );

		int setBodyB(State & state, b2WeldJointDef * );

		int getType(State & state, b2WeldJointDef * );

		int setType(State & state, b2WeldJointDef * );

		int getCollideConnected(State & state, b2WeldJointDef * );

		int setCollideConnected(State & state, b2WeldJointDef * );

		int initialize(State & state, b2WeldJointDef * );

		int getLocalAnchorA(State & state, b2WeldJointDef * object);

		int setLocalAnchorA(State & state, b2WeldJointDef * object);

		int getLocalAnchorB(State & state, b2WeldJointDef * object);

		int setLocalAnchorB(State & state, b2WeldJointDef * object);

		int getReferenceAngle(State & state, b2WeldJointDef * object);

		int setReferenceAngle(State & state, b2WeldJointDef * object);

		int getFrequencyHz(State & state, b2WeldJointDef * object);

		int setFrequencyHz(State & state, b2WeldJointDef * object);

		int getDampingRatio(State & state, b2WeldJointDef * object);

		int setDampingRatio(State & state, b2WeldJointDef * object);

		int getUserData(State & state, b2WeldJointDef * object);

		int setUserData(State & state, b2WeldJointDef * object);
	};

	void initWeldJointDef(State * );
};

#endif	
