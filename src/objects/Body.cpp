#include "common.hpp"
#include "objects/Body.hpp"

namespace LuaBox2D {
	void initBody(State * state){
		state->registerInterface<Body>("LuaBox2D_Body");
	}

	int Body::createFixture(State & state, b2Body * object){
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

	b2Body * Body::constructor(State & state){
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

	int Body::getWorld(State & state, b2Body * object){
		World * interfaceWorld = dynamic_cast<World*>(state.interfaces["LuaBox2D_World"]);
		interfaceWorld->push(object->GetWorld(), false);
		return 1;
	}
};
