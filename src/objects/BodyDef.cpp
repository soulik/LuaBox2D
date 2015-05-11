#include "common.hpp"
#include "objects/Vec2.hpp"
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

	b2BodyDef * BodyDef::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		b2BodyDef * obj = nullptr;
		obj = new b2BodyDef();

		return obj;
	}

	void BodyDef::destructor(State & state, b2BodyDef * object){
		delete object;
	}

	int BodyDef::getBodyType(State & state, b2BodyDef * object){
		state.stack->push<const std::string &>(bodyTypeToString(object->type));
		return 1;
	}

	int BodyDef::setBodyType(State & state, b2BodyDef * object){
		if (state.stack->is<LUA_TSTRING>(1)){
			const std::string key = state.stack->to<const std::string>(1);
			object->type = stringToBodyType(key);
		}
		return 0;
	}

	int BodyDef::getPosition(State & state, b2BodyDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->position, false);
		return 1;
	}

	int BodyDef::setPosition(State & state, b2BodyDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * position = interfaceVec2->get(1);
		if (position != nullptr){
			object->position = (*position);
		}
		return 0;
	}

	int BodyDef::getAngle(State & state, b2BodyDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->angle));
		return 1;
	}

	int BodyDef::setAngle(State & state, b2BodyDef * object){
		object->angle = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int BodyDef::getLinearVelocity(State & state, b2BodyDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->linearVelocity, false);
		return 1;
	}

	int BodyDef::setLinearVelocity(State & state, b2BodyDef * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * position = interfaceVec2->get(1);
		if (position != nullptr){
			object->linearVelocity = (*position);
		}
		return 0;
	}

	int BodyDef::getAngularVelocity(State & state, b2BodyDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->angularVelocity));
		return 1;
	}

	int BodyDef::setAngularVelocity(State & state, b2BodyDef * object){
		object->angularVelocity = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int BodyDef::getLinearDamping(State & state, b2BodyDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->linearDamping));
		return 1;
	}

	int BodyDef::setLinearDamping(State & state, b2BodyDef * object){
		object->linearDamping = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int BodyDef::getAngularDamping(State & state, b2BodyDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->angularDamping));
		return 1;
	}

	int BodyDef::setAngularDamping(State & state, b2BodyDef * object){
		object->angularDamping = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int BodyDef::getAllowSleep(State & state, b2BodyDef * object){
		state.stack->push<bool>(object->allowSleep);
		return 1;
	}

	int BodyDef::setAllowSleep(State & state, b2BodyDef * object){
		object->allowSleep = state.stack->to<bool>(1);
		return 0;
	}

	int BodyDef::getAwake(State & state, b2BodyDef * object){
		state.stack->push<bool>(object->awake);
		return 1;
	}

	int BodyDef::setAwake(State & state, b2BodyDef * object){
		object->awake = state.stack->to<bool>(1);
		return 0;
	}

	int BodyDef::getFixedRotation(State & state, b2BodyDef * object){
		state.stack->push<bool>(object->fixedRotation);
		return 1;
	}

	int BodyDef::setFixedRotation(State & state, b2BodyDef * object){
		object->fixedRotation = state.stack->to<bool>(1);
		return 0;
	}

	int BodyDef::getBullet(State & state, b2BodyDef * object){
		state.stack->push<bool>(object->bullet);
		return 1;
	}

	int BodyDef::setBullet(State & state, b2BodyDef * object){
		object->bullet = state.stack->to<bool>(1);
		return 0;
	}

	int BodyDef::getActive(State & state, b2BodyDef * object){
		state.stack->push<bool>(object->bullet);
		return 1;
	}

	int BodyDef::setActive(State & state, b2BodyDef * object){
		object->bullet = state.stack->to<bool>(1);
		return 0;
	}

	int BodyDef::getGravityScale(State & state, b2BodyDef * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->gravityScale));
		return 1;
	}

	int BodyDef::setGravityScale(State & state, b2BodyDef * object){
		object->gravityScale = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int BodyDef::getUserData(State & state, b2BodyDef * object){
		int ref = static_cast<int>(reinterpret_cast<intptr_t>(object->userData));
		if (ref != LUA_NOREF && ref != 0){
			state.stack->regValue(ref);
			return 1;
		}else{
			return 0;
		}
	}

	int BodyDef::setUserData(State & state, b2BodyDef * object){
		int oldRef = static_cast<int>(reinterpret_cast<intptr_t>(object->userData));
		if (oldRef != LUA_NOREF && oldRef != 0){
			state.stack->unref(oldRef);
		}
		if (!state.stack->is<LUA_TNIL>(1)){
			state.stack->pushValue(1);
			int ref = state.stack->ref();

			object->userData = reinterpret_cast<void*>(ref);
		}
		return 0;
	}
};
