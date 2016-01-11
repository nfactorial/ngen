cmake_minimum_required(VERSION 3.3)

project(ngenJSONWriter)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)

set(SOURCE_FILES
        source/json_writer.cpp)

set(INCLUDE_FILES
        include/json_writer.h)

add_library(ngen_json_writer ${SOURCE_FILES} ${INCLUDE_FILES})

if (ngen_build_tests)
    add_subdirectory(test)
endif()