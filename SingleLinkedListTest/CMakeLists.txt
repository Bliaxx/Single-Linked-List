cmake_minimum_required(VERSION 3.14)
project(SimpleLinkedListTest LANGUAGES CXX)

include_directories(${CMAKE_SOURCE_DIR}/Simple Linked List/include)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

add_executable(SimpleLinkedListTest TestMain.cpp tests/NodeTest.h)

target_link_libraries(SimpleLinkedListTest gtest gtest_main)