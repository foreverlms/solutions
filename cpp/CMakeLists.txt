cmake_minimum_required(VERSION 3.13)
project(cpp)

set(CMAKE_CXX_STANDARD 11)
set(SRC_LIST main.cpp src/leetcode64.cpp)

add_subdirectory(include)
add_subdirectory(src)

add_executable(cpp ${SRC_LIST})