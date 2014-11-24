local ac = require 'addClass'
local putFile = ac.putFile

local templates = {
-- JOINT TEMPLATE
	hpp =
[[#ifndef LUABOX2D_{{CNAME}}_H
#define LUABOX2D_{{CNAME}}_H

namespace LuaBox2D {
	class {{CLASS}} : public Object<{{ORIG_CLASS}}> {
	private:
		Joint * base;
	public:
		explicit {{CLASS}}(State * state) : Object<{{ORIG_CLASS}}>(state){
			base = state->getInterface<Joint>("LuaBox2D_Joint");
			LUTOK_PROPERTY("type", &{{CLASS}}::getType, &{{CLASS}}::nullMethod);
			LUTOK_PROPERTY("bodyA", &{{CLASS}}::getBodyA, &{{CLASS}}::nullMethod);
			LUTOK_PROPERTY("bodyB", &{{CLASS}}::getBodyB, &{{CLASS}}::nullMethod);

			LUTOK_PROPERTY("anchorA", &{{CLASS}}::getAnchorA, &{{CLASS}}::nullMethod);
			LUTOK_PROPERTY("anchorB", &{{CLASS}}::getAnchorB, &{{CLASS}}::nullMethod);

			LUTOK_METHOD("reactionForce", &{{CLASS}}::getReactionForce);
			LUTOK_METHOD("reactionTorque", &{{CLASS}}::getReactionTorque);

			LUTOK_PROPERTY("active", &{{CLASS}}::getActive, &{{CLASS}}::nullMethod);
			LUTOK_PROPERTY("collideConnected", &{{CLASS}}::getCollideConnected, &{{CLASS}}::nullMethod);
		}

		{{ORIG_CLASS}} * constructor(State & state, bool & managed);

		void destructor(State & state, {{ORIG_CLASS}} * object);

		int getType(State & state, {{ORIG_CLASS}} * );

		int getBodyA(State & state, {{ORIG_CLASS}} *);

		int getBodyB(State & state, {{ORIG_CLASS}} *);

		int getAnchorA(State & state, {{ORIG_CLASS}} *);

		int getAnchorB(State & state, {{ORIG_CLASS}} *);

		int getReactionForce(State & state, {{ORIG_CLASS}} *);

		int getReactionTorque(State & state, {{ORIG_CLASS}} *);

		int getActive(State & state, {{ORIG_CLASS}} * );

		int getCollideConnected(State & state, {{ORIG_CLASS}} * );
	};

	void init{{CLASS}}(State * );
};

#endif	
]],
	cpp =
[[#include "common.hpp"
#include "objects/Joint.hpp"
#include "objects/{{CLASS}}.hpp"

namespace LuaBox2D {
	void init{{CLASS}}(State * state){
		state->registerInterface<{{CLASS}}>("LuaBox2D_{{CLASS}}");
	}

	{{ORIG_CLASS}} * {{CLASS}}::constructor(State & state, bool & managed){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		b2Joint * joint = interfaceJoint->get(1);
		if (joint != nullptr){
			if (joint->GetType() == b2JointType::e_revoluteJoint){
				managed = false;
				return dynamic_cast<{{ORIG_CLASS}}*>(joint);
			}else{
				return nullptr;
			}
		}else{
			return nullptr;
		}
	}

	void {{CLASS}}::destructor(State & state, {{ORIG_CLASS}} * object){
		delete object;
	}

	inline int {{CLASS}}::getType(State & state, {{ORIG_CLASS}} * object){
		return base->getType(state, object);
	}

	inline int {{CLASS}}::getBodyA(State & state, {{ORIG_CLASS}} * object){
		return base->getBodyA(state, object);
	}

	inline int {{CLASS}}::getBodyB(State & state, {{ORIG_CLASS}} * object){
		return base->getBodyB(state, object);
	}

	inline int {{CLASS}}::getAnchorA(State & state, {{ORIG_CLASS}} * object){
		return base->getAnchorA(state, object);
	}

	inline int {{CLASS}}::getAnchorB(State & state, {{ORIG_CLASS}} * object){
		return base->getAnchorB(state, object);
	}

	inline int {{CLASS}}::getReactionForce(State & state, {{ORIG_CLASS}} * object){
		return base->getReactionForce(state, object);
	}

	inline int {{CLASS}}::getReactionTorque(State & state, {{ORIG_CLASS}} * object){
		return base->getReactionTorque(state, object);
	}

	inline int {{CLASS}}::getActive(State & state, {{ORIG_CLASS}} * object){
		return base->getActive(state, object);
	}

	inline int {{CLASS}}::getCollideConnected(State & state, {{ORIG_CLASS}} * object){
		return base->getCollideConnected(state, object);
	}
};
]],
-- JOINTDEF TEMPLATE
	hppDef =
[[#ifndef LUABOX2D_{{CNAME}}_H
#define LUABOX2D_{{CNAME}}_H

namespace LuaBox2D {
	class {{CLASS}} : public Object<{{ORIG_CLASS}}> {
	private:
		JointDef * base;
	public:
		explicit {{CLASS}}(State * state) : Object<{{ORIG_CLASS}}>(state){
			base = state->getInterface<JointDef>("LuaBox2D_JointDef");
			LUTOK_PROPERTY("type", &{{CLASS}}::getType, &{{CLASS}}::setType);
			LUTOK_PROPERTY("bodyA", &{{CLASS}}::getBodyA, &{{CLASS}}::setBodyA);
			LUTOK_PROPERTY("bodyB", &{{CLASS}}::getBodyB, &{{CLASS}}::setBodyB);
			LUTOK_PROPERTY("collideConnected", &{{CLASS}}::getCollideConnected, &{{CLASS}}::setCollideConnected);
		}

		{{ORIG_CLASS}} * constructor(State & state);

		void destructor(State & state, {{ORIG_CLASS}} * object);

		int getBodyA(State & state, {{ORIG_CLASS}} * );

		int setBodyA(State & state, {{ORIG_CLASS}} * );

		int getBodyB(State & state, {{ORIG_CLASS}} * );

		int setBodyB(State & state, {{ORIG_CLASS}} * );

		int getType(State & state, {{ORIG_CLASS}} * );

		int setType(State & state, {{ORIG_CLASS}} * );

		int getCollideConnected(State & state, {{ORIG_CLASS}} * );

		int setCollideConnected(State & state, {{ORIG_CLASS}} * );
	};

	void init{{CLASS}}(State * );
};

#endif	
]],
	cppDef =
[[#include "common.hpp"
#include "objects/JointDef.hpp"
#include "objects/{{CLASS}}.hpp"

namespace LuaBox2D {
	void init{{CLASS}}(State * state){
		state->registerInterface<{{CLASS}}>("LuaBox2D_{{CLASS}}");
	}

	{{ORIG_CLASS}} * {{CLASS}}::constructor(State & state){
		JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
		b2JointDef * jointDef = interfaceJointDef->get(1);
		if (jointDef != nullptr){
			if (jointDef->type == b2JointType::e_revoluteJoint){
				return new {{ORIG_CLASS}}(*({{ORIG_CLASS}}*)(jointDef));
			}else{
				return new {{ORIG_CLASS}}();
			}
		}else{
			return new {{ORIG_CLASS}}();
		}
	}

	void {{CLASS}}::destructor(State & state, {{ORIG_CLASS}} * object){
		delete object;
	}

	inline int {{CLASS}}::getBodyA(State & state, {{ORIG_CLASS}} * object){
		return base->getBodyA(state, object);
	}

	inline int {{CLASS}}::setBodyA(State & state, {{ORIG_CLASS}} * object){
		return base->setBodyA(state, object);
	}

	inline int {{CLASS}}::getBodyB(State & state, {{ORIG_CLASS}} * object){
		return base->getBodyB(state, object);
	}

	inline int {{CLASS}}::setBodyB(State & state, {{ORIG_CLASS}} * object){
		return base->setBodyB(state, object);
	}

	inline int {{CLASS}}::getType(State & state, {{ORIG_CLASS}} * object){
		return base->getType(state, object);
	}

	inline int {{CLASS}}::setType(State & state, {{ORIG_CLASS}} * object){
		return base->setType(state, object);
	}

	inline int {{CLASS}}::getCollideConnected(State & state, {{ORIG_CLASS}} * object){
		return base->getCollideConnected(state, object);
	}

	inline int {{CLASS}}::setCollideConnected(State & state, {{ORIG_CLASS}} * object){
		return base->setCollideConnected(state, object);
	}
};
]]

}

local genJointFile = function(name, orig_class_name)
	putFile(name, orig_class_name, templates.hpp, ('src/objects/%s.hpp'):format(name))
	putFile(name, orig_class_name, templates.cpp, ('src/objects/%s.cpp'):format(name))
end

local genJointDefFile = function(name, orig_class_name)
	putFile(name, orig_class_name, templates.hppDef, ('src/objects/%s.hpp'):format(name))
	putFile(name, orig_class_name, templates.cppDef, ('src/objects/%s.cpp'):format(name))
end

local function genJoint(name)
	local jointName = ('%sJoint'):format(name)
	local jointDefName = ('%sJointDef'):format(name)

	genJointFile(jointName, 'b2'..jointName)
	genJointDefFile(jointDefName, 'b2'..jointDefName)
end

if #arg >= 1 then
	genJoint(arg[1])
else
	return {
		genJoint = genJoint,
	}
end
