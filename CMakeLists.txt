#参考 https://www.jianshu.com/p/04343d6be97e
cmake_minimum_required(VERSION 3.17)
project(algorithm)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_subdirectory(leetcode/editor/cn/include)

add_executable(algorithm main.cpp)


add_executable(206-reverse-linked-list leetcode/editor/cn/206-reverse-linked-list.cpp)
add_executable(25-reverse-nodes-in-k-group leetcode/editor/cn/25-reverse-nodes-in-k-group.cpp)