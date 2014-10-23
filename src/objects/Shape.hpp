#ifndef LUABOX2D_SHAPE_H
#define LUABOX2D_SHAPE_H

#include "objects/Vec2.hpp"
#include "objects/Transform.hpp"
#include "objects/RayCastInput.hpp"
#include "objects/RayCastOutput.hpp"
#include "objects/AABB.hpp"
#include "objects/MassData.hpp"
/*
#include "objects/CircleShape.hpp"
#include "objects/ChainShape.hpp"
#include "objects/EdgeShape.hpp"
#include "objects/PolygonShape.hpp"
*/
namespace LuaBox2D {
	class Shape : public Object<b2Shape> {
	protected:
		std::forward_list<std::string> validTypes;
	public:
		explicit Shape(State * state) : Object<b2Shape>(state){
			LUTOK_PROPERTY("type", &Shape::getType, &Shape::nullMethod);
			LUTOK_PROPERTY("radius", &Shape::getRadius, &Shape::setRadius);

			LUTOK_METHOD("testPoint", &Shape::testPoint);
			LUTOK_METHOD("rayCast", &Shape::rayCast);
			LUTOK_METHOD("computeAABB", &Shape::computeAABB);
			LUTOK_METHOD("computeMass", &Shape::computeMass);

			validTypes.push_front("Shape");
			validTypes.push_front("CircleShape");
			validTypes.push_front("ChainShape");
			validTypes.push_front("EdgeShape");
			validTypes.push_front("PolygonShape");
		}

		b2Shape * constructor(State & state);

		void destructor(State & state, b2Shape * object){
			delete object;
		}

		b2Shape * get(const int index){
			ObjWrapper * wrapper = getWrapped(index, validTypes);
			if (wrapper){
				return wrapper->instance;
			}else{

				return nullptr;
			}
		}

		int getType(State & state, b2Shape * object){
			state.stack->push<int>(static_cast<int>(object->GetType()));
			return 1;
		}

		int getRadius(State & state, b2Shape * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->m_radius));
			return 1;
		}

		int setRadius(State & state, b2Shape * object){
			object->m_radius = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
			return 0;
		}

		int operator_len(State & state, b2Shape * object){
			state.stack->push<int>(static_cast<int>(object->GetChildCount()));
			return 1;
		}

		int testPoint(State & state, b2Shape * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			Transform * interfaceTransform = state.getInterface<Transform>("LuaBox2D_Transform");
			
			b2Transform * xf = interfaceTransform->get(1);
			b2Vec2 * p = interfaceVec2->get(2);
			if (xf != nullptr && p != nullptr){
				state.stack->push<bool>(object->TestPoint(
					*xf, *p
					));
				return 1;
			}else{
				return 0;
			}
		}

		int rayCast(State & state, b2Shape * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			RayCastInput * interfaceRayCastInput = state.getInterface<RayCastInput>("LuaBox2D_RayCastInput");
			RayCastOutput * interfaceRayCastOutput = state.getInterface<RayCastOutput>("LuaBox2D_RayCastOutput");
			Transform * interfaceTransform = state.getInterface<Transform>("LuaBox2D_Transform");

			b2RayCastInput * rayCastInput = interfaceRayCastInput->get(1);
			b2RayCastOutput * rayCastOutput = interfaceRayCastOutput->get(4);
			b2Transform * transform = interfaceTransform->get(2);

			if (rayCastInput != nullptr && transform != nullptr && state.stack->is<LUA_TNUMBER>(3)){
				bool ownedOutput = false;
				if (rayCastOutput == nullptr){
					rayCastOutput = new b2RayCastOutput();
					ownedOutput = true;
				}
				bool result = object->RayCast(
						rayCastOutput,
						*rayCastInput,
						*transform,
						state.stack->to<int>(3));
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

		int computeAABB(State & state, b2Shape * object){
			AABB * interfaceAABB = state.getInterface<AABB>("LuaBox2D_AABB");
			Transform * interfaceTransform = state.getInterface<Transform>("LuaBox2D_Transform");
			b2AABB * result = nullptr;
			b2Transform * transform = interfaceTransform->get(1);
			if (transform != nullptr && state.stack->is<LUA_TNUMBER>(2)){
				result = new b2AABB();
				object->ComputeAABB(result, *transform, static_cast<int32>(state.stack->to<int>(2)));
				interfaceAABB->push(result, true);
				return 1;
			}
			return 0;
		}

		int computeMass(State & state, b2Shape * object){
			MassData * interfaceMassData = state.getInterface<MassData>("LuaBox2D_MassData");
			b2MassData * massData = nullptr;

			if (state.stack->is<LUA_TNUMBER>(1)){
				massData = new b2MassData();
				object->ComputeMass(massData, static_cast<float32>(state.stack->to<LUA_NUMBER>(1)));
				interfaceMassData->push(massData, true);
				return 1;
			}else if (state.stack->is<LUA_TUSERDATA>(1) && state.stack->is<LUA_TNUMBER>(2)){
				massData = interfaceMassData->get(1);
				if (massData != nullptr){
					object->ComputeMass(massData, static_cast<float32>(state.stack->to<LUA_NUMBER>(2)));
					interfaceMassData->push(massData, false);
					return 1;
				}else{
					return 0;
				}
			}else{
				return 0;
			}
		}
	};

	void initShape(State * );

};

#endif