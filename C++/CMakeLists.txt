cmake_minimum_required(VERSION 3.1)
project(c++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++1y -march=x86-64 -Wall -Wextra -Werror -O3")

set(BOOST_ROOT "/usr/include/boost")

find_package(Boost 1.55.0)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()

################################
# GTest
################################
ADD_SUBDIRECTORY (lib/gtest)
enable_testing()
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

################################
# Prod code
################################
AUX_SOURCE_DIRECTORY(. SOURCE_FILES)

list(REMOVE_ITEM SOURCE_FILES main.cpp)
add_library(c++implementation ${SOURCE_FILES} trivial.h trivial.cpp)
add_executable(c++ main.cpp)
target_link_libraries(c++ c++implementation)

################################
# Unit Tests
################################
# Add test cpp file
aux_source_directory(tests TEST_SOURCE_FILES)
add_executable(c++tests ${TEST_SOURCE_FILES} tests/main.cpp tests/benchmark.h tests/benchmark.cpp)
# Link test executable against gtest & gtest_main

target_link_libraries(c++tests gtest gtest_main c++implementation)
add_test(c++tests c++tests)