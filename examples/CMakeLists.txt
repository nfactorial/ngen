cmake_minimum_required(VERSION 2.7)

project(ngen_example)

#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -stdlib=libc++")
set(CMAKE_CXX_FLAGS "-std=c++0x -stdlib=libc++ -g3 -Wall -O0")

find_package(SDL2 REQUIRED)

include_directories(include)
include_directories(${SDL2_INCLUDE_DIR})
#include_directories(${NGEN_APPLICATION_INCLUDE_DIR})
include_directories(${ngenApplication_SOURCE_DIR}/include)

set(SOURCE_FILES
        src/example.cpp)

set(INCLUDE_FILES
        include/input_handler.h
        include/simulation.h)

add_executable(ngen_example
        ${SOURCE_FILES})

if ( APPLE )
    #target_link_libraries(ngen_example stdc++ "-framework Foundation" "-framework Cocoa" "-framework AppKit" "-framework IOKit" objc)
    target_link_libraries(ngen_example stdc++)
endif ( APPLE )

#target_link_libraries(ngen_example ${OGRE_LIBRARIES} ${OIS_LIBRARIES})
#target_link_libraries(ngen_example OgreMain OIS)

#target_link_libraries(ngen_example ${OGRE_LIBRARIES} ${OIS_LIBRARIES})
target_link_libraries(ngen_example ngen_commerce ngen_application ngen_opengl ${SDL2_LIBRARY})
