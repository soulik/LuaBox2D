#include "common.hpp"
#include "objects/Body.hpp"
#include "objects/Joint.hpp"
#include "objects/JointEdge.hpp"

namespace LuaBox2D {
	void initJointEdge(State * state){
		state->registerInterface<JointEdge>("LuaBox2D_JointEdge");
	}

	b2JointEdge * JointEdge::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		b2JointEdge * object = new b2JointEdge();
		
		object->joint = nullptr;
		object->other = nullptr;
		object->next = nullptr;
		object->prev = nullptr;

		return object;
	}

	void JointEdge::destructor(State & state, b2JointEdge * object){
		delete object;
	}

	int JointEdge::getOther(State & state, b2JointEdge * object){
		Body * interfaceBody = state.getInterface<Body>("LuaBox2D_Body");
		if (object->other){
			interfaceBody->push(object->other, false);
			return 1;
		}else{
			return 0;
		}
	}

	int JointEdge::getJoint(State & state, b2JointEdge * object){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		if (object->joint){
			interfaceJoint->push(object->joint, false);
			return 1;
		}else{
			return 0;
		}
	}

	int JointEdge::getPrev(State & state, b2JointEdge * object){
		JointEdge * interfaceJointEdge = state.getInterface<JointEdge>("LuaBox2D_JointEdge");
		if (object->prev){
			interfaceJointEdge->push(object->prev, false);
			return 1;
		}else{
			return 0;
		}
	}

	int JointEdge::getNext(State & state, b2JointEdge * object){
		JointEdge * interfaceJointEdge = state.getInterface<JointEdge>("LuaBox2D_JointEdge");
		if (object->next){
			interfaceJointEdge->push(object->next, false);
			return 1;
		}else{
			return 0;
		}
	}
};
