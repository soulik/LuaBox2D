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
		
			LUTOK_PROPERTY("localAnchorA", &RopeJointDef::getLocalAnchorA, &RopeJointDef::setLocalAnchorA);
			LUTOK_PROPERTY("localAnchorB", &RopeJointDef::getLocalAnchorB, &RopeJointDef::setLocalAnchorB);
			LUTOK_PROPERTY("maxLength", &RopeJointDef::getMaxLength, &RopeJointDef::setMaxLength);
			LUTOK_PROPERTY("userData", &RopeJointDef::getUserData, &RopeJointDef::setUserData);
		}

		b2RopeJointDef * constructor(State & state, bool & managed);

		void destructor(State & state, b2RopeJointDef * object);

		int getBodyA(State & state, b2RopeJointDef * );

		int setBodyA(State & state, b2RopeJointDef * );

		int getBodyB(State & state, b2RopeJointDef * );

		int setBodyB(State & state, b2RopeJointDef * );

		int getType(State & state, b2RopeJointDef * );

		int setType(State & state, b2RopeJointDef * );

		int getCollideConnected(State & state, b2RopeJointDef * );

		int setCollideConnected(State & state, b2RopeJointDef * );

		int getLocalAnchorA(State & state, b2RopeJointDef * object);

		int setLocalAnchorA(State & state, b2RopeJointDef * object);

		int getLocalAnchorB(State & state, b2RopeJointDef * object);

		int setLocalAnchorB(State & state, b2RopeJointDef * object);

		int getMaxLength(State & state, b2RopeJointDef * object);

		int setMaxLength(State & state, b2RopeJointDef * object);

		int getUserData(State & state, b2RopeJointDef * object);

		int setUserData(State & state, b2RopeJointDef * object);
	};

	void initRopeJointDef(State * );
};

#endif	
