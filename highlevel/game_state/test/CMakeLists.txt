project(game_state_tests)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(game_state_tests
        test_game_system_factory.cpp
        test_state_system.cpp)

target_link_libraries(game_state_tests gtest gtest_main)
target_link_libraries(game_state_tests ngen_gamestate)
