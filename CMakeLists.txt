#参考 https://www.jianshu.com/p/04343d6be97e
cmake_minimum_required(VERSION 3.17)
project(algorithm)

set(CMAKE_CXX_STANDARD 14)

include_directories(${CMAKE_SOURCE_DIR}/include)
add_subdirectory(leetcode/editor/cn/include)

add_executable(algorithm main.cpp)


add_executable(206-reverse-linked-list leetcode/editor/cn/206-reverse-linked-list.cpp)
add_executable(25-reverse-nodes-in-k-group leetcode/editor/cn/25-reverse-nodes-in-k-group.cpp)
add_executable(26-remove-duplicates-from-sorted-array leetcode/editor/cn/26-remove-duplicates-from-sorted-array.cpp)
add_executable(20-valid-parentheses leetcode/editor/cn/20-valid-parentheses.cpp)
add_executable(155-min-stack leetcode/editor/cn/155-min-stack.cpp)
add_executable(84-largest-rectangle-in-histogram leetcode/editor/cn/84-largest-rectangle-in-histogram.cpp)
add_executable(239-sliding-window-maximum leetcode/editor/cn/239-sliding-window-maximum.cpp)