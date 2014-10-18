#ifndef LUABOX2D_BODY_H
#define LUABOX2D_BODY_H

#include "objects/Shape.hpp"
#include "objects/BodyDef.hpp"
#include "objects/Fixture.hpp"
#include "objects/FixtureDef.hpp"
#include "objects/World.hpp"
#include "objects/Transform.hpp"
#include "objects/Vec2.hpp"

namespace LuaBox2D {
	class Body : public Object<b2Body> {
	public:
		explicit Body(State * state) : Object<b2Body>(state){
			LUTOK_PROPERTY("position", &Body::getPosition, &Body::nullMethod);
			LUTOK_PROPERTY("angle", &Body::getAngle, &Body::nullMethod);
			LUTOK_PROPERTY("worldCenter", &Body::getWorldCenter, &Body::nullMethod);
			LUTOK_PROPERTY("localCenter", &Body::getLocalCenter, &Body::nullMethod);

			LUTOK_PROPERTY("linearVelocity", &Body::getLinearVelocity, &Body::setLinearVelocity);
			LUTOK_PROPERTY("angularVelocity", &Body::getAngularVelocity, &Body::setAngularVelocity);

			LUTOK_METHOD("getTransform", &Body::getTransform);
			LUTOK_METHOD("setTransform", &Body::setTransform);

			LUTOK_METHOD("applyForce", &Body::applyForce);
			LUTOK_METHOD("applyForceToCenter", &Body::applyForceToCenter);
			LUTOK_METHOD("applyLinearImpulse", &Body::applyLinearImpulse);
			LUTOK_METHOD("applyAngularImpulse", &Body::applyAngularImpulse);

			LUTOK_PROPERTY("mass", &Body::getMass, &Body::nullMethod);
			LUTOK_PROPERTY("inertia", &Body::getInertia, &Body::nullMethod);
			LUTOK_PROPERTY("massData", &Body::getMassData, &Body::setMassData);
			
			LUTOK_METHOD("localPoint", &Body::getLocalPoint);
			LUTOK_METHOD("localVector", &Body::getLocalVector);
			LUTOK_METHOD("worldPoint", &Body::getWorldPoint);
			LUTOK_METHOD("WorldVector", &Body::getWorldVector);
			LUTOK_METHOD("linearVelocityFromWorldPoint", &Body::getLinearVelocityFromWorldPoint);
			LUTOK_METHOD("linearVelocityFromLocalPoint", &Body::getLinearVelocityFromLocalPoint);

			LUTOK_PROPERTY("linearDamping", &Body::getLinearDamping, &Body::setLinearDamping);
			LUTOK_PROPERTY("angularDamping", &Body::getAngularDamping, &Body::setAngularDamping);
			LUTOK_PROPERTY("gravityScale", &Body::getGravityScale, &Body::setGravityScale);
			LUTOK_PROPERTY("type", &Body::getType, &Body::setType);
			LUTOK_PROPERTY("bullet", &Body::getBullet, &Body::setBullet);
			LUTOK_PROPERTY("allowSleeping", &Body::getSleepingAllowed, &Body::setSleepingAllowed);
			LUTOK_PROPERTY("awake", &Body::getAwake, &Body::setAwake);
			LUTOK_PROPERTY("active", &Body::getActive, &Body::setActive);
			LUTOK_PROPERTY("fixedRotation", &Body::getFixedRotation, &Body::setFixedRotation);

			LUTOK_PROPERTY("world", &Body::getWorld, &Body::nullMethod);
			LUTOK_METHOD("createFixture", &Body::createFixture);
		}
		b2Body * constructor(State & state){
			b2Body * obj = nullptr;
			Stack * stack = state.stack;
			
			BodyDef * interfaceBodyDef = dynamic_cast<BodyDef*>(state.interfaces["LuaBox2D_BodyDef"]);
			World * interfaceWorld = dynamic_cast<World*>(state.interfaces["LuaBox2D_World"]);

			b2BodyDef * bodyDef = interfaceBodyDef->get(1);
			b2World * world = interfaceWorld->get(2);

			if (bodyDef != nullptr && world != nullptr){
				obj = world->CreateBody(bodyDef);
			}

			return obj;
		}
		void destructor(State & state, b2Body * object){
			b2World * world = object->GetWorld();
			world->DestroyBody(object);
		}

		int getTransform(State & state, b2Body * object){
			Transform * interfaceTransform = dynamic_cast<Transform*>(state.interfaces["LuaBox2D_Transform"]);
			interfaceTransform->push(new b2Transform(object->GetTransform()), true);
			return 1;
		}

		int setTransform(State & state, b2Body * object){
			Stack * stack = state.stack;
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			if (stack->is<LUA_TUSERDATA>(1) && stack->is<LUA_TNUMBER>(2)){
				b2Vec2 * position = interfaceVec2->get(1);
				if (position != nullptr){
					object->SetTransform(*position, static_cast<float32>(stack->to<LUA_NUMBER>(2)));
				}
			}
			return 0;
		}

		int getPosition(State & state, b2Body * object){
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			interfaceVec2->push(new b2Vec2(object->GetPosition()), true);
			return 1;
		}

		int getAngle(State & state, b2Body * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetAngle()));
			return 1;
		}

		int getWorldCenter(State & state, b2Body * object){
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			interfaceVec2->push(new b2Vec2(object->GetWorldCenter()), true);
			return 1;
		}

		int getLocalCenter(State & state, b2Body * object){
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			interfaceVec2->push(new b2Vec2(object->GetLocalCenter()), true);
			return 1;
		}
		
		int getLinearVelocity(State & state, b2Body * object){
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			interfaceVec2->push(new b2Vec2(object->GetLinearVelocity()), true);
			return 1;
		}

		int setLinearVelocity(State & state, b2Body * object){
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			b2Vec2 * linearVelocity = interfaceVec2->get(1);
			if (linearVelocity != nullptr){
				object->SetLinearVelocity(*linearVelocity);
			}
			return 0;
		}

		int getAngularVelocity(State & state, b2Body * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetAngularVelocity()));
			return 1;
		}

		int setAngularVelocity(State & state, b2Body * object){
			object->SetAngularVelocity(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
			return 0;
		}

		int applyForce(State & state, b2Body * object){
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			b2Vec2 * force = interfaceVec2->get(1);
			b2Vec2 * point = interfaceVec2->get(2);
			if (force!=nullptr && point!=nullptr){
				object->ApplyForce(*force, *point, state.stack->to<bool>(3));
			}
			return 0;
		}

		int applyForceToCenter(State & state, b2Body * object){
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			b2Vec2 * force = interfaceVec2->get(1);
			if (force!=nullptr){
				object->ApplyForceToCenter(*force, state.stack->to<bool>(2));
			}
			return 0;
		}

		int applyTorque(State & state, b2Body * object){
			object->ApplyTorque(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)), state.stack->to<bool>(2));
			return 0;
		}

		int applyLinearImpulse(State & state, b2Body * object){
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			b2Vec2 * force = interfaceVec2->get(1);
			b2Vec2 * point = interfaceVec2->get(2);
			if (force!=nullptr && point!=nullptr){
				object->ApplyLinearImpulse(*force, *point, state.stack->to<bool>(3));
			}
			return 0;
		}

		int applyAngularImpulse(State & state, b2Body * object){
			object->ApplyAngularImpulse(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)), state.stack->to<bool>(2));
			return 0;
		}

		int getMass(State & state, b2Body * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetMass()));
			return 1;
		}

		int getInertia(State & state, b2Body * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetInertia()));
			return 1;
		}

		int createFixture(State & state, b2Body * object){
			Fixture * interfaceFixture = dynamic_cast<Fixture*>(state.interfaces["LuaBox2D_Fixture"]);
			FixtureDef * interfaceFixtureDef = dynamic_cast<FixtureDef*>(state.interfaces["LuaBox2D_FixtureDef"]);
			Shape * interfaceShape = dynamic_cast<Shape*>(state.interfaces["LuaBox2D_Shape"]);
			Stack * stack = state.stack;

			if (stack->is<LUA_TUSERDATA>(1)){
				b2FixtureDef * fixtureDef = interfaceFixtureDef->get(1);
				if (fixtureDef != nullptr){
					interfaceFixture->push(object->CreateFixture(fixtureDef));
					return 1;
				}else{
					b2Shape * shape = interfaceShape->get(1);
					if (shape != nullptr && stack->is<LUA_TNUMBER>(2)){
						interfaceFixture->push(object->CreateFixture(shape, static_cast<float32>(stack->to<LUA_NUMBER>(1))));
						return 1;
					}
				}
			}
			return 0;
		}

		//TODO
		int getMassData(State & state, b2Body * object){
			//Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			b2MassData massData;
			object->GetMassData(&massData);
			//interfaceVec2->push(new b2Vec2(), true);
			return 1;
		}

		//TODO
		int setMassData(State & state, b2Body * object){
			//Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			b2MassData * massData = nullptr;//interfaceVec2->get(1);
			if (massData != nullptr){
				object->SetMassData(massData);
			}
			return 0;
		}

		int resetMassData(State & state, b2Body * object){
			object->ResetMassData();
			return 0;
		}

		int getWorldPoint(State & state, b2Body * object){
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			b2Vec2 * localPoint = interfaceVec2->get(1);
			if (localPoint != nullptr){
				interfaceVec2->push(new b2Vec2(object->GetWorldPoint(*localPoint)));
				return 1;
			}
			return 0;
		}

		int getWorldVector(State & state, b2Body * object){
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			b2Vec2 * localVector = interfaceVec2->get(1);
			if (localVector != nullptr){
				interfaceVec2->push(new b2Vec2(object->GetWorldVector(*localVector)));
				return 1;
			}
			return 0;
		}

		int getLocalPoint(State & state, b2Body * object){
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			b2Vec2 * worldPoint = interfaceVec2->get(1);
			if (worldPoint != nullptr){
				interfaceVec2->push(new b2Vec2(object->GetLocalPoint(*worldPoint)));
				return 1;
			}
			return 0;
		}

		int getLocalVector(State & state, b2Body * object){
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			b2Vec2 * worldVector = interfaceVec2->get(1);
			if (worldVector != nullptr){
				interfaceVec2->push(new b2Vec2(object->GetLocalVector(*worldVector)));
				return 1;
			}
			return 0;
		}

		int getLinearVelocityFromWorldPoint(State & state, b2Body * object){
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			b2Vec2 * worldPoint = interfaceVec2->get(1);
			if (worldPoint != nullptr){
				interfaceVec2->push(new b2Vec2(object->GetLinearVelocityFromWorldPoint(*worldPoint)));
				return 1;
			}
			return 0;
		}
		
		int getLinearVelocityFromLocalPoint(State & state, b2Body * object){
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			b2Vec2 * worldPoint = interfaceVec2->get(1);
			if (worldPoint != nullptr){
				interfaceVec2->push(new b2Vec2(object->GetLinearVelocityFromLocalPoint(*worldPoint)));
				return 1;
			}
			return 0;
		}

		int getLinearDamping(State & state, b2Body * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetLinearDamping()));
			return 1;
		}

		int setLinearDamping(State & state, b2Body * object){
			object->SetLinearDamping(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
			return 0;
		}

		int getAngularDamping(State & state, b2Body * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetAngularDamping()));
			return 1;
		}

		int setAngularDamping(State & state, b2Body * object){
			object->SetAngularDamping(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
			return 0;
		}

		int getGravityScale(State & state, b2Body * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetGravityScale()));
			return 1;
		}

		int setGravityScale(State & state, b2Body * object){
			object->SetGravityScale(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
			return 0;
		}

		int getType(State & state, b2Body * object){
			state.stack->push(bodyTypeToString(object->GetType()));
			return 1;
		}

		int setType(State & state, b2Body * object){
			if (state.stack->is<LUA_TSTRING>(1)){
				object->SetType(stringToBodyType(state.stack->to<std::string>(1)));
			}
			return 0;
		}

		int getBullet(State & state, b2Body * object){
			state.stack->push<bool>(object->IsBullet());
			return 1;
		}

		int setBullet(State & state, b2Body * object){
			object->SetBullet(state.stack->to<bool>(1));
			return 0;
		}

		int getSleepingAllowed(State & state, b2Body * object){
			state.stack->push<bool>(object->IsSleepingAllowed());
			return 1;
		}

		int setSleepingAllowed(State & state, b2Body * object){
			object->SetSleepingAllowed(state.stack->to<bool>(1));
			return 0;
		}

		int getAwake(State & state, b2Body * object){
			state.stack->push<bool>(object->IsAwake());
			return 1;
		}

		int setAwake(State & state, b2Body * object){
			object->SetAwake(state.stack->to<bool>(1));
			return 0;
		}

		int getActive(State & state, b2Body * object){
			state.stack->push<bool>(object->IsActive());
			return 1;
		}

		int setActive(State & state, b2Body * object){
			object->SetActive(state.stack->to<bool>(1));
			return 0;
		}

		int getFixedRotation(State & state, b2Body * object){
			state.stack->push<bool>(object->IsFixedRotation());
			return 1;
		}

		int setFixedRotation(State & state, b2Body * object){
			object->SetFixedRotation(state.stack->to<bool>(1));
			return 0;
		}

		int getWorld(State & state, b2Body * object){
			World * interfaceWorld = dynamic_cast<World*>(state.interfaces["LuaBox2D_World"]);
			interfaceWorld->push(object->GetWorld(), false);
			return 1;
		}
	};

	void initBody(State *);
};

#endif
