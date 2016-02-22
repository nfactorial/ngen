project(ngen_gl_tests)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(ngen_gl_tests
        test_texture.cpp
        test_program_factory.cpp)

target_link_libraries(ngen_gl_tests gtest gtest_main)
target_link_libraries(ngen_gl_tests ngen_opengl)
