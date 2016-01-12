cmake_minimum_required(VERSION 3.3)

project(ngenRenderLayer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)

set(SOURCE_FILES
        src/render_layer.cpp)

set(INCLUDE_FILES
        include/render_layer.h)

add_library(ngen_renderlayer ${SOURCE_FILES} ${INCLUDE_FILES})

if (ngen_build_tests)
    add_subdirectory(test)
endif()
