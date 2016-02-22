cmake_minimum_required(VERSION 2.7)

project(ngenGameState)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${NGEN_STD}")

include_directories(include)

set(SOURCE_FILES
        src/game_system.cpp
        src/game_system_factory.cpp
        src/state_system.cpp)

set(INCLUDE_FILES
        include/game_system.h
        include/game_system_factory.h
        include/state_description.h
        include/state_system.h include/init_args.h include/game_system_ref.h)

add_library(ngen_gamestate ${SOURCE_FILES} ${INCLUDE_FILES})

if (ngen_build_tests)
    add_subdirectory(test)
endif()