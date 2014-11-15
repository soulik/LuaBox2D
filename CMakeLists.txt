cmake_minimum_required (VERSION 2.6)
project (LuaBox2D)

include(FindLua51.cmake)

set(BOX2D_INSTALL_BY_DEFAULT OFF CACHE BOOL "Install Box2D library")
set(BOX2D_BUILD_STATIC ON CACHE BOOL "Build Box2D static library")
set(BOX2D_BUILD_EXAMPLES OFF CACHE BOOL "Build Box2D examples")

add_subdirectory(dependencies/Box2D/Box2D)

include_directories(dependencies/lutok2/include)
add_subdirectory(src)

set(LuaBox2D_libs
	Box2D
	${LUA_LIBRARIES}
)

target_link_libraries (LuaBox2D ${LuaBox2D_libs})

