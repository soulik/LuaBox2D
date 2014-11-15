#ifndef LUABOX2D_ARRAY_H
#define LUABOX2D_ARRAY_H

#include <cstdlib>

namespace LuaBox2D {

	template <class C>
	class Array {
	private:
		C ** usedArray;
		size_t size;
	public:
		Array(){
			usedArray = nullptr;
			size = 0;
		}

		Array(const Array & other){
			usedArray = other.usedArray;
			size = other.size;
		}

		Array(const C ** arrayPtr, size_t arraySize = 0){
			set(arrayPtr, size);
		}

		size_t getSize(){
			return size;
		}

		void set(const C ** arrayPtr, size_t arraySize = 0){
			usedArray = arrayPtr;
			size = arraySize;
		}

		void add(C * element){
			size++;
			usedArray = static_cast<C **>(std::realloc(usedArray, sizeof(C*) * size));
			(*usedArray)[size-1] = *element;
		}

		C & operator[](size_t index){
			if (index>=0 && index<size){
				return (*usedArray)[index];
			}else{
				throw std::exception("Invalid index");
			}
		}
	
	};

};

#endif