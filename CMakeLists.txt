cmake_minimum_required(VERSION 3.15)
project(SimpleLinkedListSolution LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(extern/googletest)

add_subdirectory("Simple Linked List")
add_subdirectory(SingleLinkedListTest)