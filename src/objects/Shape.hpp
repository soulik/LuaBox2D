#ifndef LUABOX2D_SHAPE_H
#define LUABOX2D_SHAPE_H

#include "objects/Vec2.hpp"
#include "objects/Transform.hpp"
#include "objects/RayCastInput.hpp"
#include "objects/RayCastOutput.hpp"

namespace LuaBox2D {
	class Shape : public Object<b2Shape> {
	public:
		explicit Shape(State * state) : Object<b2Shape>(state){
			LUTOK_PROPERTY("type", &Shape::getType, &Shape::nullMethod);
			LUTOK_METHOD("testPoint", &Shape::testPoint);
			LUTOK_METHOD("rayCast", &Shape::rayCast);
			LUTOK_METHOD("computeAABB", &Shape::computeAABB);
			LUTOK_METHOD("computeMass", &Shape::computeMass);
		}

		b2Shape * constructor(State & state){
			b2Shape * obj = nullptr;
			

			//obj = new b2Shape();

			return obj;
		}
		void destructor(State & state, b2Shape * object){
			delete object;
		}

		int getType(State & state, b2Shape * object){
			state.stack->push<int>(static_cast<int>(object->GetType()));
			return 1;
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
					state.stack->push<bool>(false);
					return 1;
				}
			}else{
				return 0;
			}
		}

		//TODO
		int computeAABB(State & state, b2Shape * object){
			return 0;
		}

		//TODO
		int computeMass(State & state, b2Shape * object){
			return 0;
		}
	};

	void initShape(State * );

};

#endif