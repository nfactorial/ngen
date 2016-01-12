project(render_layer_tests)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(render_layer_tests
        test_render_layer.cpp)

target_link_libraries(render_layer_tests gtest gtest_main)
target_link_libraries(render_layer_tests ngen_renderlayer)
