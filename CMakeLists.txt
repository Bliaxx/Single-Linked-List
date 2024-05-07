cmake_minimum_required(VERSION 3.14)
project(MySolution LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(gtest_force_shared_crt ON CACHE BOOL "Use shared (DLL) run-time lib even when Google Test is built as static lib." FORCE)

add_subdirectory(extern/googletest)

add_subdirectory("Simple Linked List")
add_subdirectory(SingleLinkedListTest)