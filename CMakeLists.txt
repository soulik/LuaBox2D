cmake_minimum_required (VERSION 2.6)
project (LuaBox2D)

include(CheckCXXCompilerFlag)
CHECK_CXX_COMPILER_FLAG("-std=c++11" COMPILER_SUPPORTS_CXX11)
CHECK_CXX_COMPILER_FLAG("-std=c++0x" COMPILER_SUPPORTS_CXX0X)
if(COMPILER_SUPPORTS_CXX11)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
elseif(COMPILER_SUPPORTS_CXX0X)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++0x")
else()
    message(STATUS "The compiler ${CMAKE_CXX_COMPILER} has no C++11 support. Please use a different C++ compiler.")
endif()

include(FindLua51)
include_directories(SYSTEM ${LUA_INCLUDE_DIR})
include_directories(dependencies/lua/include)

set(BOX2D_INSTALL_BY_DEFAULT OFF CACHE BOOL "Install Box2D library")
set(BOX2D_BUILD_STATIC ON CACHE BOOL "Build Box2D static library")
set(BOX2D_BUILD_EXAMPLES OFF CACHE BOOL "Build Box2D examples")

add_subdirectory(dependencies/Box2D/Box2D)
include_directories(dependencies/Box2D/Box2D)

include_directories(dependencies/lutok2/include)
add_subdirectory(src)

set(LuaBox2D_libs
	#Box2D
	${LUA_LIBRARIES}
)

#target_link_libraries (LuaBox2D ${LuaBox2D_libs})

