#include "common.hpp"
#include "objects/ManifoldPoint.hpp"
#include "objects/ContactID.hpp"
#include "objects/Vec2.hpp"

namespace LuaBox2D {
	void initManifoldPoint(State * state){
		state->registerInterface<ManifoldPoint>("LuaBox2D_ManifoldPoint");
	}

	b2ManifoldPoint * ManifoldPoint::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		return new b2ManifoldPoint();
	}

	void ManifoldPoint::destructor(State & state, b2ManifoldPoint * object){
		delete object;
	}

	int ManifoldPoint::getLocalPoint(State & state, b2ManifoldPoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		interfaceVec2->push(&object->localPoint, false);
		return 1;
	}

	int ManifoldPoint::setLocalPoint(State & state, b2ManifoldPoint * object){
		Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
		b2Vec2 * point = interfaceVec2->get(1);
		if (point != nullptr){
			object->localPoint = *point;
		}
		return 0;
	}

	int ManifoldPoint::getNormalImpulse(State & state, b2ManifoldPoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->normalImpulse));
		return 1;
	}

	int ManifoldPoint::setNormalImpulse(State & state, b2ManifoldPoint * object){
		object->normalImpulse = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int ManifoldPoint::getTangentImpulse(State & state, b2ManifoldPoint * object){
		state.stack->push<LUA_NUMBER>(static_cast<LUA_NUMBER>(object->tangentImpulse));
		return 1;
	}

	int ManifoldPoint::setTangentImpulse(State & state, b2ManifoldPoint * object){
		object->tangentImpulse = static_cast<float32>(state.stack->to<LUA_NUMBER>(1));
		return 0;
	}

	int ManifoldPoint::getContactID(State & state, b2ManifoldPoint * object){
		ContactID * interfaceContactID = state.getInterface<ContactID>("LuaBox2D_ContactID");
		interfaceContactID->push(&object->id, false);
		return 1;
	}

	int ManifoldPoint::setContactID(State & state, b2ManifoldPoint * object){
		ContactID * interfaceContactID = state.getInterface<ContactID>("LuaBox2D_ContactID");
		b2ContactID * id = interfaceContactID->get(1);
		if (id != nullptr){
			object->id = *id;
		}
		return 0;
	}
};
