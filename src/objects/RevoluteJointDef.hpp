#ifndef LUABOX2D_REVOLUTEJOINTDEF_H
#define LUABOX2D_REVOLUTEJOINTDEF_H

namespace LuaBox2D {
	class RevoluteJointDef : public Object<b2RevoluteJointDef> {
	private:
		JointDef * base;
	public:
		explicit RevoluteJointDef(State * state) : Object<b2RevoluteJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &RevoluteJointDef::getType, &RevoluteJointDef::setType);
			LUTOK_PROPERTY("bodyA", &RevoluteJointDef::getBodyA, &RevoluteJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &RevoluteJointDef::getBodyB, &RevoluteJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &RevoluteJointDef::getCollideConnected, &RevoluteJointDef::setCollideConnected);
		}

		b2RevoluteJointDef * constructor(State & state);

		void destructor(State & state, b2RevoluteJointDef * object);

		int getBodyA(State & state, b2RevoluteJointDef * );

		int setBodyA(State & state, b2RevoluteJointDef * );

		int getBodyB(State & state, b2RevoluteJointDef * );

		int setBodyB(State & state, b2RevoluteJointDef * );

		int getType(State & state, b2RevoluteJointDef * );

		int setType(State & state, b2RevoluteJointDef * );

		int getCollideConnected(State & state, b2RevoluteJointDef * );

		int setCollideConnected(State & state, b2RevoluteJointDef * );
	};

	void initRevoluteJointDef(State * );
};

#endif	
