cmake_minimum_required(VERSION 3.3)

project(ngenUsers)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)

set(SOURCE_FILES
        source/user_info.cpp
        source/user_list.cpp)

set(INCLUDE_FILES
        include/user_info.h
        include/user_list.h
        include/user.h)

add_library(ngen_users ${SOURCE_FILES} ${INCLUDE_FILES})

if (ngen_build_tests)
    add_subdirectory(test)
endif()