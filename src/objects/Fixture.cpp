#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Shape.hpp"
#include "objects/Body.hpp"
#include "objects/AABB.hpp"
#include "objects/RayCastInput.hpp"
#include "objects/RayCastOutput.hpp"
#include "objects/MassData.hpp"
#include "objects/Filter.hpp"
#include "objects/Fixture.hpp"

namespace LuaBox2D {
	void initFixture(State * state){
		state->registerInterface<Fixture>("LuaBox2D_Fixture");
	}

	int Fixture::getBody(State & state, b2Fixture * object){
		Body * interfaceBody = state.getInterface<Body>("LuaBox2D_Body");
		interfaceBody->push(object->GetBody(), false);
		return 1;
	}

	b2Fixture * Fixture::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		return nullptr;
	}

	void Fixture::destructor(State & state, b2Fixture * object){
		int oldRef = static_cast<int>(reinterpret_cast<intptr_t>(object->GetUserData()));
		if (oldRef != LUA_NOREF && oldRef != 0){
			state.stack->unref(oldRef);
		}
		object->GetBody()->DestroyFixture(object);
	}

	int Fixture::getType(State & state, b2Fixture * object){
		state.stack->push<int>(static_cast<int>(object->GetType()));
		return 1;
	}

	int Fixture::getShape(State & state, b2Fixture * object){
		Shape * interfaceShape = state.getInterface<Shape>("LuaBox2D_Shape");
		interfaceShape->push(object->GetShape(), false);
		return 1;
	}

	int Fixture::getSensor(State & state, b2Fixture * object){
		state.stack->push<bool>(object->IsSensor());
		return 1;
	}

	int Fixture::setSensor(State & state, b2Fixture * object){
		object->SetSensor(state.stack->to<bool>(1));
		return 0;
	}

	int Fixture::getFilter(State & state, b2Fixture * object){
		Filter * interfaceFilter = state.getInterface<Filter>("LuaBox2D_Filter");
		interfaceFilter->push(new b2Filter(object->GetFilterData()), true);
		return 1;
	}

	int Fixture::setFilter(State & state, b2Fixture * object){
		Filter * interfaceFilter = state.getInterface<Filter>("LuaBox2D_Filter");
		b2Filter * filter = interfaceFilter->get(1);
		if (filter != nullptr){
			object->SetFilterData(*filter);
		}
		return 0;
	}

	int Fixture::refilter(State & state, b2Fixture * object){
		object->Refilter();
		return 1;
	}

	int Fixture::getFriction(State & state, b2Fixture * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetFriction()));
		return 1;
	}

	int Fixture::setFriction(State & state, b2Fixture * object){
		object->SetFriction(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int Fixture::getRestitution(State & state, b2Fixture * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetRestitution()));
		return 1;
	}

	int Fixture::setRestitution(State & state, b2Fixture * object){
		object->SetRestitution(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int Fixture::getDensity(State & state, b2Fixture * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetDensity()));
		return 1;
	}

	int Fixture::setDensity(State & state, b2Fixture * object){
		object->SetDensity(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
		return 0;
	}

	int Fixture::getAABB(State & state, b2Fixture * object){
		if (state.stack->is<LUA_TNUMBER>(1)){
			AABB * interfaceAABB = state.getInterface<AABB>("LuaBox2D_AABB");
			interfaceAABB->push(new b2AABB(object->GetAABB(
				static_cast<int32>(state.stack->to<int>(1))
				)), true);
			return 1;
		}else{
			return 0;
		}
	}

	int Fixture::testPoint(State & state, b2Fixture * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");

		b2Vec2 * p = interfaceVec2->get(1);
		if (p != nullptr){
			state.stack->push<bool>(object->TestPoint(
				*p
				));
			return 1;
		}else{
			return 0;
		}
	}

	int Fixture::rayCast(State & state, b2Fixture * object){
		RayCastInput * interfaceRayCastInput = state.getInterface<RayCastInput>("LuaBox2D_RayCastInput");
		RayCastOutput * interfaceRayCastOutput = state.getInterface<RayCastOutput>("LuaBox2D_RayCastOutput");

		b2RayCastInput * rayCastInput = interfaceRayCastInput->get(1);
		b2RayCastOutput * rayCastOutput = interfaceRayCastOutput->get(3);

		if (rayCastInput != nullptr && state.stack->is<LUA_TNUMBER>(2)){
			bool ownedOutput = false;
			if (rayCastOutput == nullptr){
				rayCastOutput = new b2RayCastOutput();
				ownedOutput = true;
			}
			bool result = object->RayCast(
				rayCastOutput,
				*rayCastInput,
				state.stack->to<int>(2));
			if (result){
				state.stack->push<bool>(true);
				interfaceRayCastOutput->push(rayCastOutput, ownedOutput);
				return 2;
			}else{
				if (ownedOutput){
					delete rayCastOutput;
				}
				state.stack->push<bool>(false);
				return 1;
			}
		}else{
			return 0;
		}
	}

	int Fixture::getMassData(State & state, b2Fixture * object){
		MassData * interfaceMassData = state.getInterface<MassData>("LuaBox2D_MassData");
		b2MassData * massData = nullptr;

		if (state.stack->is<LUA_TUSERDATA>(1)){
			massData = interfaceMassData->get(1);
			if (massData != nullptr){
				object->GetMassData(massData);
				interfaceMassData->push(massData, false);
				return 1;
			}else{
				return 0;
			}
		}else{
			massData = new b2MassData();
			object->GetMassData(massData);
			interfaceMassData->push(massData, true);
			return 1;
		}
	}

	int Fixture::getNext(State & state, b2Fixture * object){
		Fixture * interfaceFixture = state.getInterface<Fixture>("LuaBox2D_Fixture");
		b2Fixture * next = object->GetNext();
		if (next){
			interfaceFixture->push(next, false);
			return 1;
		}else{
			return 0;
		}
	}

	int Fixture::getUserData(State & state, b2Fixture * object){
		int ref = static_cast<int>(reinterpret_cast<intptr_t>(object->GetUserData()));
		if (ref != LUA_NOREF && ref != 0){
			state.stack->regValue(ref);
			return 1;
		}else{
			return 0;
		}
	}

	int Fixture::setUserData(State & state, b2Fixture * object){
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

};