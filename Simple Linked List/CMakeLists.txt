cmake_minimum_required(VERSION 3.14)
project(SimpleLinkedList LANGUAGES CXX)

add_executable(SimpleLinkedList examples/main.cpp)
target_include_directories(SimpleLinkedList PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)