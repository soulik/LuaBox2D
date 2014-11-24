local templates = {
	hpp =
[[#ifndef LUABOX2D_{{CNAME}}_H
#define LUABOX2D_{{CNAME}}_H

namespace LuaBox2D {
	class {{CLASS}} : public Object<{{ORIG_CLASS}}> {
	public:
		explicit {{CLASS}}(State * state) : Object<{{ORIG_CLASS}}>(state){
		}

		{{ORIG_CLASS}} * constructor(State & state, bool & managed);

		void destructor(State & state, {{ORIG_CLASS}} * object);
	};

	void init{{CLASS}}(State * );
};

#endif	
]],
	cpp =
[[#include "common.hpp"
#include "objects/{{CLASS}}.hpp"

namespace LuaBox2D {
	void init{{CLASS}}(State * state){
		state->registerInterface<{{CLASS}}>("LuaBox2D_{{CLASS}}");
	}

	{{ORIG_CLASS}} * {{CLASS}}::constructor(State & state, bool & managed){
		return nullptr;
	}

	void {{CLASS}}::destructor(State & state, {{ORIG_CLASS}} * object){
		delete object;
	}
};
]]
}

local function putFile(name, className, template, path)
	local f = io.open(path, "w")
	if f then
		f:write((template:gsub("{{([^{}]+)}}", {
			CNAME = name:upper(),
			CLASS = name,
			ORIG_CLASS = className,
		})))
		f:close()
		return true
	else
		return false
	end
end

local genClassFile = function(name, orig_class_name)
	putFile(name, orig_class_name, templates.hpp, ('src/objects/%s.hpp'):format(name))
	putFile(name, orig_class_name, templates.cpp, ('src/objects/%s.cpp'):format(name))
end

if #arg>1 then
	genClassFile(tostring(arg[1]), tostring(arg[2]))
else
--	print(("lua %s <name> <orig_class_name>"):format(arg[0]))
	return {
		genclassFile = genClassFile,
		putFile = putFile,
	}
end