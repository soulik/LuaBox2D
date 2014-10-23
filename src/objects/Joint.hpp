#ifndef LUABOX2D_JOINT_H
#define LUABOX2D_JOINT_H

namespace LuaBox2D {
	class Joint : public Object<b2Joint> {
	public:
		explicit Joint(State * state) : Object<b2Joint>(state){
		}

		b2Joint * constructor(State & state){
			return nullptr;
		}

		void destructor(State & state, b2Joint * object){
			object->GetBodyA()->GetWorld()->DestroyJoint(object);
		}
	};

	void initJoint(State * );
};

#endif	
