project(ngenExternal)

set(VECTORMATH_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/sce_vectormath)
set(VECTORMATH_INCLUDE_DIR ${VECTORMATH_ROOT_DIR}/include/vectormath/SSE/cpp)

set(BUILD_UNIT_TESTS OFF)

add_subdirectory(GSL)
add_subdirectory(bullet3)

if (ngen_build_tests)
    add_subdirectory(googletest)
endif()
