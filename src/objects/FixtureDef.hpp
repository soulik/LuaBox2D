#ifndef LUABOX2D_FIXTUREDEF_H
#define LUABOX2D_FIXTUREDEF_H

#include "objects/Filter.hpp"

namespace LuaBox2D {
	class FixtureDef : public Object<b2FixtureDef> {
	public:
		explicit FixtureDef(State * state) : Object<b2FixtureDef>(state){
			LUTOK_PROPERTY("friction", &FixtureDef::getFriction, &FixtureDef::setFriction);
			LUTOK_PROPERTY("restitution", &FixtureDef::getRestitution, &FixtureDef::setRestitution);
			LUTOK_PROPERTY("density", &FixtureDef::getDensity, &FixtureDef::setDensity);
			LUTOK_PROPERTY("sensor", &FixtureDef::getSensor, &FixtureDef::setSensor);
			LUTOK_PROPERTY("filter", &FixtureDef::getFilter, &FixtureDef::setFilter);
		}

		b2FixtureDef * constructor(State & state){
			b2FixtureDef * obj = nullptr;
			obj = new b2FixtureDef();

			return obj;
		}
		void destructor(State & state, b2FixtureDef * object){
			delete object;
		}

		int getFriction(State & state, b2FixtureDef * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->friction));
			return 1;
		}

		int setFriction(State & state, b2FixtureDef * object){
			object->friction = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
			return 0;
		}

		int getRestitution(State & state, b2FixtureDef * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->restitution));
			return 1;
		}

		int setRestitution(State & state, b2FixtureDef * object){
			object->restitution = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
			return 0;
		}

		int getDensity(State & state, b2FixtureDef * object){
			state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->density));
			return 1;
		}

		int setDensity(State & state, b2FixtureDef * object){
			object->density = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
			return 0;
		}

		int getSensor(State & state, b2FixtureDef * object){
			state.stack->push<bool>(object->isSensor);
			return 1;
		}

		int setSensor(State & state, b2FixtureDef * object){
			object->isSensor = state.stack->to<bool>(1);
			return 0;
		}

		int getFilter(State & state, b2FixtureDef * object){
			Filter * interfaceFilter = dynamic_cast<Filter*>(state.interfaces["LuaBox2D_Filter"]);
			interfaceFilter->push(&object->filter, false);
			return 1;
		}

		int setFilter(State & state, b2FixtureDef * object){
			Filter * interfaceFilter = dynamic_cast<Filter*>(state.interfaces["LuaBox2D_Filter"]);
			b2Filter * filter = interfaceFilter->get(1);
			if (filter != nullptr){
				object->filter = *filter;
			}
			return 0;
		}
	};

	void initFixtureDef(State * );

};

#endif