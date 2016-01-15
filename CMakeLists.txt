cmake_minimum_required(VERSION 3.3)

option(ngen_build_tests "Build unit tests." ON)

add_subdirectory(external)

# We require the boost library to be installed, we expect it to be located in the external/boost_1_60_0 folder.
# If you install boost to an alternative path, update this to the correct location.
# I may use a system environment variable in the future. But happy with this for now.
include_directories(SYSTEM external/boost_1_60_0)
include_directories(SYSTEM include)

project(ngen)

add_subdirectory(core)
add_subdirectory(lowlevel)
add_subdirectory(highlevel)
