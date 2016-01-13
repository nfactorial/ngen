project(display_tests)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(display_tests
        test_display_port.cpp)

target_link_libraries(display_tests gtest gtest_main)
target_link_libraries(display_tests ngen_display)
