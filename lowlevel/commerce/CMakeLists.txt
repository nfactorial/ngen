cmake_minimum_required(VERSION 2.7)

project(ngen_commerce)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${NGEN_STD}")

include_directories(include)

set(SOURCE_FILES
        src/store.cpp)

set(INCLUDE_FILES
        include/store.h)

add_library(ngen_commerce ${SOURCE_FILES} ${INCLUDE_FILES})

if (ngen_build_tests)
    add_subdirectory(test)
endif()
