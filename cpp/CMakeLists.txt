cmake_minimum_required(VERSION 3.13)
project(cpp)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(include)
add_subdirectory(src)

add_executable(cpp main.cpp src/leetcode14.cpp)