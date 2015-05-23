cmake_minimum_required (VERSION 2.6)
project (LuaBox2D)

# Include Lua 5.1

include(FindLua51)
include_directories(SYSTEM ${LUA_INCLUDE_DIR})
include_directories(dependencies/lua/include)

# Setup Box2D

set(BOX2D_INSTALL_BY_DEFAULT OFF CACHE BOOL "Install Box2D library")
set(BOX2D_BUILD_STATIC ON CACHE BOOL "Build Box2D static library")
set(BOX2D_BUILD_EXAMPLES OFF CACHE BOOL "Build Box2D examples")

add_subdirectory(dependencies/Box2D/Box2D)
include_directories(dependencies/Box2D/Box2D)

set_target_properties(Box2D
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

include_directories(dependencies/lutok2/include)

add_subdirectory(src)

set_target_properties(LuaBox2D PROPERTIES PREFIX "")
