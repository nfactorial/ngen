cmake_minimum_required(VERSION 3.3)

project(ngenMemory)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)

# We require the boost library to be installed, we expect it to be located in the external/boost_1_60_0 folder.
# If you install boost to an alternative path, update this to the correct location.
# I may use a system environment variable in the future. But happy with this for now.
#include_directories(SYSTEM external/boost_1_60_0)

set(SOURCE_FILES
        src/heap_allocator.cpp
        src/memory.cpp)

set(INCLUDE_FILES
        include/heap_allocator.h
        include/memory.h)

add_library(ngen_memory ${SOURCE_FILES} ${INCLUDE_FILES})

if (ngen_build_tests)
    add_subdirectory(test)
endif()
