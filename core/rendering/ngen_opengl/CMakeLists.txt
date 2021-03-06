cmake_minimum_required(VERSION 2.7)

project(ngenOpenGL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${NGEN_STD}")

find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR})

if(OPENGL_FOUND)
    MESSAGE( "OpenGL library found successfully.")
    include_directories(SYSTEM ${OPENGL_INCLUDE_DIR})
else(OPENGL_FOUND)
    MESSAGE( "Unable to find OpenGL library, please make sure it is installed." )
endif (OPENGL_FOUND)

include_directories(include)
include_directories(${ngenExternal_SOURCE_DIR}/sce_vectormath/include/vectormath/SSE/cpp) # TODO: Simplify this

set(SOURCE_FILES
        src/buffer_object.cpp
        src/state_manager.cpp
        src/program_factory.cpp
        src/shader.cpp
        src/program.cpp
        src/texture.cpp
        src/material.cpp)

set(INCLUDE_FILES
        include/buffer_object.h
        include/shader.h
        include/state_value.h
        include/state_manager.h
        include/program_factory.h
        include/geometry.h
        include/program.h
        include/texture.h
        include/material.h)

add_library(ngen_opengl ${SOURCE_FILES} ${INCLUDE_FILES})

target_link_libraries(ngen_opengl ${OPENGL_LIBRARIES})

if (ngen_build_tests)
    add_subdirectory(test)
endif()
