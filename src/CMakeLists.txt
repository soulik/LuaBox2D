set(LuaBox2D_src
	main.cpp
)

set(LuaBox2D_objects_src
	objects/AABB.cpp
	objects/Body.cpp
	objects/BodyDef.cpp
	objects/Filter.cpp
	objects/Fixture.cpp
	objects/FixtureDef.cpp
	objects/Manifold.cpp
	objects/ManifoldPoint.cpp
	objects/MassData.cpp
	objects/RayCastInput.cpp
	objects/RayCastOutput.cpp
	objects/Rot.cpp
	objects/Sweep.cpp
	objects/Timer.cpp
	objects/Transform.cpp
	objects/Vec2.cpp
	objects/VertexArray.cpp
	objects/World.cpp
	objects/WorldManifold.cpp
)

set(LuaBox2D_objects_contacts_src
	objects/Contact.cpp
	objects/ContactEdge.cpp
	objects/ContactFeature.cpp
	objects/ContactFilter.cpp
	objects/ContactID.cpp
	objects/ContactImpulse.cpp
	objects/ContactListener.cpp
	objects/ContactManager.cpp
	objects/QueryCallback.cpp
	objects/RayCastCallback.cpp
)

set(LuaBox2D_objects_joints_src
	objects/DistanceJoint.cpp
	objects/FrictionJoint.cpp
	objects/GearJoint.cpp
	objects/Joint.cpp
	objects/JointEdge.cpp
	objects/MotorJoint.cpp
	objects/MouseJoint.cpp
	objects/PrismaticJoint.cpp
	objects/PulleyJoint.cpp
	objects/RevoluteJoint.cpp
	objects/RopeJoint.cpp
	objects/WeldJoint.cpp
	objects/WheelJoint.cpp
)

set(LuaBox2D_objects_joints_defs_src
	objects/DistanceJointDef.cpp
	objects/FrictionJointDef.cpp
	objects/GearJointDef.cpp
	objects/JointDef.cpp
	objects/MotorJointDef.cpp
	objects/MouseJointDef.cpp
	objects/PrismaticJointDef.cpp
	objects/PulleyJointDef.cpp
	objects/RevoluteJointDef.cpp
	objects/RopeJointDef.cpp
	objects/WeldJointDef.cpp
	objects/WheelJointDef.cpp
)

set(LuaBox2D_objects_shapes_src
	objects/ChainShape.cpp
	objects/CircleShape.cpp
	objects/EdgeShape.cpp
	objects/PolygonShape.cpp
	objects/Shape.cpp
)

set(LuaBox2D_hdr
	common.hpp
	main.hpp
	array.hpp
)

set(LuaBox2D_objects_hdr
	objects/AABB.hpp
	objects/Body.hpp
	objects/BodyDef.hpp
	objects/Filter.hpp
	objects/Fixture.hpp
	objects/FixtureDef.hpp
	objects/Manifold.hpp
	objects/ManifoldPoint.hpp
	objects/MassData.hpp
	objects/RayCastInput.hpp
	objects/RayCastOutput.hpp
	objects/Rot.hpp
	objects/Sweep.hpp
	objects/Timer.hpp
	objects/Transform.hpp
	objects/Vec2.hpp
	objects/VertexArray.hpp
	objects/World.hpp
	objects/WorldManifold.hpp
)

set(LuaBox2D_objects_contacts_hdr
	objects/Contact.hpp
	objects/ContactEdge.hpp
	objects/ContactFeature.hpp
	objects/ContactFilter.hpp
	objects/ContactID.hpp
	objects/ContactImpulse.hpp
	objects/ContactListener.hpp
	objects/ContactManager.hpp
	objects/QueryCallback.hpp
	objects/RayCastCallback.hpp
)

set(LuaBox2D_objects_joints_hdr
	objects/DistanceJoint.hpp
	objects/FrictionJoint.hpp
	objects/GearJoint.hpp
	objects/Joint.hpp
	objects/JointEdge.hpp
	objects/MotorJoint.hpp
	objects/MouseJoint.hpp
	objects/PrismaticJoint.hpp
	objects/PulleyJoint.hpp
	objects/RevoluteJoint.hpp
	objects/RopeJoint.hpp
	objects/WeldJoint.hpp
	objects/WheelJoint.hpp
)

set(LuaBox2D_objects_joints_defs_hdr
	objects/DistanceJointDef.hpp
	objects/FrictionJointDef.hpp
	objects/GearJointDef.hpp
	objects/JointDef.hpp
	objects/MotorJointDef.hpp
	objects/MouseJointDef.hpp
	objects/PrismaticJointDef.hpp
	objects/PulleyJointDef.hpp
	objects/RevoluteJointDef.hpp
	objects/RopeJointDef.hpp
	objects/WeldJointDef.hpp
	objects/WheelJointDef.hpp
)

set(LuaBox2D_objects_shapes_hdr
	objects/ChainShape.hpp
	objects/CircleShape.hpp
	objects/EdgeShape.hpp
	objects/PolygonShape.hpp
	objects/Shape.hpp
)

source_group(objects FILES ${LuaBox2D_objects_src} ${LuaBox2D_object_hdr})
source_group(objects\\contacts FILES ${LuaBox2D_objects_contacts_src} ${LuaBox2D_object_contacts_hdr})
source_group(objects\\joints FILES ${LuaBox2D_objects_joints_src} ${LuaBox2D_object_joints_hdr})
source_group(objects\\joints\\defs FILES ${LuaBox2D_objects_joints_defs_src} ${LuaBox2D_object_joints_defs_hdr})
source_group(objects\\shapes FILES ${LuaBox2D_objects_shapes_src} ${LuaBox2D_object_shapes_hdr})

set(LuaBox2D_sources
	${LuaBox2D_src}
	${LuaBox2D_objects_src}
	${LuaBox2D_objects_contacts_src}
	${LuaBox2D_objects_joints_src}
	${LuaBox2D_objects_joints_defs_src}
	${LuaBox2D_objects_shapes_src}
)

include_directories(objects)
include_directories(./)

# Setup C++ flags
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


set(LuaBox2D_version_script LuaBox2D.version)

IF(UNIX)
    IF(CMAKE_COMPILER_IS_GNUCC)
         SET(CMAKE_SHARED_LINKER_FLAGS  "${CMAKE_SHARED_LINKER_FLAGS} ${CMAKE_CXX_COMPILE_OPTIONS_VISIBILITY}hidden -Wl,--version-script=${CMAKE_CURRENT_SOURCE_DIR}/${LuaBox2D_version_script}")
    ENDIF(CMAKE_COMPILER_IS_GNUCC)

    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wmissing-declarations")
ENDIF(UNIX)

add_definitions(-DBUILDING_LIBLUABOX2D)

add_library(LuaBox2D SHARED
	${LuaBox2D_sources}
)

set_target_properties(LuaBox2D
    PROPERTIES
    ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/lib"
    RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin"
)

target_link_libraries (LuaBox2D
	Box2D
	${LUA_LIBRARIES}
)
