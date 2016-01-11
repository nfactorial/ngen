include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

project(ngen_memory_tests)

add_executable(memory_tests
        test_heap_allocator.cpp)

target_link_libraries(memory_tests gtest gtest_main)
target_link_libraries(memory_tests ngen_memory)
