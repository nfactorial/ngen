cmake_minimum_required(VERSION 3.3)

project(ngenDisplay)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)

set(SOURCE_FILES
        src/display_port.cpp
        src/display_pipeline.cpp)

set(INCLUDE_FILES
        include/display_port.h
        include/display_pipeline.h
        include/camera_type.h
        include/camera_args.h)

add_library(ngen_display ${SOURCE_FILES} ${INCLUDE_FILES})

if (ngen_build_tests)
    add_subdirectory(test)
endif()
