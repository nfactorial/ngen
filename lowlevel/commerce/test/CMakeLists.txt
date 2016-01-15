project(commerce_tests)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(commerce_tests
        test_store.cpp)

target_link_libraries(commerce_tests gtest gtest_main)
target_link_libraries(commerce_tests ngen_commerce)
