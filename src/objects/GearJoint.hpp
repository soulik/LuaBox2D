#ifndef LUABOX2D_GEARJOINT_H
#define LUABOX2D_GEARJOINT_H

namespace LuaBox2D {
	class GearJoint : public Object<b2GearJoint> {
	private:
		Joint * base;
	public:
		explicit GearJoint(State * state) : Object<b2GearJoint>(state){
			base = state->getInterface<Joint>("LuaBox2D_Joint");
			LUTOK_PROPERTY("type", &GearJoint::getType, &GearJoint::nullMethod);
			LUTOK_PROPERTY("bodyA", &GearJoint::getBodyA, &GearJoint::nullMethod);
			LUTOK_PROPERTY("bodyB", &GearJoint::getBodyB, &GearJoint::nullMethod);

			LUTOK_PROPERTY("anchorA", &GearJoint::getAnchorA, &GearJoint::nullMethod);
			LUTOK_PROPERTY("anchorB", &GearJoint::getAnchorB, &GearJoint::nullMethod);

			LUTOK_METHOD("reactionForce", &GearJoint::getReactionForce);
			LUTOK_METHOD("reactionTorque", &GearJoint::getReactionTorque);

			LUTOK_PROPERTY("active", &GearJoint::getActive, &GearJoint::nullMethod);
			LUTOK_PROPERTY("collideConnected", &GearJoint::getCollideConnected, &GearJoint::nullMethod);

			LUTOK_PROPERTY("joint1", &GearJoint::getJoint1, &GearJoint::nullMethod);
			LUTOK_PROPERTY("joint2", &GearJoint::getJoint2, &GearJoint::nullMethod);
			LUTOK_PROPERTY("ratio", &GearJoint::getRatio, &GearJoint::setRatio);
			LUTOK_PROPERTY("userData", &GearJoint::getUserData, &GearJoint::setUserData);
		}

		b2GearJoint * constructor(State & state, bool & managed);

		void destructor(State & state, b2GearJoint * object);

		int getType(State & state, b2GearJoint * );

		int getBodyA(State & state, b2GearJoint *);

		int getBodyB(State & state, b2GearJoint *);

		int getAnchorA(State & state, b2GearJoint *);

		int getAnchorB(State & state, b2GearJoint *);

		int getReactionForce(State & state, b2GearJoint *);

		int getReactionTorque(State & state, b2GearJoint *);

		int getActive(State & state, b2GearJoint * );

		int getCollideConnected(State & state, b2GearJoint * );

		int getJoint1(State & state, b2GearJoint * object);

		int getJoint2(State & state, b2GearJoint * object);

		int getRatio(State & state, b2GearJoint * object);

		int setRatio(State & state, b2GearJoint * object);

		int getUserData(State & state, b2GearJoint * object);

		int setUserData(State & state, b2GearJoint * object);

	};

	void initGearJoint(State * );
};

#endif	
