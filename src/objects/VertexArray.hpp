#ifndef LUABOX2D_VERTEXARRAY_H
#define LUABOX2D_VERTEXARRAY_H

#include <vector>
#include "objects/Vec2.hpp"

namespace LuaBox2D {
	typedef std::vector<b2Vec2> b2VertexArray;

	class VertexArray : public Object<b2VertexArray> {
	public:
		explicit VertexArray(State * state) : Object<b2VertexArray>(state){
			LUTOK_PROPERTY("vertices", &VertexArray::nullMethod, &VertexArray::setVertices);
		}

		b2VertexArray * constructor(State & state){
			b2VertexArray * object = new b2VertexArray();
			setVertices(state, object);
			return object;
		}

		void destructor(State & state, b2VertexArray * object){
			delete object;
		}

		int operator_len(State & state, b2VertexArray * object){
			state.stack->push<int>(object->size());
			return 1;
		}

		int operator_concat(State & state, b2VertexArray * a, b2VertexArray * b){
			VertexArray * interfaceVertexArray = state.getInterface<VertexArray>("LuaBox2D_VertexArray");
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			if (b == nullptr){
				b2Vec2 * vertex = interfaceVec2->get(2);
				if (vertex != nullptr){
					a->push_back(*vertex);
				}
			}

			interfaceVertexArray->push(a, false);
			return 1;
		}

		int operator_getArray(State & state, b2VertexArray * object){
			if (state.stack->is<LUA_TNUMBER>(1)){
				b2VertexArray::size_type index = static_cast<b2VertexArray::size_type>(state.stack->to<int>(1) - 1);
				if (index >= 0 && index < object->size()){
					Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
					interfaceVec2->push(& (*object)[index], false);
					return 1;
				}else{
					return 0;
				}
			}else{
				return 0;
			}
		}

		void operator_setArray(State & state, b2VertexArray * object){
			if (state.stack->is<LUA_TNUMBER>(1) && state.stack->is<LUA_TUSERDATA>(2)){
				b2VertexArray::size_type index = static_cast<b2VertexArray::size_type>(state.stack->to<int>(1) - 1);
				Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
				b2Vec2 * vertex = interfaceVec2->get(2);

				if (vertex != nullptr){
					if (index >= 0 && index < object->size()){
						(*object)[index] = *vertex;
					}else if (index > object->size()){
						b2VertexArray::iterator iter = object->end();
						object->insert(iter, *vertex);
					}
				}
			}
		}

		int setVertices(State & state, b2VertexArray * object){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			Stack * stack = state.stack;
			if (stack->is<LUA_TTABLE>(1)){
				int count = stack->objLen(1);
				object->clear();
				object->reserve(count);

				for (int index=0; index< count; index++){
					stack->push<int>(index+1);
					stack->getTable(1);
					b2Vec2 * vertex = interfaceVec2->get(-1);
					if (vertex != nullptr){
						object->push_back(*vertex);
					}
					stack->pop(1);
				}
			}
			return 0;
		}
	};

	void initVertexArray(State * );
};

#endif	
