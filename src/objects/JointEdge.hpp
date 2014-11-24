#ifndef LUABOX2D_JOINTEDGE_H
#define LUABOX2D_JOINTEDGE_H

namespace LuaBox2D {
	class JointEdge : public Object<b2JointEdge> {
	public:
		explicit JointEdge(State * state) : Object<b2JointEdge>(state){
			LUTOK_PROPERTY("other", &JointEdge::getOther, &JointEdge::nullMethod);
			LUTOK_PROPERTY("joint", &JointEdge::getJoint, &JointEdge::nullMethod);
			LUTOK_PROPERTY("prev", &JointEdge::getPrev, &JointEdge::nullMethod);
			LUTOK_PROPERTY("next", &JointEdge::getNext, &JointEdge::nullMethod);
		}

		b2JointEdge * constructor(State & state, bool & managed);

		void destructor(State & state, b2JointEdge * object);

		int getOther(State & state, b2JointEdge * object);
		int getJoint(State & state, b2JointEdge * object);
		int getPrev(State & state, b2JointEdge * object);
		int getNext(State & state, b2JointEdge * object);

	};

	void initJointEdge(State * );
};

#endif	
