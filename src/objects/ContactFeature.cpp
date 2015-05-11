#include "common.hpp"
#include "objects/ContactFeature.hpp"

namespace LuaBox2D {
	void initContactFeature(State * state){
		state->registerInterface<ContactFeature>("LuaBox2D_ContactFeature");
	}

	b2ContactFeature * ContactFeature::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		return new b2ContactFeature();
	}

	void ContactFeature::destructor(State & state, b2ContactFeature * object){
		delete object;
	}


	int ContactFeature::getIndexA(State & state, b2ContactFeature * object){
		state.stack->push<int>(static_cast<int>(object->indexA));
		return 1;
	}

	int ContactFeature::setIndexA(State & state, b2ContactFeature * object){
		object->indexA = static_cast<uint8>(state.stack->to<int>(1));
		return 0;
	}

	int ContactFeature::getIndexB(State & state, b2ContactFeature * object){
		state.stack->push<int>(static_cast<int>(object->indexB));
		return 1;
	}

	int ContactFeature::setIndexB(State & state, b2ContactFeature * object){
		object->indexB = static_cast<uint8>(state.stack->to<int>(1));
		return 0;
	}

	int ContactFeature::getTypeA(State & state, b2ContactFeature * object){
		state.stack->push<int>(static_cast<int>(object->typeA));
		return 1;
	}

	int ContactFeature::setTypeA(State & state, b2ContactFeature * object){
		object->typeA = static_cast<b2ContactFeature::Type>(state.stack->to<int>(1));
		return 0;
	}

	int ContactFeature::getTypeB(State & state, b2ContactFeature * object){
		state.stack->push<int>(static_cast<int>(object->typeB));
		return 1;
	}

	int ContactFeature::setTypeB(State & state, b2ContactFeature * object){
		object->typeB = static_cast<b2ContactFeature::Type>(state.stack->to<int>(1));
		return 0;
	}
};
