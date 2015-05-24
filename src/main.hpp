namespace LuaBox2D {
	int version(State & state);

	//function declarations to speed up building process
	void initTimer(State *);

	void initVec2(State *);
	void initRot(State *);
	void initTransform(State *);
	void initSweep(State *);

	void initWorld(State *);
	void initBody(State *);
	void initBodyDef(State *);
	void initJoint(State *);
	void initJointDef(State *);
	void initFixture(State *);
	void initFixtureDef(State *);

	void initShape(State *);
	void initCircleShape(State *);
	void initChainShape(State *);
	void initEdgeShape(State *);
	void initPolygonShape(State *);

	void initFilter(State *);
	void initRayCastInput(State *);
	void initRayCastOutput(State *);
	void initAABB(State *);
	void initMassData(State *);
	void initVertexArray(State *);
	void initContact(State *);
	void initManifold(State *);
	void initManifoldPoint(State *);
	void initContactID(State *);
	void initContactFeature(State *);
	void initWorldManifold(State *);
	void initContactListener(State *);
	void initContactImpulse(State *);
	void initContactManager(State *);
	void initContactFilter(State *);

	void initQueryCallback(State *);
	void initRayCastCallback(State *);

	void initJointEdge(State *);
	void initContactEdge(State *);

	void initRevoluteJoint(State *);
	void initPrismaticJoint(State *);
	void initDistanceJoint(State *);
	void initPulleyJoint(State *);
	void initMouseJoint(State *);
	void initGearJoint(State *);
	void initWheelJoint(State *);
	void initWeldJoint(State *);
	void initFrictionJoint(State *);
	void initRopeJoint(State *);
	void initMotorJoint(State *);

	void initRevoluteJointDef(State *);
	void initPrismaticJointDef(State *);
	void initDistanceJointDef(State *);
	void initPulleyJointDef(State *);
	void initMouseJointDef(State *);
	void initGearJointDef(State *);
	void initWheelJointDef(State *);
	void initWeldJointDef(State *);
	void initFrictionJointDef(State *);
	void initRopeJointDef(State *);
	void initMotorJointDef(State *);
}

extern "C" LIBLUABOX2D_DLL_EXPORTED int luaopen_LuaBox2D(lua_State * L);
