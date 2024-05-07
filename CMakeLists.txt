cmake_minimum_required(VERSION 3.14)
project(SimpleLinkedListSolution LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(extern/googletest)

add_subdirectory(SimpleLinkedList)
add_subdirectory(SimpleLinkedListTest)