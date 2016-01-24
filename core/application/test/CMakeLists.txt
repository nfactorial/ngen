project(application_tests)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(application_tests
        test_application.cpp)

target_link_libraries(application_tests gtest gtest_main)
target_link_libraries(application_tests ngen_application)
