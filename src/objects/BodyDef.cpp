#include "common.hpp"
#include "objects/BodyDef.hpp"
#include <map>

namespace LuaBox2D {
	typedef std::map<std::string, b2BodyType> bodyTypeMap;
	bodyTypeMap bodyTypes;

	void initBodyDef(State * state){
		bodyTypes["static"] = b2_staticBody;
		bodyTypes["kinematic"] = b2_kinematicBody;
		bodyTypes["dynamic"] = b2_dynamicBody;

		state->registerInterface<BodyDef>("LuaBox2D_BodyDef");
	}

	b2BodyType stringToBodyType(const std::string & name){
		bodyTypeMap::iterator iter = bodyTypes.find(name);
		if (iter != bodyTypes.end()){
			return iter->second;
		}else{
			return b2_staticBody;
		}
	}

	std::string bodyTypeToString(const b2BodyType bodyType){
		for (bodyTypeMap::iterator iter = bodyTypes.begin(); iter != bodyTypes.end(); iter++){
			if (iter->second == bodyType){
				return iter->first;
			}
		}
		return "Unknown";
	}
};
