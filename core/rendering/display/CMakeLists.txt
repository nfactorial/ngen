cmake_minimum_required(VERSION 3.3)

project(ngenDisplay)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)
include_directories(${ngen_rendering_SOURCE_DIR}/include)
include_directories(${ngenExternal_SOURCE_DIR}/sce_vectormath/include/vectormath/SSE/cpp) # TODO: Simplify this

set(SOURCE_FILES
        src/display_port.cpp
        src/render_layer.cpp
        src/request_provider.cpp
        src/display_pipeline.cpp
        src/display_provider.cpp)

set(INCLUDE_FILES
        include/display_port.h
        include/display_pipeline.h
        include/material_request.h
        include/request_provider.h
        include/request_queue.h
        include/render_layer.h
        include/camera_type.h
        include/camera_args.h
        include/display_provider.h)

add_library(ngen_display ${SOURCE_FILES} ${INCLUDE_FILES})

if (ngen_build_tests)
    add_subdirectory(test)
endif()
