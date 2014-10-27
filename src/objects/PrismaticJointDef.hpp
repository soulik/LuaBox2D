#ifndef LUABOX2D_PRISMATICJOINTDEF_H
#define LUABOX2D_PRISMATICJOINTDEF_H

namespace LuaBox2D {
	class PrismaticJointDef : public Object<b2PrismaticJointDef> {
	private:
		JointDef * base;
	public:
		explicit PrismaticJointDef(State * state) : Object<b2PrismaticJointDef>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &PrismaticJointDef::getType, &PrismaticJointDef::setType);
			LUTOK_PROPERTY("bodyA", &PrismaticJointDef::getBodyA, &PrismaticJointDef::setBodyA);
			LUTOK_PROPERTY("bodyB", &PrismaticJointDef::getBodyB, &PrismaticJointDef::setBodyB);
			LUTOK_PROPERTY("collideConnected", &PrismaticJointDef::getCollideConnected, &PrismaticJointDef::setCollideConnected);
		}

		b2PrismaticJointDef * constructor(State & state);

		void destructor(State & state, b2PrismaticJointDef * object);

		int getBodyA(State & state, b2PrismaticJointDef * );

		int setBodyA(State & state, b2PrismaticJointDef * );

		int getBodyB(State & state, b2PrismaticJointDef * );

		int setBodyB(State & state, b2PrismaticJointDef * );

		int getType(State & state, b2PrismaticJointDef * );

		int setType(State & state, b2PrismaticJointDef * );

		int getCollideConnected(State & state, b2PrismaticJointDef * );

		int setCollideConnected(State & state, b2PrismaticJointDef * );
	};

	void initPrismaticJointDef(State * );
};

#endif	
