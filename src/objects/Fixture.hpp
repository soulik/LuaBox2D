#ifndef LUABOX2D_FIXTURE_H
#define LUABOX2D_FIXTURE_H

#include "objects/Shape.hpp"
#include "objects/Body.hpp"
#include "objects/AABB.hpp"
#include "objects/RayCastInput.hpp"
#include "objects/RayCastOutput.hpp"
#include "objects/MassData.hpp"
#include "objects/Filter.hpp"

namespace LuaBox2D {
	class Fixture : public Object<b2Fixture> {
	public:
		explicit Fixture(State * state) : Object<b2Fixture>(state){
			LUTOK_PROPERTY("type", &Fixture::getType, &Fixture::nullMethod);
			LUTOK_PROPERTY("shape", &Fixture::getShape, &Fixture::nullMethod);
			LUTOK_PROPERTY("sensor", &Fixture::getSensor, &Fixture::setSensor);
			LUTOK_PROPERTY("filter", &Fixture::getFilter, &Fixture::setFilter);
			LUTOK_PROPERTY("body", &Fixture::getBody, &Fixture::nullMethod);
			LUTOK_PROPERTY("friction", &Fixture::getFriction, &Fixture::setFriction);
			LUTOK_PROPERTY("restitution", &Fixture::getRestitution, &Fixture::setRestitution);
			LUTOK_PROPERTY("density", &Fixture::getDensity, &Fixture::setDensity);
			LUTOK_PROPERTY("AABB", &Fixture::getAABB, &Fixture::nullMethod);
			LUTOK_PROPERTY("massData", &Fixture::getMassData, &Fixture::nullMethod);

			LUTOK_METHOD("refilter", &Fixture::refilter);
			LUTOK_METHOD("testPoint", &Fixture::testPoint);
			LUTOK_METHOD("rayCast", &Fixture::rayCast);
		}

		b2Fixture * constructor(State & state){
			return nullptr;
		}

		void destructor(State & state, b2Fixture * object){
			object->GetBody()->DestroyFixture(object);
		}

		int getType(State & state, b2Fixture * object){
			state.stack->push<int>(static_cast<int>(object->GetType()));
			return 1;
		}

		int getShape(State & state, b2Fixture * object){
			Shape * interfaceShape = state.getInterface<Shape>("LuaBox2D_Shape");
			interfaceShape->push(object->GetShape(), false);
			return 1;
		}

		int getSensor(State & state, b2Fixture * object){
			state.stack->push<bool>(object->IsSensor());
			return 1;
		}

		int setSensor(State & state, b2Fixture * object){
			object->SetSensor(state.stack->to<bool>(1));
			return 0;
		}

		int getFilter(State & state, b2Fixture * object){
			Filter * interfaceFilter = dynamic_cast<Filter*>(state.interfaces["LuaBox2D_Filter"]);
			interfaceFilter->push(new b2Filter(object->GetFilterData()), true);
			return 1;
		}

		int setFilter(State & state, b2Fixture * object){
			Filter * interfaceFilter = dynamic_cast<Filter*>(state.interfaces["LuaBox2D_Filter"]);
			b2Filter * filter = interfaceFilter->get(1);
			if (filter != nullptr){
				object->SetFilterData(*filter);
			}
			return 0;
		}

		int refilter(State & state, b2Fixture * object){
			object->Refilter();
			return 1;
		}

		int getBody(State & state, b2Fixture * object);

		int getFriction(State & state, b2Fixture * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetFriction()));
			return 1;
		}

		int setFriction(State & state, b2Fixture * object){
			object->SetFriction(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
			return 0;
		}

		int getRestitution(State & state, b2Fixture * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetRestitution()));
			return 1;
		}

		int setRestitution(State & state, b2Fixture * object){
			object->SetRestitution(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
			return 0;
		}

		int getDensity(State & state, b2Fixture * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->GetDensity()));
			return 1;
		}

		int setDensity(State & state, b2Fixture * object){
			object->SetDensity(static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
			return 0;
		}

		int getAABB(State & state, b2Fixture * object){
			if (state.stack->is<LUA_TNUMBER>(1)){
				AABB * interfaceAABB = dynamic_cast<AABB*>(state.interfaces["LuaBox2D_AABB"]);
				interfaceAABB->push(new b2AABB(object->GetAABB(
					static_cast<int32>(state.stack->to<int>(1))
					)), true);
				return 1;
			}else{
				return 0;
			}
		}

		int testPoint(State & state, b2Fixture * object){
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

		int rayCast(State & state, b2Fixture * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
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

		int getMassData(State & state, b2Fixture * object){
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


	};

	void initFixture(State * );
};

#endif