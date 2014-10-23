#ifndef LUABOX2D_JOINTDEF_H
#define LUABOX2D_JOINTDEF_H

namespace LuaBox2D {
	class JointDef : public Object<b2JointDef> {
	public:
		explicit JointDef(State * state) : Object<b2JointDef>(state){
		}

		b2JointDef * constructor(State & state){
			return nullptr;
		}

		void destructor(State & state, b2JointDef * object){
			delete object;
		}
	};

	void initJointDef(State * );
};

#endif	
