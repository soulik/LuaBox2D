#include "common.hpp"
#include "objects/Vec2.hpp"
#include "objects/Transform.hpp"
#include "objects/RayCastInput.hpp"
#include "objects/RayCastOutput.hpp"
#include "objects/AABB.hpp"
#include "objects/MassData.hpp"
#include "objects/Shape.hpp"
#include "objects/CircleShape.hpp"
#include "objects/ChainShape.hpp"
#include "objects/EdgeShape.hpp"
#include "objects/PolygonShape.hpp"

namespace LuaBox2D {
	void initShape(State * state){
		state->registerInterface<Shape>("LuaBox2D_Shape");
	}

	void Shape::initAllowedTypes(){
		ADD_VALID_TYPE(b2Shape);
		ADD_VALID_TYPE(b2CircleShape);
		ADD_VALID_TYPE(b2ChainShape);
		ADD_VALID_TYPE(b2EdgeShape);
		ADD_VALID_TYPE(b2PolygonShape);
	}

	b2Shape * Shape::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		b2Shape *obj = get(1);
		if (obj != nullptr){
			return obj;
		}else{
			return nullptr;
		}
	}

	void Shape::destructor(State & state, b2Shape * object){
		delete object;
	}

	b2Shape * Shape::get(const int index){
		ObjWrapper * wrapper = getWrapped(index, validTypes);
		if (wrapper){
			return wrapper->instance;
		}else{

			return nullptr;
		}
	}

	int Shape::getType(State & state, b2Shape * object){
		state.stack->push<int>(static_cast<int>(object->GetType()));
		return 1;
	}

	int Shape::getRadius(State & state, b2Shape * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->m_radius));
		return 1;
	}

	int Shape::setRadius(State & state, b2Shape * object){
		object->m_radius = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int Shape::operator_len(State & state, b2Shape * object){
		state.stack->push<int>(static_cast<int>(object->GetChildCount()));
		return 1;
	}

	int Shape::testPoint(State & state, b2Shape * object){
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

	int Shape::rayCast(State & state, b2Shape * object){
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

	int Shape::computeAABB(State & state, b2Shape * object){
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

	int Shape::computeMass(State & state, b2Shape * object){
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