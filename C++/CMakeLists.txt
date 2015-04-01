cmake_minimum_required(VERSION 3.1)
project(c++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -march=x86-64")

set(BOOST_ROOT "/usr/include/boost")

find_package(Boost 1.55.0)

if(NOT Boost_FOUND)
    message(FATAL_ERROR "Could not find boost!")
endif()

AUX_SOURCE_DIRECTORY(. SOURCE_FILES)

add_executable(c++ ${SOURCE_FILES})