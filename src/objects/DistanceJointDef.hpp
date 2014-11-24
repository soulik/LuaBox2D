#ifndef LUABOX2D_DISTANCEJOINTDEF_H
#define LUABOX2D_DISTANCEJOINTDEF_H

namespace LuaBox2D {
	class DistanceJointDef : public Object<b2DistanceJointDef> {
	private:
		JointDef * base;
	public:
		explicit DistanceJointDef(State * state) : Object<b2DistanceJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &DistanceJointDef::getType, &DistanceJointDef::setType);
			LUTOK_PROPERTY("bodyA", &DistanceJointDef::getBodyA, &DistanceJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &DistanceJointDef::getBodyB, &DistanceJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &DistanceJointDef::getCollideConnected, &DistanceJointDef::setCollideConnected);
			LUTOK_METHOD("initialize", &DistanceJointDef::initialize);

			LUTOK_PROPERTY("localAnchorA", &DistanceJointDef::getLocalAnchorA, &DistanceJointDef::setLocalAnchorA);
			LUTOK_PROPERTY("localAnchorB", &DistanceJointDef::getLocalAnchorB, &DistanceJointDef::setLocalAnchorB);
			LUTOK_PROPERTY("length", &DistanceJointDef::getLength, &DistanceJointDef::setLength);
			LUTOK_PROPERTY("frequencyHz", &DistanceJointDef::getFrequencyHz, &DistanceJointDef::setFrequencyHz);
			LUTOK_PROPERTY("dampingRatio", &DistanceJointDef::getDampingRatio, &DistanceJointDef::setDampingRatio);
			LUTOK_PROPERTY("userData", &DistanceJointDef::getUserData, &DistanceJointDef::setUserData);
		}

		b2DistanceJointDef * constructor(State & state, bool & managed);

		void destructor(State & state, b2DistanceJointDef * object);

		int getBodyA(State & state, b2DistanceJointDef * );

		int setBodyA(State & state, b2DistanceJointDef * );

		int getBodyB(State & state, b2DistanceJointDef * );

		int setBodyB(State & state, b2DistanceJointDef * );

		int getType(State & state, b2DistanceJointDef * );

		int setType(State & state, b2DistanceJointDef * );

		int getCollideConnected(State & state, b2DistanceJointDef * );

		int setCollideConnected(State & state, b2DistanceJointDef * );

		int initialize(State & state, b2DistanceJointDef * );

		int getLocalAnchorA(State & state, b2DistanceJointDef * object);

		int setLocalAnchorA(State & state, b2DistanceJointDef * object);

		int getLocalAnchorB(State & state, b2DistanceJointDef * object);

		int setLocalAnchorB(State & state, b2DistanceJointDef * object);

		int getLength(State & state, b2DistanceJointDef * object);

		int setLength(State & state, b2DistanceJointDef * object);

		int getFrequencyHz(State & state, b2DistanceJointDef * object);

		int setFrequencyHz(State & state, b2DistanceJointDef * object);

		int getDampingRatio(State & state, b2DistanceJointDef * object);

		int setDampingRatio(State & state, b2DistanceJointDef * object);

		int getUserData(State & state, b2DistanceJointDef * object);

		int setUserData(State & state, b2DistanceJointDef * object);
	};

	void initDistanceJointDef(State * );
};

#endif	
