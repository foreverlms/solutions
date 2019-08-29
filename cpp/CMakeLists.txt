cmake_minimum_required(VERSION 2.8)
project(cpp)

set(CMAKE_CXX_STANDARD 11)
# set(SRC_LIST "./src/jd/src/choice.cpp")
set(SRC_LIST "./src/test.cpp")



include_directories("./include")
add_subdirectory(src)

add_executable(cpp ${SRC_LIST})