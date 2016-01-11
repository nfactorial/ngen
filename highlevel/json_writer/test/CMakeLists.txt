project(json_writer_tests)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(json_writer_tests
        test_json_writer.cpp)

target_link_libraries(json_writer_tests gtest gtest_main)
target_link_libraries(json_writer_tests ngen_json_writer)
