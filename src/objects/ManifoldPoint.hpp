#ifndef LUABOX2D_MANIFOLDPOINT_H
#define LUABOX2D_MANIFOLDPOINT_H

namespace LuaBox2D {
	class ManifoldPoint : public Object<b2ManifoldPoint> {
	public:
		explicit ManifoldPoint(State * state) : Object<b2ManifoldPoint>(state){
			LUTOK_PROPERTY("localPoint", &ManifoldPoint::getLocalPoint, &ManifoldPoint::setLocalPoint);
			LUTOK_PROPERTY("normalImpulse", &ManifoldPoint::getNormalImpulse, &ManifoldPoint::setNormalImpulse);
			LUTOK_PROPERTY("tangentImpulse", &ManifoldPoint::getTangentImpulse, &ManifoldPoint::setTangentImpulse);
			LUTOK_PROPERTY("contactID", &ManifoldPoint::getContactID, &ManifoldPoint::setContactID);
		}

		b2ManifoldPoint * constructor(State & state, bool & managed);

		void destructor(State & state, b2ManifoldPoint * object);

		int getLocalPoint(State & state, b2ManifoldPoint * object);

		int setLocalPoint(State & state, b2ManifoldPoint * object);

		int getNormalImpulse(State & state, b2ManifoldPoint * object);

		int setNormalImpulse(State & state, b2ManifoldPoint * object);

		int getTangentImpulse(State & state, b2ManifoldPoint * object);

		int setTangentImpulse(State & state, b2ManifoldPoint * object);

		int getContactID(State & state, b2ManifoldPoint * object);

		int setContactID(State & state, b2ManifoldPoint * object);
	};

	void initManifoldPoint(State * );
};

#endif	
