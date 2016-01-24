cmake_minimum_required(VERSION 3.3)

project(ngenOpenGL)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(OpenGL REQUIRED)

include_directories(${OPENGL_INCLUDE_DIR})

if(OPENGL_FOUND)
    MESSAGE( "OpenGL library found successfully.")
    include_directories(SYSTEM ${OPENGL_INCLUDE_DIR})
else(OPENGL_FOUND)
    MESSAGE( "Unable to find OpenGL library, please make sure it is installed." )
endif (OPENGL_FOUND)

include_directories(include)
include_directories(${ngen_rendering_SOURCE_DIR}/include)

set(SOURCE_FILES
        src/buffer_object.cpp
        src/shader.cpp
        src/program.cpp
        src/texture.cpp
        src/material.cpp)

set(INCLUDE_FILES
        include/buffer_object.h
        include/shader.h
        include/program.h
        include/texture.h
        include/material.h)

add_library(ngen_opengl ${SOURCE_FILES} ${INCLUDE_FILES})

target_link_libraries(ngen_opengl ${OPENGL_LIBRARIES})

if (ngen_build_tests)
    add_subdirectory(test)
endif()
