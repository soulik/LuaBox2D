#ifndef LUABOX2D_COMMON_H
#define LUABOX2D_COMMON_H

#include <Box2D/Box2D.h>
#include <lutok2/lutok2.hpp>

using namespace lutok2;
/*
#define ADD_VALID_TYPE(NAME)	validTypes.push_front("class lutok2::Object<class b2" #NAME "> *")
#define ADD_VALID_STRUCT(NAME)	validTypes.push_front("class lutok2::Object<struct b2" #NAME "> *")
*/
#define ADD_VALID_TYPE(C)	validTypes.push_front(typeid(C).name())
#define ADD_VALID_STRUCT(C)	validTypes.push_front(typeid(C).name())

#if (BUILDING_LIBLUABOX2D || LuaBox2D_EXPORTS) && HAVE_VISIBILITY
#define LIBLUABOX2D_DLL_EXPORTED __attribute__((visibility("default")))
#elif (BUILDING_LIBLUABOX2D || LuaBox2D_EXPORTS) && defined _MSC_VER
#define LIBLUABOX2D_DLL_EXPORTED __declspec(dllexport)
#elif defined _MSC_VER
#define LIBLUABOX2D_DLL_EXPORTED __declspec(dllimport)
#else
#define LIBLUABOX2D_DLL_EXPORTED
#endif

#endif