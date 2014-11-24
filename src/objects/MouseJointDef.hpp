#ifndef LUABOX2D_MOUSEJOINTDEF_H
#define LUABOX2D_MOUSEJOINTDEF_H

namespace LuaBox2D {
	class MouseJointDef : public Object<b2MouseJointDef> {
	private:
		JointDef * base;
	public:
		explicit MouseJointDef(State * state) : Object<b2MouseJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &MouseJointDef::getType, &MouseJointDef::setType);
			LUTOK_PROPERTY("bodyA", &MouseJointDef::getBodyA, &MouseJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &MouseJointDef::getBodyB, &MouseJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &MouseJointDef::getCollideConnected, &MouseJointDef::setCollideConnected);

			LUTOK_PROPERTY("target", &MouseJointDef::getTarget, &MouseJointDef::setTarget);
			LUTOK_PROPERTY("maxForce", &MouseJointDef::getMaxForce, &MouseJointDef::setMaxForce);
			LUTOK_PROPERTY("frequencyHz", &MouseJointDef::getFrequencyHz, &MouseJointDef::setFrequencyHz);
			LUTOK_PROPERTY("dampingRatio", &MouseJointDef::getDampingRatio, &MouseJointDef::setDampingRatio);
			LUTOK_PROPERTY("userData", &MouseJointDef::getUserData, &MouseJointDef::setUserData);
		}

		b2MouseJointDef * constructor(State & state, bool & managed);

		void destructor(State & state, b2MouseJointDef * object);

		int getBodyA(State & state, b2MouseJointDef * );

		int setBodyA(State & state, b2MouseJointDef * );

		int getBodyB(State & state, b2MouseJointDef * );

		int setBodyB(State & state, b2MouseJointDef * );

		int getType(State & state, b2MouseJointDef * );

		int setType(State & state, b2MouseJointDef * );

		int getCollideConnected(State & state, b2MouseJointDef * );

		int setCollideConnected(State & state, b2MouseJointDef * );

		int getTarget(State & state, b2MouseJointDef * object);

		int setTarget(State & state, b2MouseJointDef * object);

		int getMaxForce(State & state, b2MouseJointDef * object);

		int setMaxForce(State & state, b2MouseJointDef * object);

		int getFrequencyHz(State & state, b2MouseJointDef * object);

		int setFrequencyHz(State & state, b2MouseJointDef * object);

		int getDampingRatio(State & state, b2MouseJointDef * object);

		int setDampingRatio(State & state, b2MouseJointDef * object);

		int getUserData(State & state, b2MouseJointDef * object);

		int setUserData(State & state, b2MouseJointDef * object);

	};

	void initMouseJointDef(State * );
};

#endif	
