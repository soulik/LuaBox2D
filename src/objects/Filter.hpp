#ifndef LUABOX2D_FILTER_H
#define LUABOX2D_FILTER_H

namespace LuaBox2D {
	class Filter : public Object<b2Filter> {
	public:
		explicit Filter(State * state) : Object<b2Filter>(state){
			LUTOK_PROPERTY("categoryBits", &Filter::getCategoryBits, &Filter::setCategoryBits);
			LUTOK_PROPERTY("maskBits", &Filter::getMaskBits, &Filter::setMaskBits);
			LUTOK_PROPERTY("groupIndex", &Filter::getGroupIndex, &Filter::setGroupIndex);
		}

		b2Filter * constructor(State & state){
			return new b2Filter();
		}

		void destructor(State & state, b2Filter * object){
			delete object;
		}

		int getCategoryBits(State & state, b2Filter * object){
			state.stack->push<int>(static_cast<int>(object->categoryBits));
			return 1;
		}

		int setCategoryBits(State & state, b2Filter * object){
			object->categoryBits = static_cast<int16>(state.stack->to<int>(1));
			return 0;
		}

		int getMaskBits(State & state, b2Filter * object){
			state.stack->push<int>(static_cast<int>(object->maskBits));
			return 1;
		}

		int setMaskBits(State & state, b2Filter * object){
			object->maskBits = static_cast<int16>(state.stack->to<int>(1));
			return 0;
		}

		int getGroupIndex(State & state, b2Filter * object){
			state.stack->push<int>(static_cast<int>(object->groupIndex));
			return 1;
		}

		int setGroupIndex(State & state, b2Filter * object){
			object->groupIndex = static_cast<int16>(state.stack->to<int>(1));
			return 0;
		}
	};

	void initFilter(State * );
};

#endif	
