#ifndef LUABOX2D_MASSDATA_H
#define LUABOX2D_MASSDATA_H

#include "objects/Vec2.hpp"

namespace LuaBox2D {
	class MassData : public Object<b2MassData> {
	public:
		explicit MassData(State * state) : Object<b2MassData>(state){
			LUTOK_PROPERTY("center", &MassData::getCenter, &MassData::setCenter);
			LUTOK_PROPERTY("mass", &MassData::getMass, &MassData::setMass);
			LUTOK_PROPERTY("I", &MassData::getI, &MassData::setI);
		}

		b2MassData * constructor(State & state){
			b2MassData * object = new b2MassData();
			return object;
		}

		void destructor(State & state, b2MassData * object){
			delete object;
		}

		int getCenter(State & state, b2MassData * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			interfaceVec2->push(&object->center, false);
			return 1;
		}

		int setCenter(State & state, b2MassData * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			b2Vec2 * bound = interfaceVec2->get(1);
			if (bound != nullptr){
				object->center = *bound;
			}
			return 0;
		}

		int getMass(State & state, b2MassData * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->mass));
			return 1;
		}

		int setMass(State & state, b2MassData * object){
			object->mass = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
			return 0;
		}

		int getI(State & state, b2MassData * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->I));
			return 1;
		}

		int setI(State & state, b2MassData * object){
			object->I = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
			return 0;
		}
	};

	void initMassData(State * );
};

#endif	
