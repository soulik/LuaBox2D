#include "common.hpp"
#include "objects/Shape.hpp"
#include "objects/BodyDef.hpp"
#include "objects/Fixture.hpp"
#include "objects/FixtureDef.hpp"
#include "objects/World.hpp"
#include "objects/Transform.hpp"
#include "objects/MassData.hpp"
#include "objects/Vec2.hpp"
#include "objects/Body.hpp"
#include "objects/JointEdge.hpp"
#include "objects/ContactEdge.hpp"

namespace LuaBox2D {
	void initBody(State * state){
		state->registerInterface<Body>("LuaBox2D_Body");
	}

	void Body::destructor(State & state, b2Body * object){
		b2World * world = object->GetWorld();
		int oldRef = static_cast<int>(reinterpret_cast<intptr_t>(object->GetUserData()));
		if (oldRef != LUA_NOREF && oldRef != 0){
			state.stack->unref(oldRef);
		}
		world->DestroyBody(object);
	}

	int Body::createFixture(State & state, b2Body * object){
		Fixture * interfaceFixture = state.getInterface<Fixture>("LuaBox2D_Fixture");
		FixtureDef * interfaceFixtureDef = state.getInterface<FixtureDef>("LuaBox2D_FixtureDef");
		Shape * interfaceShape = state.getInterface<Shape>("LuaBox2D_Shape");
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

	b2Body * Body::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		b2Body * obj = nullptr;

		BodyDef * interfaceBodyDef = state.getInterface<BodyDef>("LuaBox2D_BodyDef");
		World * interfaceWorld = state.getInterface<World>("LuaBox2D_World");

		b2BodyDef * bodyDef = interfaceBodyDef->get(1);
		b2World * world = interfaceWorld->get(2);

		if (bodyDef != nullptr && world != nullptr){
			obj = world->CreateBody(bodyDef);
		}

		return obj;
	}

	int Body::getWorld(State & state, b2Body * object){
		World * interfaceWorld = state.getInterface<World>("LuaBox2D_World");
		interfaceWorld->push(object->GetWorld(), false);
		return 1;
	}

	int Body::getTransform(State & state, b2Body * object){
		Transform * interfaceTransform = state.getInterface<Transform>("LuaBox2D_Transform");
		interfaceTransform->push(new b2Transform(object->GetTransform()), true);
		return 1;
	}

	int Body::setTransform(State & state, b2Body * object){
		Stack * stack = state.stack;
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		if (stack->is<LUA_TUSERDATA>(1) && stack->is<LUA_TNUMBER>(2)){
			b2Vec2 * position = interfaceVec2->get(1);
			if (position != nullptr){
				object->SetTransform(*position, static_cast<float32>(stack->to<LUA_NUMBER>(2)));
			}
		}
		return 0;
	}

	int Body::getPosition(State & state, b2Body * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetPosition()), true);
		return 1;
	}

	int Body::getAngle(State & state, b2Body * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetAngle()));
		return 1;
	}

	int Body::getWorldCenter(State & state, b2Body * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetWorldCenter()), true);
		return 1;
	}

	int Body::getLocalCenter(State & state, b2Body * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetLocalCenter()), true);
		return 1;
	}

	int Body::getLinearVelocity(State & state, b2Body * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetLinearVelocity()), true);
		return 1;
	}

	int Body::setLinearVelocity(State & state, b2Body * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * linearVelocity = interfaceVec2->get(1);
		if (linearVelocity != nullptr){
			object->SetLinearVelocity(*linearVelocity);
		}
		return 0;
	}

	int Body::getAngularVelocity(State & state, b2Body * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetAngularVelocity()));
		return 1;
	}

	int Body::setAngularVelocity(State & state, b2Body * object){
		object->SetAngularVelocity(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int Body::applyForce(State & state, b2Body * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * force = interfaceVec2->get(1);
		b2Vec2 * point = interfaceVec2->get(2);
		if (force!=nullptr && point!=nullptr){
			object->ApplyForce(*force, *point, state.stack->to<bool>(3));
		}
		return 0;
	}

	int Body::applyForceToCenter(State & state, b2Body * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * force = interfaceVec2->get(1);
		if (force!=nullptr){
			object->ApplyForceToCenter(*force, state.stack->to<bool>(2));
		}
		return 0;
	}

	int Body::applyTorque(State & state, b2Body * object){
		object->ApplyTorque(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)), state.stack->to<bool>(2));
		return 0;
	}

	int Body::applyLinearImpulse(State & state, b2Body * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * force = interfaceVec2->get(1);
		b2Vec2 * point = interfaceVec2->get(2);
		if (force!=nullptr && point!=nullptr){
			object->ApplyLinearImpulse(*force, *point, state.stack->to<bool>(3));
		}
		return 0;
	}

	int Body::applyAngularImpulse(State & state, b2Body * object){
		object->ApplyAngularImpulse(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)), state.stack->to<bool>(2));
		return 0;
	}

	int Body::getMass(State & state, b2Body * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetMass()));
		return 1;
	}

	int Body::getInertia(State & state, b2Body * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetInertia()));
		return 1;
	}

	int Body::getMassData(State & state, b2Body * object){
		MassData * interfaceMassData = state.getInterface<MassData>("LuaBox2D_MassData");
		b2MassData * massData = new b2MassData();
		object->GetMassData(massData);
		interfaceMassData->push(massData, true);
		return 1;
	}

	int Body::setMassData(State & state, b2Body * object){
		MassData * interfaceMassData = state.getInterface<MassData>("LuaBox2D_MassData");
		b2MassData * massData = interfaceMassData->get(1);
		if (massData != nullptr){
			object->SetMassData(massData);
		}
		return 0;
	}

	int Body::resetMassData(State & state, b2Body * object){
		object->ResetMassData();
		return 0;
	}

	int Body::getWorldPoint(State & state, b2Body * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * localPoint = interfaceVec2->get(1);
		if (localPoint != nullptr){
			interfaceVec2->push(new b2Vec2(object->GetWorldPoint(*localPoint)));
			return 1;
		}
		return 0;
	}

	int Body::getWorldVector(State & state, b2Body * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * localVector = interfaceVec2->get(1);
		if (localVector != nullptr){
			interfaceVec2->push(new b2Vec2(object->GetWorldVector(*localVector)));
			return 1;
		}
		return 0;
	}

	int Body::getLocalPoint(State & state, b2Body * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * worldPoint = interfaceVec2->get(1);
		if (worldPoint != nullptr){
			interfaceVec2->push(new b2Vec2(object->GetLocalPoint(*worldPoint)));
			return 1;
		}
		return 0;
	}

	int Body::getLocalVector(State & state, b2Body * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * worldVector = interfaceVec2->get(1);
		if (worldVector != nullptr){
			interfaceVec2->push(new b2Vec2(object->GetLocalVector(*worldVector)));
			return 1;
		}
		return 0;
	}

	int Body::getLinearVelocityFromWorldPoint(State & state, b2Body * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * worldPoint = interfaceVec2->get(1);
		if (worldPoint != nullptr){
			interfaceVec2->push(new b2Vec2(object->GetLinearVelocityFromWorldPoint(*worldPoint)));
			return 1;
		}
		return 0;
	}

	int Body::getLinearVelocityFromLocalPoint(State & state, b2Body * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * worldPoint = interfaceVec2->get(1);
		if (worldPoint != nullptr){
			interfaceVec2->push(new b2Vec2(object->GetLinearVelocityFromLocalPoint(*worldPoint)));
			return 1;
		}
		return 0;
	}

	int Body::getLinearDamping(State & state, b2Body * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetLinearDamping()));
		return 1;
	}

	int Body::setLinearDamping(State & state, b2Body * object){
		object->SetLinearDamping(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int Body::getAngularDamping(State & state, b2Body * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetAngularDamping()));
		return 1;
	}

	int Body::setAngularDamping(State & state, b2Body * object){
		object->SetAngularDamping(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int Body::getGravityScale(State & state, b2Body * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetGravityScale()));
		return 1;
	}

	int Body::setGravityScale(State & state, b2Body * object){
		object->SetGravityScale(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int Body::getType(State & state, b2Body * object){
		state.stack->push<const std::string &>(bodyTypeToString(object->GetType()));
		return 1;
	}

	int Body::setType(State & state, b2Body * object){
		if (state.stack->is<LUA_TSTRING>(1)){
			const std::string typeName = state.stack->to<const std::string>(1);
			object->SetType(stringToBodyType(typeName));
		}
		return 0;
	}

	int Body::getBullet(State & state, b2Body * object){
		state.stack->push<bool>(object->IsBullet());
		return 1;
	}

	int Body::setBullet(State & state, b2Body * object){
		object->SetBullet(state.stack->to<bool>(1));
		return 0;
	}

	int Body::getSleepingAllowed(State & state, b2Body * object){
		state.stack->push<bool>(object->IsSleepingAllowed());
		return 1;
	}

	int Body::setSleepingAllowed(State & state, b2Body * object){
		object->SetSleepingAllowed(state.stack->to<bool>(1));
		return 0;
	}

	int Body::getAwake(State & state, b2Body * object){
		state.stack->push<bool>(object->IsAwake());
		return 1;
	}

	int Body::setAwake(State & state, b2Body * object){
		object->SetAwake(state.stack->to<bool>(1));
		return 0;
	}

	int Body::getActive(State & state, b2Body * object){
		state.stack->push<bool>(object->IsActive());
		return 1;
	}

	int Body::setActive(State & state, b2Body * object){
		object->SetActive(state.stack->to<bool>(1));
		return 0;
	}

	int Body::getFixedRotation(State & state, b2Body * object){
		state.stack->push<bool>(object->IsFixedRotation());
		return 1;
	}

	int Body::setFixedRotation(State & state, b2Body * object){
		object->SetFixedRotation(state.stack->to<bool>(1));
		return 0;
	}

	int Body::getFixture(State & state, b2Body * object){
		Fixture * interfaceFixture = state.getInterface<Fixture>("LuaBox2D_Fixture");
		b2Fixture * fixture = object->GetFixtureList();
		if (fixture){
			interfaceFixture->push(fixture, false);
			return 1;
		}else{
			return 0;
		}
	}

	int Body::getJoint(State & state, b2Body * object){
		JointEdge * interfaceJointEdge = state.getInterface<JointEdge>("LuaBox2D_JointEdge");
		b2JointEdge * jointEdge = object->GetJointList();
		if (jointEdge){
			interfaceJointEdge->push(jointEdge, false);
			return 1;
		}else{
			return 0;
		}
	}

	int Body::getContact(State & state, b2Body * object){
		ContactEdge * interfaceContactEdge = state.getInterface<ContactEdge>("LuaBox2D_ContactEdge");
		b2ContactEdge * contactEdge = object->GetContactList();
		if (contactEdge){
			interfaceContactEdge->push(contactEdge, false);
			return 1;
		}else{
			return 0;
		}
	}

	int Body::getUserData(State & state, b2Body * object){
		int ref = static_cast<int>(reinterpret_cast<intptr_t>(object->GetUserData()));
		if (ref != LUA_NOREF && ref != 0){
			state.stack->regValue(ref);
			return 1;
		}else{
			return 0;
		}
	}

	int Body::setUserData(State & state, b2Body * object){
		int oldRef = static_cast<int>(reinterpret_cast<intptr_t>(object->GetUserData()));
		if (oldRef != LUA_NOREF && oldRef != 0){
			state.stack->unref(oldRef);
		}
		if (!state.stack->is<LUA_TNIL>(1)){
			state.stack->pushValue(1);
			int ref = state.stack->ref();

			object->SetUserData(reinterpret_cast<void*>(ref));
		}
		return 0;
	}

	int Body::getNext(State & state, b2Body * object){
		Body * interfaceBody = state.getInterface<Body>("LuaBox2D_Body");
		b2Body * body = object->GetNext();
		if (body){
			interfaceBody->push(body, false);
			return 1;
		}else{
			return 0;
		}
	}

};
