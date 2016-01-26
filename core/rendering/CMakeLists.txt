project(ngen_rendering)

if (NGEN_BUILD_OPENGL)
    add_subdirectory(ngen_opengl)
endif()

add_subdirectory(display)
