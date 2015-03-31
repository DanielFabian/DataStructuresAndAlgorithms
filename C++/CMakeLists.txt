cmake_minimum_required(VERSION 3.1)
project(c++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -O3 -march=x86-64")

AUX_SOURCE_DIRECTORY(. SOURCE_FILES)

add_executable(c++ ${SOURCE_FILES})