#include "common.hpp"

#include "objects/Vec2.hpp"
#include "objects/BodyDef.hpp"
#include "objects/JointDef.hpp"
#include "objects/Body.hpp"
#include "objects/Joint.hpp"
#include "objects/ContactListener.hpp"
#include "objects/ContactFilter.hpp"
#include "objects/ContactManager.hpp"
#include "objects/Contact.hpp"

#include "objects/World.hpp"

#include "objects/QueryCallback.hpp"
#include "objects/RayCastCallback.hpp"
#include "objects/AABB.hpp"

namespace LuaBox2D {
	void initWorld(State * state){
		state->registerInterface<World>("LuaBox2D_World");
	}

	int World::createBody(State & state, b2World * object){
		BodyDef * interfaceBodyDef = state.getInterface<BodyDef>("LuaBox2D_BodyDef");
		b2BodyDef * bodyDef = interfaceBodyDef->get(1);
		if (bodyDef != nullptr){
			Body * interfaceBody = state.getInterface<Body>("LuaBox2D_Body");
			b2Body * body = object->CreateBody(bodyDef);
			interfaceBody->push(body, true);
			return 1;
		}else{
			return 0;
		}
	}

	int World::createJoint(State & state, b2World * object){
		JointDef * interfaceJointDef = state.getInterface<JointDef>("LuaBox2D_JointDef");
		b2JointDef * jointDef = interfaceJointDef->get(1);
		if (jointDef != nullptr){
			Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
			b2Joint * joint = object->CreateJoint(jointDef);
			interfaceJoint->push(joint, true);
			return 1;
		}else{
			return 0;
		}
	}

	b2World * World::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		b2World * obj = nullptr;
		Stack * stack = state.stack;
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * gravity = interfaceVec2->get(1);

		if (gravity != nullptr){
			obj = new b2World(*gravity);
		}else{
			obj = new b2World(b2Vec2(0, 0));
		}

		return obj;
	}

	void World::destructor(State & state, b2World * object){
		delete object;
	}

	int World::getBody(State & state, b2World * object){
		Body * interfaceBody = state.getInterface<Body>("LuaBox2D_Body");
		b2Body * body = object->GetBodyList();
		if (body){
			interfaceBody->push(body, false);
			return 1;
		}else{
			return 0;
		}
	}

	int World::getJoint(State & state, b2World * object){
		Joint * interfaceJoint = state.getInterface<Joint>("LuaBox2D_Joint");
		b2Joint * joint = object->GetJointList();
		if (joint){
			interfaceJoint->push(joint, false);
			return 1;
		}else{
			return 0;
		}
	}

	int World::getContact(State & state, b2World * object){
		Contact * interfaceContact = state.getInterface<Contact>("LuaBox2D_Contact");
		b2Contact * contact = object->GetContactList();
		if (contact){
			interfaceContact->push(contact, false);
			return 1;
		}else{
			return 0;
		}
	}

	int World::step(State & state, b2World * object){
		Stack * stack = state.stack;
		if (stack->is<LUA_TNUMBER>(1) && stack->is<LUA_TNUMBER>(2) && stack->is<LUA_TNUMBER>(3)){
			float32 timeStep = static_cast<float32>(stack->to<LUA_NUMBER>(1));
			int32 velocityIterations = static_cast<int32>(stack->to<int>(2));
			int32 positionIterations = static_cast<int32>(stack->to<int>(3));
			object->Step(timeStep, velocityIterations, positionIterations);
		}
		return 0;
	}

	int World::clearForces(State & state, b2World * object){
		object->ClearForces();
		return 0;
	}

	int World::getAllowSleeping(State & state, b2World * object){
		state.stack->push<bool>(object->GetAllowSleeping());
		return 1;
	}

	int World::setAllowSleeping(State & state, b2World * object){
		object->SetAllowSleeping(state.stack->to<bool>(1));
		return 0;
	}

	int World::getWarmStarting(State & state, b2World * object){
		state.stack->push<bool>(object->GetWarmStarting());
		return 1;
	}

	int World::setWarmStarting(State & state, b2World * object){
		object->SetWarmStarting(state.stack->to<bool>(1));
		return 0;
	}

	int World::getContinuousPhysics(State & state, b2World * object){
		state.stack->push<bool>(object->GetContinuousPhysics());
		return 1;
	}

	int World::setContinuousPhysics(State & state, b2World * object){
		object->SetContinuousPhysics(state.stack->to<bool>(1));
		return 0;
	}

	int World::getSubStepping(State & state, b2World * object){
		state.stack->push<bool>(object->GetSubStepping());
		return 1;
	}

	int World::setSubStepping(State & state, b2World * object){
		object->SetSubStepping(state.stack->to<bool>(1));
		return 0;
	}

	int World::getGravity(State & state, b2World * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(new b2Vec2(object->GetGravity()), true);
		return 1;
	}

	int World::setGravity(State & state, b2World * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * gravity = interfaceVec2->get(1);
		if (gravity != nullptr){
			object->SetGravity(*gravity);
		}
		return 0;
	}

	int World::getLocked(State & state, b2World * object){
		state.stack->push<bool>(object->IsLocked());
		return 1;
	}

	int World::getAutoClearForces(State & state, b2World * object){
		state.stack->push<bool>(object->GetAutoClearForces());
		return 1;
	}

	int World::setAutoClearForces(State & state, b2World * object){
		object->SetAutoClearForces(state.stack->to<bool>(1));
		return 0;
	}

	int World::shiftToOritin(State & state, b2World * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * gravity = interfaceVec2->get(1);
		if (gravity != nullptr){
			object->ShiftOrigin(*gravity);
		}
		return 0;
	}

	int World::getProxyCount(State & state, b2World * object){
		state.stack->push<int>(object->GetProxyCount());
		return 1;
	}

	int World::getBodyCount(State & state, b2World * object){
		state.stack->push<int>(object->GetBodyCount());
		return 1;
	}

	int World::getJointCount(State & state, b2World * object){
		state.stack->push<int>(object->GetJointCount());
		return 1;
	}

	int World::getContactCount(State & state, b2World * object){
		state.stack->push<int>(object->GetContactCount());
		return 1;
	}

	int World::getTreeHeight(State & state, b2World * object){
		state.stack->push<int>(object->GetTreeHeight());
		return 1;
	}

	int World::getTreeBalance(State & state, b2World * object){
		state.stack->push<int>(object->GetTreeBalance());
		return 1;
	}

	int World::getTreeQuality(State & state, b2World * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetTreeQuality()));
		return 1;
	}


	int World::getContactListener(State & state, b2World * object){
		ContactListener * interfaceContactListener = state.getInterface<ContactListener>("LuaBox2D_ContactListener");
		interfaceContactListener->push( dynamic_cast<LuaBox2DContactListener*>(object->GetContactManager().m_contactListener), false);
		return 1;
	}

	int World::setContactListener(State & state, b2World * object){
		ContactListener * interfaceContactListener = state.getInterface<ContactListener>("LuaBox2D_ContactListener");
		LuaBox2DContactListener * listener = interfaceContactListener->get(1);
		if (listener != nullptr){
			object->SetContactListener(listener);
		}
		return 0;
	}

	int World::getContactFilter(State & state, b2World * object){
		ContactFilter * interfaceContactFilter = state.getInterface<ContactFilter>("LuaBox2D_ContactFilter");
		interfaceContactFilter->push( dynamic_cast<LuaBox2DContactFilter*>(object->GetContactManager().m_contactFilter), false);
		return 1;
	}

	int World::setContactFilter(State & state, b2World * object){
		ContactFilter * interfaceContactFilter = state.getInterface<ContactFilter>("LuaBox2D_ContactFilter");
		LuaBox2DContactFilter * filter = interfaceContactFilter->get(1);
		if (filter != nullptr){
			object->SetContactFilter(filter);
		}
		return 0;
	}

	int World::getContactManager(State & state, b2World * object){
		ContactManager * interfaceContactManager = state.getInterface<ContactManager>("LuaBox2D_ContactManager");
		interfaceContactManager->push(new b2ContactManager(object->GetContactManager()), true);
		return 1;
	}

	int World::queryAABB(State & state, b2World * object){
		if (state.stack->is<LUA_TUSERDATA>(1) && state.stack->is<LUA_TUSERDATA>(2)){
			QueryCallback * interfaceQueryCallback = state.getInterface<QueryCallback>("LuaBox2D_QueryCallback");
			AABB * interfaceAABB = state.getInterface<AABB>("LuaBox2D_AABB");

			LuaBox2DQueryCallback * callback = interfaceQueryCallback->get(1);
			b2AABB * aabb = interfaceAABB->get(2);
			if (callback != nullptr && aabb != nullptr){
				object->QueryAABB(callback, *aabb);
			}
		}
		return 0;
	}

	int World::rayCast(State & state, b2World * object){
		if (state.stack->is<LUA_TUSERDATA>(1) && state.stack->is<LUA_TUSERDATA>(2) && state.stack->is<LUA_TUSERDATA>(3)){
			RayCastCallback * interfaceRayCastCallback = state.getInterface<RayCastCallback>("LuaBox2D_RayCastCallback");
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");

			LuaBox2DRayCastCallback * callback = interfaceRayCastCallback->get(1);
			b2Vec2 * point1 = interfaceVec2->get(2);
			b2Vec2 * point2 = interfaceVec2->get(3);
			if (callback != nullptr && point1 != nullptr && point2 != nullptr){
				object->RayCast(callback, *point1, *point2);
			}
		}
		return 0;
	}
};
