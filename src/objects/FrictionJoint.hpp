#ifndef LUABOX2D_FRICTIONJOINT_H
#define LUABOX2D_FRICTIONJOINT_H

namespace LuaBox2D {
	class FrictionJoint : public Object<b2FrictionJoint> {
	private:
		Joint * base;
	public:
		explicit FrictionJoint(State * state) : Object<b2FrictionJoint>(state){
			base = state->getInterface<Joint>("LuaBox2D_Joint");
			LUTOK_PROPERTY("type", &FrictionJoint::getType, &FrictionJoint::nullMethod);
			LUTOK_PROPERTY("bodyA", &FrictionJoint::getBodyA, &FrictionJoint::nullMethod);
			LUTOK_PROPERTY("bodyB", &FrictionJoint::getBodyB, &FrictionJoint::nullMethod);

			LUTOK_PROPERTY("anchorA", &FrictionJoint::getAnchorA, &FrictionJoint::nullMethod);
			LUTOK_PROPERTY("anchorB", &FrictionJoint::getAnchorB, &FrictionJoint::nullMethod);
			LUTOK_PROPERTY("localAnchorA", &FrictionJoint::getLocalAnchorA, &FrictionJoint::nullMethod);
			LUTOK_PROPERTY("localAnchorB", &FrictionJoint::getLocalAnchorB, &FrictionJoint::nullMethod);

			LUTOK_METHOD("reactionForce", &FrictionJoint::getReactionForce);
			LUTOK_METHOD("reactionTorque", &FrictionJoint::getReactionTorque);

			LUTOK_PROPERTY("active", &FrictionJoint::getActive, &FrictionJoint::nullMethod);
			LUTOK_PROPERTY("collideConnected", &FrictionJoint::getCollideConnected, &FrictionJoint::nullMethod);
			LUTOK_PROPERTY("maxForce", &FrictionJoint::getMaxForce, &FrictionJoint::setMaxForce);
			LUTOK_PROPERTY("maxTorque", &FrictionJoint::getMaxTorque, &FrictionJoint::setMaxTorque);
			LUTOK_PROPERTY("userData", &FrictionJoint::getUserData, &FrictionJoint::setUserData);
		}

		b2FrictionJoint * constructor(State & state, bool & managed);

		void destructor(State & state, b2FrictionJoint * object);

		int getType(State & state, b2FrictionJoint * );

		int getBodyA(State & state, b2FrictionJoint *);

		int getBodyB(State & state, b2FrictionJoint *);

		int getReactionForce(State & state, b2FrictionJoint *);

		int getReactionTorque(State & state, b2FrictionJoint *);

		int getActive(State & state, b2FrictionJoint * );

		int getCollideConnected(State & state, b2FrictionJoint * );

		int getAnchorA(State & state, b2FrictionJoint *);

		int getAnchorB(State & state, b2FrictionJoint *);

		int getLocalAnchorA(State & state, b2FrictionJoint *);

		int getLocalAnchorB(State & state, b2FrictionJoint *);

		int getMaxForce(State & state, b2FrictionJoint * object);

		int setMaxForce(State & state, b2FrictionJoint * object);

		int getMaxTorque(State & state, b2FrictionJoint * object);

		int setMaxTorque(State & state, b2FrictionJoint * object);
		
		int getUserData(State & state, b2FrictionJoint * object);

		int setUserData(State & state, b2FrictionJoint * object);
	};

	void initFrictionJoint(State * );
};

#endif	
