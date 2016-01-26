cmake_minimum_required(VERSION 3.3)

project(ngenDisplay)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

include_directories(include)
include_directories(${ngenExternal_SOURCE_DIR}/sce_vectormath/include/vectormath/SSE/cpp) # TODO: Simplify this
include_directories(${GSL_SOURCE_DIR}/include)

# Enable correct rendering API
if (NGEN_BUILD_OPENGL)
    find_package(OpenGL REQUIRED)

    if(OPENGL_FOUND)
        MESSAGE( "OpenGL library found successfully.")
        include_directories(SYSTEM ${OPENGL_INCLUDE_DIR})
    else(OPENGL_FOUND)
        MESSAGE( "Unable to find OpenGL library, please make sure it is installed." )
    endif (OPENGL_FOUND)

    include_directories(${ngenOpenGL_SOURCE_DIR}/include)
endif()

set(SOURCE_FILES
        src/display_port.cpp
        src/render_layer.cpp
        src/material_request.cpp
        src/request_provider.cpp
        src/display_pipeline.cpp
        src/display_provider.cpp)

set(INCLUDE_FILES
        include/display_port.h
        include/display_pipeline.h
        include/material_request.h
        include/request_provider.h
        include/render_layer.h
        include/request_page.h
        include/camera_args.h
        include/display_provider.h)

add_library(ngen_display ${SOURCE_FILES} ${INCLUDE_FILES})

if (ngen_build_tests)
    add_subdirectory(test)
endif()

