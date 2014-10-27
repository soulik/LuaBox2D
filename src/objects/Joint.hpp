#ifndef LUABOX2D_JOINT_H
#define LUABOX2D_JOINT_H

namespace LuaBox2D {
	class Joint : public Object<b2Joint> {
	protected:
		std::forward_list<std::string> validTypes;
	public:
		explicit Joint(State * state) : Object<b2Joint>(state){
			LUTOK_PROPERTY("type", &Joint::getType, &Joint::nullMethod);
			LUTOK_PROPERTY("bodyA", &Joint::getBodyA, &Joint::nullMethod);
			LUTOK_PROPERTY("bodyB", &Joint::getBodyB, &Joint::nullMethod);

			LUTOK_PROPERTY("anchorA", &Joint::getAnchorA, &Joint::nullMethod);
			LUTOK_PROPERTY("anchorB", &Joint::getAnchorB, &Joint::nullMethod);

			LUTOK_METHOD("reactionForce", &Joint::getReactionForce);
			LUTOK_METHOD("reactionTorque", &Joint::getReactionTorque);

			LUTOK_PROPERTY("active", &Joint::getActive, &Joint::nullMethod);
			LUTOK_PROPERTY("collideConnected", &Joint::getCollideConnected, &Joint::nullMethod);

			ADD_VALID_TYPE(Joint);
			ADD_VALID_TYPE(RevoluteJoint);
			ADD_VALID_TYPE(PrismaticJoint);
			ADD_VALID_TYPE(DistanceJoint);
			ADD_VALID_TYPE(PulleyJoint);
			ADD_VALID_TYPE(MouseJoint);
			ADD_VALID_TYPE(GearJoint);
			ADD_VALID_TYPE(WheelJoint);
			ADD_VALID_TYPE(WeldJoint);
			ADD_VALID_TYPE(FrictionJoint);
			ADD_VALID_TYPE(RopeJoint);
			ADD_VALID_TYPE(MotorJoint);
		}

		b2Joint * constructor(State & );

		b2Joint * get(const int index);

		void destructor(State & state, b2Joint * object);

		int getType(State & state, b2Joint * object);

		int getBodyA(State & state, b2Joint *);

		int getBodyB(State & state, b2Joint *);

		int getAnchorA(State & state, b2Joint *);

		int getAnchorB(State & state, b2Joint *);

		int getReactionForce(State & state, b2Joint *);

		int getReactionTorque(State & state, b2Joint *);

		int getActive(State & state, b2Joint * object);

		int getCollideConnected(State & state, b2Joint * object);

	};

	void initJoint(State * );
};

#endif	
