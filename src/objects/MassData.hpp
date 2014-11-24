#ifndef LUABOX2D_MASSDATA_H
#define LUABOX2D_MASSDATA_H

namespace LuaBox2D {
	class MassData : public Object<b2MassData> {
	public:
		explicit MassData(State * state) : Object<b2MassData>(state){
			LUTOK_PROPERTY("center", &MassData::getCenter, &MassData::setCenter);
			LUTOK_PROPERTY("mass", &MassData::getMass, &MassData::setMass);
			LUTOK_PROPERTY("I", &MassData::getI, &MassData::setI);
		}

		b2MassData * constructor(State & state, bool & managed);

		void destructor(State & state, b2MassData * object);

		int getCenter(State & state, b2MassData * object);

		int setCenter(State & state, b2MassData * object);

		int getMass(State & state, b2MassData * object);

		int setMass(State & state, b2MassData * object);

		int getI(State & state, b2MassData * object);

		int setI(State & state, b2MassData * object);
	};

	void initMassData(State * );
};

#endif	
