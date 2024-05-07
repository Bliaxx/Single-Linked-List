cmake_minimum_required(VERSION 3.14)
project(SimpleLinkedList LANGUAGES CXX)

include_directories(include)

add_executable(SimpleLinkedList examples/main.cpp)

target_include_directories(SimpleLinkedList PUBLIC include)