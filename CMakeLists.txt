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
add_executable(42-trapping-rain-water leetcode/editor/cn/42-trapping-rain-water.cpp)
add_executable(242-valid-anagram leetcode/editor/cn/242-valid-anagram.cpp)
add_executable(49-group-anagrams leetcode/editor/cn/49-group-anagrams.cpp)
add_executable(94-binary-tree-inorder-traversal leetcode/editor/cn/94-binary-tree-inorder-traversal.cpp)
add_executable(297-serialize-and-deserialize-binary-tree leetcode/editor/cn/297-serialize-and-deserialize-binary-tree.cpp)
add_executable(77-combinations leetcode/editor/cn/77-combinations.cpp)
add_executable(78-subsets leetcode/editor/cn/78-subsets.cpp)
add_executable(40-combination-sum-ii leetcode/editor/cn/40-combination-sum-ii.cpp)
add_executable(17-letter-combinations-of-a-phone-number leetcode/editor/cn/17-letter-combinations-of-a-phone-number.cpp)
add_executable(15-3sum leetcode/editor/cn/15-3sum.cpp)