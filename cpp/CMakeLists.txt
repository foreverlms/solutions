cmake_minimum_required(VERSION 2.8)


project(cpp)

add_definitions(-std=c++11)
# set(SRC_LIST "./src/test.cpp")
set(SRC_LIST "./src/foo.cpp")



include_directories("./include")
add_subdirectory(src)

add_executable(cpp ${SRC_LIST})