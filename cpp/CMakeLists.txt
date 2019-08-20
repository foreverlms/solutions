cmake_minimum_required(VERSION 2.8)
project(cpp)

set(CMAKE_CXX_STANDARD 11)
set(SRC_LIST "./src/bilibili/second.cpp")


include_directories("./include")
add_subdirectory(src)

add_executable(cpp ${SRC_LIST})