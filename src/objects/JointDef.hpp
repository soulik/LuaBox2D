#ifndef LUABOX2D_JOINTDEF_H
#define LUABOX2D_JOINTDEF_H

namespace LuaBox2D {
	class JointDef : public Object<b2JointDef> {
	protected:
		std::forward_list<std::string> validTypes;
	public:
		explicit JointDef(State * state) : Object<b2JointDef>(state){
			LUTOK_PROPERTY("type", &JointDef::getType, &JointDef::setType);
			LUTOK_PROPERTY("bodyA", &JointDef::getBodyA, &JointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &JointDef::getBodyB, &JointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &JointDef::getCollideConnected, &JointDef::setCollideConnected);
			LUTOK_PROPERTY("userData", &JointDef::getUserData, &JointDef::setUserData);
			
			initAllowedTypes();
		}

		void initAllowedTypes();

		b2JointDef * constructor(State & state, bool &);

		void destructor(State & state, b2JointDef * object);

		b2JointDef * get(const int index);

		int getBodyA(State & state, b2JointDef *);

		int setBodyA(State & state, b2JointDef *);

		int getBodyB(State & state, b2JointDef *);

		int setBodyB(State & state, b2JointDef *);

		int getType(State & state, b2JointDef * object);

		int setType(State & state, b2JointDef * object);

		int getCollideConnected(State & state, b2JointDef * object);

		int setCollideConnected(State & state, b2JointDef * object);

		int getUserData(State & state, b2JointDef * object);

		int setUserData(State & state, b2JointDef * object);
	};

	void initJointDef(State * );
};

#endif	
