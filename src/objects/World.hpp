#ifndef LUABOX2D_WORLD_H
#define LUABOX2D_WORLD_H

namespace LuaBox2D {
	class World : public Object<b2World> {
	public:
		explicit World(State * state) : Object<b2World>(state){
			LUTOK_PROPERTY("allowSleeping", &World::getAllowSleeping, &World::setAllowSleeping);
			LUTOK_PROPERTY("warmStarting", &World::getWarmStarting, &World::setWarmStarting);
			LUTOK_PROPERTY("continuousPhysics", &World::getContinuousPhysics, &World::setContinuousPhysics);
			LUTOK_PROPERTY("subStepping", &World::getSubStepping, &World::setSubStepping);

			LUTOK_PROPERTY("gravity", &World::getGravity, &World::setGravity);
			LUTOK_PROPERTY("locked", &World::getLocked, &World::nullMethod);
			LUTOK_PROPERTY("autoClearForces", &World::getAutoClearForces, &World::setAutoClearForces);

			LUTOK_PROPERTY("proxyCount", &World::getProxyCount, &World::nullMethod);
			LUTOK_PROPERTY("bodyCount", &World::getBodyCount, &World::nullMethod);
			LUTOK_PROPERTY("jointCount", &World::getJointCount, &World::nullMethod);
			LUTOK_PROPERTY("contactCount", &World::getContactCount, &World::nullMethod);
			LUTOK_PROPERTY("treeHeight", &World::getTreeHeight, &World::nullMethod);
			LUTOK_PROPERTY("treeBalance", &World::getTreeBalance, &World::nullMethod);
			LUTOK_PROPERTY("treeQuality", &World::getTreeQuality, &World::nullMethod);

			LUTOK_METHOD("step", &World::step);
			LUTOK_METHOD("clearForces", &World::clearForces);
			LUTOK_METHOD("shiftToOritin", &World::shiftToOritin);

			LUTOK_METHOD("createBody", &World::createBody);
			LUTOK_METHOD("createJoint", &World::createJoint);

			LUTOK_PROPERTY("body", &World::getBody, &World::nullMethod);
			LUTOK_PROPERTY("joint", &World::getJoint, &World::nullMethod);
			LUTOK_PROPERTY("contact", &World::getContact, &World::nullMethod);

			LUTOK_PROPERTY("contactListener", &World::getContactListener, &World::setContactListener);
			LUTOK_PROPERTY("contactFilter", &World::getContactFilter, &World::setContactFilter);
			LUTOK_PROPERTY("contactManager", &World::getContactManager, &World::nullMethod);

			LUTOK_METHOD("queryAABB", &World::queryAABB);
			LUTOK_METHOD("rayCast", &World::rayCast);
		}

		b2World * constructor(State & state, bool & managed);

		void destructor(State & state, b2World * object);

		int createBody(State & state, b2World * object);

		int createJoint(State & state, b2World * object);

		int getBody(State & state, b2World * object);

		int getJoint(State & state, b2World * object);

		int getContact(State & state, b2World * object);

		int step(State & state, b2World * object);

		int clearForces(State & state, b2World * object);

		int getAllowSleeping(State & state, b2World * object);

		int setAllowSleeping(State & state, b2World * object);

		int getWarmStarting(State & state, b2World * object);

		int setWarmStarting(State & state, b2World * object);

		int getContinuousPhysics(State & state, b2World * object);

		int setContinuousPhysics(State & state, b2World * object);

		int getSubStepping(State & state, b2World * object);

		int setSubStepping(State & state, b2World * object);

		int getGravity(State & state, b2World * object);

		int setGravity(State & state, b2World * object);

		int getLocked(State & state, b2World * object);

		int getAutoClearForces(State & state, b2World * object);

		int setAutoClearForces(State & state, b2World * object);

		int shiftToOritin(State & state, b2World * object);

		int getProxyCount(State & state, b2World * object);

		int getBodyCount(State & state, b2World * object);
		
		int getJointCount(State & state, b2World * object);

		int getContactCount(State & state, b2World * object);

		int getTreeHeight(State & state, b2World * object);

		int getTreeBalance(State & state, b2World * object);

		int getTreeQuality(State & state, b2World * object);

		int getContactListener(State & state, b2World * object);

		int setContactListener(State & state, b2World * object);

		int getContactFilter(State & state, b2World * object);

		int setContactFilter(State & state, b2World * object);

		int getContactManager(State & state, b2World * object);

		int queryAABB(State & state, b2World * object);

		int rayCast(State & state, b2World * object);
	};

	void initWorld(State *);
};

#endif