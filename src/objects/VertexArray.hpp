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

		b2VertexArray * constructor(State & state, const int index){
			b2VertexArray * object = new b2VertexArray();
			setVertices(state, object, index);
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
			Stack * stack = state.stack;
			if (stack->is<LUA_TNUMBER>(1)){
				b2VertexArray::size_type index = static_cast<b2VertexArray::size_type>(stack->to<int>(1) - 1);
				if (stack->is<LUA_TUSERDATA>(2)){
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
				}else if (stack->is<LUA_TTABLE>(2)){
					stack->getField(1, 2);
					float32 x = static_cast<float32>(stack->to<LUA_NUMBER>());

					stack->getField(2, 2);
					float32 y = static_cast<float32>(stack->to<LUA_NUMBER>());
					stack->pop(2);

					if (index >= 0 && index < object->size()){
						(*object)[index] = b2Vec2(x, y);
					}else if (index > object->size()){
						b2VertexArray::iterator iter = object->end();
						object->insert(iter, b2Vec2(x, y));
					}
				}
			}
		}

		int setVertices(State & state, b2VertexArray * object){
			return setVertices(state, object, 1);
		}

		int setVertices(State & state, b2VertexArray * object, const int index){
			Vec2 * interfaceVec2 = state.getInterface<Vec2>("LuaBox2D_Vec2");
			Stack * stack = state.stack;
			if (stack->is<LUA_TTABLE>(index)){
				int count = stack->objLen(index);
				object->clear();
				object->reserve(count);

				for (int index=0; index< count; index++){
					stack->getField(index+1, index);
					if (stack->is<LUA_TUSERDATA>()){
						b2Vec2 * vertex = interfaceVec2->get(-1);
						if (vertex != nullptr){
							object->push_back(*vertex);
						}
					}else if (stack->is<LUA_TTABLE>()){
						stack->getField(1, -2);
						float32 x = static_cast<float32>(stack->to<LUA_NUMBER>());

						stack->getField(2, -3);
						float32 y = static_cast<float32>(stack->to<LUA_NUMBER>());
						stack->pop(2);

						object->push_back(b2Vec2(x, y));
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
