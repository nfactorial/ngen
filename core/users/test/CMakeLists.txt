project(user_tests)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(user_tests
        test_user_info.cpp
        test_user_list.cpp)

target_link_libraries(user_tests gtest gtest_main)
target_link_libraries(user_tests ngen_users)
