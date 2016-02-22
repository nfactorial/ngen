cmake_minimum_required(VERSION 2.7)

project(ngenApplication)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${NGEN_STD}")
set(NGEN_APPLICATION_INCLUDE_DIR ${PROJECT_SOURCE_DIR}/include)

find_package(SDL2 REQUIRED)

include_directories(include)
include_directories(${SDL2_INCLUDE_DIR})

set(SOURCE_FILES
        src/application.cpp)

set(INCLUDE_FILES
        include/application_info.h
        include/application.h
        include/ikeyboard_handler.h)

add_library(ngen_application ${SOURCE_FILES} ${INCLUDE_FILES})
target_link_libraries(ngen_application ${SDL2_LIBRARY})

if (ngen_build_tests)
    add_subdirectory(test)
endif()
