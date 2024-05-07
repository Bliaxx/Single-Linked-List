project(SimpleLinkedListTest LANGUAGES CXX)

set(SLL_INCLUDE_DIR "${CMAKE_SOURCE_DIR}/Simple Linked List/include")

add_executable(SimpleLinkedListTest TestMain.cpp tests/NodeTest.h)
target_include_directories(SimpleLinkedListTest PRIVATE ${SLL_INCLUDE_DIR})
target_include_directories(SimpleLinkedListTest PRIVATE ${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

target_link_libraries(SimpleLinkedListTest gtest gtest_main)