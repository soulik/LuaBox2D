#ifndef LUABOX2D_WORLD_H
#define LUABOX2D_WORLD_H

#include "objects/Vec2.hpp"
#include "objects/BodyDef.hpp"
#include "objects/JointDef.hpp"
#include "objects/Body.hpp"
#include "objects/Joint.hpp"

namespace LuaBox2D {
	class World : public Object<b2World> {
	public:
		explicit World(State * state) : Object<b2World>(state){
			LUTOK_PROPERTY("allowSleeping", &World::getAllowSleeping, &World::setAllowSleeping);
			LUTOK_PROPERTY("warmStarting", &World::getWarmStarting, &World::setWarmStarting);
			LUTOK_PROPERTY("continuousPhysics", &World::getContinuousPhysics, &World::setContinuousPhysics);
			LUTOK_PROPERTY("subStepping", &World::getSubStepping, &World::setSubStepping);

			LUTOK_PROPERTY("gravity", &World::getGravity, &World::setGravity);
			LUTOK_PROPERTY("locked", &World::getLocked, &World::nullMethod);
			LUTOK_PROPERTY("autoClearForces", &World::getAutoClearForces, &World::setAutoClearForces);

			LUTOK_PROPERTY("proxyCount", &World::getProxyCount, &World::nullMethod);
			LUTOK_PROPERTY("bodyCount", &World::getBodyCount, &World::nullMethod);
			LUTOK_PROPERTY("jointCount", &World::getJointCount, &World::nullMethod);
			LUTOK_PROPERTY("contactCount", &World::getContactCount, &World::nullMethod);
			LUTOK_PROPERTY("treeHeight", &World::getTreeHeight, &World::nullMethod);
			LUTOK_PROPERTY("treeBalance", &World::getTreeBalance, &World::nullMethod);
			LUTOK_PROPERTY("treeQuality", &World::getTreeQuality, &World::nullMethod);

			LUTOK_METHOD("step", &World::step);
			LUTOK_METHOD("clearForces", &World::clearForces);
			LUTOK_METHOD("shiftToOritin", &World::shiftToOritin);

			LUTOK_METHOD("createBody", &World::createBody);
			LUTOK_METHOD("createJoint", &World::createJoint);

			LUTOK_PROPERTY("body", &World::getBody, &World::nullMethod);
			LUTOK_PROPERTY("joint", &World::getJoint, &World::nullMethod);
			LUTOK_PROPERTY("contact", &World::getContact, &World::nullMethod);
		}

		b2World * constructor(State & state){
			b2World * obj = nullptr;
			Stack * stack = state.stack;
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			b2Vec2 * gravity = interfaceVec2->get(1);

			if (gravity != nullptr){
				obj = new b2World(*gravity);
			}else{
				obj = new b2World(b2Vec2(0, 0));
			}
			
			return obj;
		}
		void destructor(State & state, b2World * object){
			delete object;
		}

		int createBody(State & state, b2World * object);

		int createJoint(State & state, b2World * object);

		int getBody(State & state, b2World * object){
			return 0;
		}

		int getJoint(State & state, b2World * object){
			return 0;
		}

		int getContact(State & state, b2World * object){
			return 0;
		}

		int step(State & state, b2World * object){
			Stack * stack = state.stack;
			if (stack->is<LUA_TNUMBER>(1) && stack->is<LUA_TNUMBER>(2) && stack->is<LUA_TNUMBER>(3)){
				float32 timeStep = static_cast<float32>(stack->to<LUA_NUMBER>(1));
				int32 velocityIterations = static_cast<int32>(stack->to<int>(2));
				int32 positionIterations = static_cast<int32>(stack->to<int>(3));
				object->Step(timeStep, velocityIterations, positionIterations);
			}
			return 0;
		}

		int clearForces(State & state, b2World * object){
			object->ClearForces();
			return 0;
		}

		int getAllowSleeping(State & state, b2World * object){
			state.stack->push<bool>(object->GetAllowSleeping());
			return 1;
		}

		int setAllowSleeping(State & state, b2World * object){
			object->SetAllowSleeping(state.stack->to<bool>(1));
			return 0;
		}

		int getWarmStarting(State & state, b2World * object){
			state.stack->push<bool>(object->GetWarmStarting());
			return 1;
		}

		int setWarmStarting(State & state, b2World * object){
			object->SetWarmStarting(state.stack->to<bool>(1));
			return 0;
		}

		int getContinuousPhysics(State & state, b2World * object){
			state.stack->push<bool>(object->GetContinuousPhysics());
			return 1;
		}

		int setContinuousPhysics(State & state, b2World * object){
			object->SetContinuousPhysics(state.stack->to<bool>(1));
			return 0;
		}

		int getSubStepping(State & state, b2World * object){
				state.stack->push<bool>(object->GetSubStepping());
				return 1;
		}

		int setSubStepping(State & state, b2World * object){
			object->SetSubStepping(state.stack->to<bool>(1));
			return 0;
		}

		int getGravity(State & state, b2World * object){
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			interfaceVec2->push(&object->GetGravity(), false);
			return 1;
		}

		int setGravity(State & state, b2World * object){
			Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
			b2Vec2 * gravity = interfaceVec2->get(1);
			if (gravity != nullptr){
				object->SetGravity(*gravity);
			}
			return 0;
		}

		int getLocked(State & state, b2World * object){
			state.stack->push<bool>(object->IsLocked());
			return 1;
		}

		int getAutoClearForces(State & state, b2World * object){
			state.stack->push<bool>(object->GetAutoClearForces());
			return 1;
		}

		int setAutoClearForces(State & state, b2World * object){
			object->SetAutoClearForces(state.stack->to<bool>(1));
			return 0;
		}

		int shiftToOritin(State & state, b2World * object){
				Vec2 * interfaceVec2 = dynamic_cast<Vec2*>(state.interfaces["LuaBox2D_Vec2"]);
				b2Vec2 * gravity = interfaceVec2->get(1);
				if (gravity != nullptr){
					object->ShiftOrigin(*gravity);
				}
				return 0;
		}

		int getProxyCount(State & state, b2World * object){
			state.stack->push<int>(object->GetProxyCount());
			return 1;
		}

		int getBodyCount(State & state, b2World * object){
			state.stack->push<int>(object->GetBodyCount());
			return 1;
		}
		
		int getJointCount(State & state, b2World * object){
			state.stack->push<int>(object->GetJointCount());
			return 1;
		}

		int getContactCount(State & state, b2World * object){
			state.stack->push<int>(object->GetContactCount());
			return 1;
		}

		int getTreeHeight(State & state, b2World * object){
			state.stack->push<int>(object->GetTreeHeight());
			return 1;
		}

		int getTreeBalance(State & state, b2World * object){
			state.stack->push<int>(object->GetTreeBalance());
			return 1;
		}

		int getTreeQuality(State & state, b2World * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetTreeQuality()));
			return 1;
		}

	};

	void initWorld(State *);
};

#endif