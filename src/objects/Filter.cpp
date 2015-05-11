#include "common.hpp"
#include "objects/Filter.hpp"

namespace LuaBox2D {
	void initFilter(State * state){
		state->registerInterface<Filter>("LuaBox2D_Filter");

	}

	b2Filter * Filter::constructor(State & state, bool & managed){
		LUTOK2_NOT_USED(managed);
		return new b2Filter();
	}

	void Filter::destructor(State & state, b2Filter * object){
		delete object;
	}

	int Filter::getCategoryBits(State & state, b2Filter * object){
		state.stack->push<int>(static_cast<int>(object->categoryBits));
		return 1;
	}

	int Filter::setCategoryBits(State & state, b2Filter * object){
		object->categoryBits = static_cast<int16>(state.stack->to<int>(1));
		return 0;
	}

	int Filter::getMaskBits(State & state, b2Filter * object){
		state.stack->push<int>(static_cast<int>(object->maskBits));
		return 1;
	}

	int Filter::setMaskBits(State & state, b2Filter * object){
		object->maskBits = static_cast<int16>(state.stack->to<int>(1));
		return 0;
	}

	int Filter::getGroupIndex(State & state, b2Filter * object){
		state.stack->push<int>(static_cast<int>(object->groupIndex));
		return 1;
	}

	int Filter::setGroupIndex(State & state, b2Filter * object){
		object->groupIndex = static_cast<int16>(state.stack->to<int>(1));
		return 0;
	}
};
