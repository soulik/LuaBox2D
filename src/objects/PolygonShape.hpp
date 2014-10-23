#ifndef LUABOX2D_POLYGONSHAPE_H
#define LUABOX2D_POLYGONSHAPE_H

namespace LuaBox2D {
	class PolygonShape : public Object<b2PolygonShape> {
	public:
		explicit PolygonShape(State * state) : Object<b2PolygonShape>(state){
		}

		b2PolygonShape * constructor(State & state){
			return nullptr;
		}

		void destructor(State & state, b2PolygonShape * object){
			delete object;
		}
	};

	void initPolygonShape(State * );
};

#endif	
