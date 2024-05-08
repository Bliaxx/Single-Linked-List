cmake_minimum_required(VERSION 3.15)
project(SimpleLinkedListTest LANGUAGES CXX)

if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebugDLL")
endif()

add_executable(SimpleLinkedListTest TestMain.cpp)
target_include_directories(SimpleLinkedListTest PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/tests "${CMAKE_CURRENT_SOURCE_DIR}/../	Simple Linked List/include")

target_link_libraries(SimpleLinkedListTest gtest gtest_main)