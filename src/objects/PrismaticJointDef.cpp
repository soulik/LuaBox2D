#include "common.hpp"
#include "objects/PrismaticJointDef.hpp"

namespace LuaBox2D {
	void initPrismaticJointDef(State * state){
		state->registerInterface<PrismaticJointDef>("LuaBox2D_PrismaticJointDef");
	}

	inline int PrismaticJointDef::getBodyA(State & state, b2PrismaticJointDef * object){
		return base->getBodyA(state, object);
	}

	inline int PrismaticJointDef::setBodyA(State & state, b2PrismaticJointDef * object){
		return base->setBodyA(state, object);
	}

	inline int PrismaticJointDef::getBodyB(State & state, b2PrismaticJointDef * object){
		return base->getBodyB(state, object);
	}

	inline int PrismaticJointDef::setBodyB(State & state, b2PrismaticJointDef * object){
		return base->setBodyB(state, object);
	}

	inline int PrismaticJointDef::getType(State & state, b2PrismaticJointDef * object){
		return base->getType(state, object);
	}

	inline int PrismaticJointDef::setType(State & state, b2PrismaticJointDef * object){
		return base->setType(state, object);
	}

	inline int PrismaticJointDef::getCollideConnected(State & state, b2PrismaticJointDef * object){
		return base->getCollideConnected(state, object);
	}

	inline int PrismaticJointDef::setCollideConnected(State & state, b2PrismaticJointDef * object){
		return base->setCollideConnected(state, object);
	}
};
