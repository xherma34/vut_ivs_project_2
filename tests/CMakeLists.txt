cmake_minimum_required(VERSION 2.6)

project(TestingNaCalculator)


# Locate GTest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# Link runTests with what we want to test and the GTest and pthread library
add_executable(c_test tdd_tests.cpp)
target_link_libraries(c_test ${GTEST_LIBRARIES} pthread)
