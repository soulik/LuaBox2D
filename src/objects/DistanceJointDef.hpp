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
		}

		b2DistanceJointDef * constructor(State & state);

		void destructor(State & state, b2DistanceJointDef * object);

		int getBodyA(State & state, b2DistanceJointDef * );

		int setBodyA(State & state, b2DistanceJointDef * );

		int getBodyB(State & state, b2DistanceJointDef * );

		int setBodyB(State & state, b2DistanceJointDef * );

		int getType(State & state, b2DistanceJointDef * );

		int setType(State & state, b2DistanceJointDef * );

		int getCollideConnected(State & state, b2DistanceJointDef * );

		int setCollideConnected(State & state, b2DistanceJointDef * );
	};

	void initDistanceJointDef(State * );
};

#endif	
