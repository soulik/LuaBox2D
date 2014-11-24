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

		b2Filter * constructor(State & state, bool & managed);

		void destructor(State & state, b2Filter * object);

		int getCategoryBits(State & state, b2Filter * object);

		int setCategoryBits(State & state, b2Filter * object);

		int getMaskBits(State & state, b2Filter * object);

		int setMaskBits(State & state, b2Filter * object);

		int getGroupIndex(State & state, b2Filter * object);

		int setGroupIndex(State & state, b2Filter * object);
	};

	void initFilter(State * );
};

#endif	
