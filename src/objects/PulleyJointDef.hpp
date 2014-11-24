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
			LUTOK_METHOD("initialize", &PulleyJointDef::initialize);

			LUTOK_PROPERTY("groundAnchorA", &PulleyJointDef::getGroundAnchorA, &PulleyJointDef::setGroundAnchorA);
			LUTOK_PROPERTY("groundAnchorB", &PulleyJointDef::getGroundAnchorB, &PulleyJointDef::setGroundAnchorB);
			LUTOK_PROPERTY("localAnchorA", &PulleyJointDef::getLocalAnchorA, &PulleyJointDef::setLocalAnchorA);
			LUTOK_PROPERTY("localAnchorB", &PulleyJointDef::getLocalAnchorB, &PulleyJointDef::setLocalAnchorB);
			LUTOK_PROPERTY("lengthA", &PulleyJointDef::getLengthA, &PulleyJointDef::setLengthA);
			LUTOK_PROPERTY("lengthB", &PulleyJointDef::getLengthB, &PulleyJointDef::setLengthB);
			LUTOK_PROPERTY("ratio", &PulleyJointDef::getRatio, &PulleyJointDef::setRatio);
			LUTOK_PROPERTY("userData", &PulleyJointDef::getUserData, &PulleyJointDef::setUserData);
		}

		b2PulleyJointDef * constructor(State & state, bool & managed);

		void destructor(State & state, b2PulleyJointDef * object);

		int getBodyA(State & state, b2PulleyJointDef * );

		int setBodyA(State & state, b2PulleyJointDef * );

		int getBodyB(State & state, b2PulleyJointDef * );

		int setBodyB(State & state, b2PulleyJointDef * );

		int getType(State & state, b2PulleyJointDef * );

		int setType(State & state, b2PulleyJointDef * );

		int getCollideConnected(State & state, b2PulleyJointDef * );

		int setCollideConnected(State & state, b2PulleyJointDef * );

		int initialize(State & state, b2PulleyJointDef * );

		int getLocalAnchorA(State & state, b2PulleyJointDef * object);

		int setLocalAnchorA(State & state, b2PulleyJointDef * object);

		int getLocalAnchorB(State & state, b2PulleyJointDef * object);

		int setLocalAnchorB(State & state, b2PulleyJointDef * object);

		int getGroundAnchorA(State & state, b2PulleyJointDef * object);

		int setGroundAnchorA(State & state, b2PulleyJointDef * object);

		int getGroundAnchorB(State & state, b2PulleyJointDef * object);

		int setGroundAnchorB(State & state, b2PulleyJointDef * object);

		int getLengthA(State & state, b2PulleyJointDef * object);

		int setLengthA(State & state, b2PulleyJointDef * object);

		int getLengthB(State & state, b2PulleyJointDef * object);

		int setLengthB(State & state, b2PulleyJointDef * object);

		int getRatio(State & state, b2PulleyJointDef * object);

		int setRatio(State & state, b2PulleyJointDef * object);

		int getUserData(State & state, b2PulleyJointDef * object);

		int setUserData(State & state, b2PulleyJointDef * object);
	};

	void initPulleyJointDef(State * );
};

#endif	
