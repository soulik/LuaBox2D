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

			LUTOK_PROPERTY("next", &Joint::getNext, &Joint::nullMethod);
			LUTOK_PROPERTY("userData", &Joint::getUserData, &Joint::setUserData);

			initAllowedTypes();
		}

		void initAllowedTypes();

		b2Joint * constructor(State & state, bool & managed);

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

		int getNext(State & state, b2Joint * object);

		int getUserData(State & state, b2Joint * object);

		int setUserData(State & state, b2Joint * object);

	};

	void initJoint(State * );
};

#endif	
