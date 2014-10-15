#ifndef LUABOX2D_BODYDEF_H
#define LUABOX2D_BODYDEF_H

#include "objects/Vec2.hpp"

namespace LuaBox2D {
	b2BodyType stringToBodyType(const std::string &);
	std::string bodyTypeToString(const b2BodyType);

	class BodyDef : public Object<b2BodyDef> {
	public:
		explicit BodyDef(State * state) : Object<b2BodyDef>(state){
			LUTOK_PROPERTY("bodyType", &BodyDef::getBodyType, &BodyDef::setBodyType);
			LUTOK_PROPERTY("position", &BodyDef::getPosition, &BodyDef::setPosition);
			LUTOK_PROPERTY("angle", &BodyDef::getAngle, &BodyDef::setAngle);
			LUTOK_PROPERTY("linearVelocity", &BodyDef::getLinearVelocity, &BodyDef::setLinearVelocity);
			LUTOK_PROPERTY("angularVelocity", &BodyDef::getAngularVelocity, &BodyDef::setAngularVelocity);
			LUTOK_PROPERTY("linearDamping", &BodyDef::getLinearDamping, &BodyDef::setLinearDamping);
			LUTOK_PROPERTY("angularDamping", &BodyDef::getAngularDamping, &BodyDef::setAngularDamping);

			LUTOK_PROPERTY("allowSleep", &BodyDef::getAllowSleep, &BodyDef::setAllowSleep);
			LUTOK_PROPERTY("awake", &BodyDef::getAwake, &BodyDef::setAwake);
			LUTOK_PROPERTY("fixedRotation", &BodyDef::getFixedRotation, &BodyDef::setFixedRotation);
			LUTOK_PROPERTY("bullet", &BodyDef::getBullet, &BodyDef::setBullet);
			LUTOK_PROPERTY("active", &BodyDef::getActive, &BodyDef::setActive);

			LUTOK_PROPERTY("gravityScale", &BodyDef::getGravityScale, &BodyDef::setGravityScale);

			//LUTOK_METHOD("step", &World::step);
		}
		b2BodyDef * constructor(State & state){
			b2BodyDef * obj = nullptr;
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);

			obj = new b2BodyDef();

			return obj;
		}
		void destructor(State & state, b2BodyDef * object){
			delete object;
		}

		int getBodyType(State & state, b2BodyDef * object){
			state.stack->push(bodyTypeToString(object->type));
			return 1;
		}

		int setBodyType(State & state, b2BodyDef * object){
			if (state.stack->is<LUA_TSTRING>(1)){
				object->type = stringToBodyType(state.stack->to<std::string>(1));
			}
			return 0;
		}

		int getPosition(State & state, b2BodyDef * object){
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			interfaceVec2->push(&object->position, false);
			return 1;
		}

		int setPosition(State & state, b2BodyDef * object){
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			b2Vec2 * position = interfaceVec2->get(1);
			if (position != nullptr){
				object->position = (*position);
			}
			return 0;
		}

		int getAngle(State & state, b2BodyDef * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->angle));
			return 1;
		}

		int setAngle(State & state, b2BodyDef * object){
			object->angle = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
			return 0;
		}

		int getLinearVelocity(State & state, b2BodyDef * object){
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			interfaceVec2->push(&object->linearVelocity, false);
			return 1;
		}

		int setLinearVelocity(State & state, b2BodyDef * object){
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			b2Vec2 * position = interfaceVec2->get(1);
			if (position != nullptr){
				object->linearVelocity = (*position);
			}
			return 0;
		}

		int getAngularVelocity(State & state, b2BodyDef * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->angularVelocity));
			return 1;
		}

		int setAngularVelocity(State & state, b2BodyDef * object){
			object->angularVelocity = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
			return 0;
		}

		int getLinearDamping(State & state, b2BodyDef * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->linearDamping));
			return 1;
		}

		int setLinearDamping(State & state, b2BodyDef * object){
			object->linearDamping = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
			return 0;
		}

		int getAngularDamping(State & state, b2BodyDef * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->angularDamping));
			return 1;
		}

		int setAngularDamping(State & state, b2BodyDef * object){
			object->angularDamping = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
			return 0;
		}

		int getAllowSleep(State & state, b2BodyDef * object){
			state.stack->push<bool>(object->allowSleep);
			return 1;
		}

		int setAllowSleep(State & state, b2BodyDef * object){
			object->allowSleep = state.stack->to<bool>(1);
			return 0;
		}

		int getAwake(State & state, b2BodyDef * object){
			state.stack->push<bool>(object->awake);
			return 1;
		}

		int setAwake(State & state, b2BodyDef * object){
			object->awake = state.stack->to<bool>(1);
			return 0;
		}

		int getFixedRotation(State & state, b2BodyDef * object){
			state.stack->push<bool>(object->fixedRotation);
			return 1;
		}

		int setFixedRotation(State & state, b2BodyDef * object){
			object->fixedRotation = state.stack->to<bool>(1);
			return 0;
		}

		int getBullet(State & state, b2BodyDef * object){
			state.stack->push<bool>(object->bullet);
			return 1;
		}

		int setBullet(State & state, b2BodyDef * object){
			object->bullet = state.stack->to<bool>(1);
			return 0;
		}

		int getActive(State & state, b2BodyDef * object){
			state.stack->push<bool>(object->bullet);
			return 1;
		}

		int setActive(State & state, b2BodyDef * object){
			object->bullet = state.stack->to<bool>(1);
			return 0;
		}

		int getGravityScale(State & state, b2BodyDef * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->gravityScale));
			return 1;
		}

		int setGravityScale(State & state, b2BodyDef * object){
			object->gravityScale = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
			return 0;
		}
	};

	void initBodyDef(State *);
};

#endif
