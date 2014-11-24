#ifndef LUABOX2D_VERTEXARRAY_H
#define LUABOX2D_VERTEXARRAY_H

namespace LuaBox2D {
	typedef std::vector<b2Vec2> b2VertexArray;

	class VertexArray : public Object<b2VertexArray> {
	public:
		explicit VertexArray(State * state) : Object<b2VertexArray>(state){
			LUTOK_PROPERTY("vertices", &VertexArray::nullMethod, &VertexArray::setVertices);
		}

		b2VertexArray * constructor(State & state, bool & managed);

		b2VertexArray * constructor(State & state, const int index);

		b2VertexArray * constructor(State & state, b2Vec2 * array, b2VertexArray::size_type size);

		void destructor(State & state, b2VertexArray * object){
			LUTOK2_NOT_USED(state);
			delete object;
		}

		int operator_len(State & state, b2VertexArray * object);

		int operator_concat(State & state, b2VertexArray * a, b2VertexArray * b);

		int operator_getArray(State & state, b2VertexArray * object);

		void operator_setArray(State & state, b2VertexArray * object);

		int setVertices(State & state, b2VertexArray * object);

		int setVertices(State & state, b2VertexArray * object, const int tableIndex);
	};

	void initVertexArray(State * );
};

#endif	
