#pragma once

#include <gtest/gtest.h>
#include "LinkedList.h"

template<typename T>
class LinkedListTestBase : public testing::Test {
protected:
    LinkedList<T> list;

    void TearDown() override {
        list.Clear();
    }
};

class LinkedListInt : public LinkedListTestBase<int> {};

TEST_F(LinkedListInt, InsertAtFrontTest) {
    list.InsertAtFront(10);
    ASSERT_EQ(list.Front(), 10);
    list.InsertAtFront(20);
    ASSERT_EQ(list.Front(), 20);
}

TEST_F(LinkedListInt, InsertAtEndTest) {
    list.InsertAtEnd(10);
    ASSERT_EQ(list.Back(), 10);
    list.InsertAtEnd(20);
    ASSERT_EQ(list.Back(), 20);
}

TEST_F(LinkedListInt, InsertAtIndexTest) {
    list.InsertAtEnd(10);
    list.InsertAtEnd(30);
    list.InsertAtIndex(20, 1);
    ASSERT_EQ(list.Find(20)->GetData(), 20);
}

TEST_F(LinkedListInt, DeleteAtIndexTest) {
    list.InsertAtEnd(10);
    list.InsertAtEnd(20);
    list.InsertAtEnd(30);
    list.DeleteAtIndex(1);
    ASSERT_EQ(list.GetSize(), 2);
    ASSERT_EQ(list.Find(20), nullptr);
}

TEST_F(LinkedListInt, FindTest) {
    list.InsertAtEnd(10);
    ASSERT_NE(list.Find(10), nullptr);
    ASSERT_EQ(list.Find(10)->GetData(), 10);
    ASSERT_EQ(list.Find(20), nullptr);
}

TEST_F(LinkedListInt, IteratorTest) {
    list.InsertAtEnd(1);
    list.InsertAtEnd(2);
    LinkedList<int>::Iterator it = list.begin();
    ASSERT_EQ(*it, 1);
    ++it;
    ASSERT_EQ(*it, 2);
    ++it;
    ASSERT_EQ(it, list.end());
}

TEST_F(LinkedListInt, ClearTest) {
    list.InsertAtEnd(1);
    list.InsertAtEnd(2);
    list.Clear();
    ASSERT_TRUE(list.IsEmpty());
}

TEST_F(LinkedListInt, EqualityTest) {
    LinkedList<int> other;
    list.InsertAtEnd(1);
    list.InsertAtEnd(2);
    other.InsertAtEnd(1);
    other.InsertAtEnd(2);
    ASSERT_TRUE(list == other);
    other.InsertAtEnd(3);
    ASSERT_FALSE(list == other);
}

TEST_F(LinkedListInt, OperatorOutputStream) {
    list.InsertAtEnd(1);
    list.InsertAtEnd(2);
    list.InsertAtEnd(3);

    std::stringstream ss;
    ss << list;

    std::string expectedOutput = "1->2->3->nullptr";
    ASSERT_EQ(ss.str(), expectedOutput);
}

TEST_F(LinkedListInt, OperatorAssignment) {
    list.InsertAtEnd(1);
    list.InsertAtEnd(2);
    list.InsertAtEnd(3);

    LinkedList<int> anotherList;
    anotherList = list;

    ASSERT_EQ(anotherList.GetSize(), list.GetSize());
    ASSERT_TRUE(anotherList == list);

    list.InsertAtEnd(4);
    ASSERT_NE(anotherList.GetSize(), list.GetSize());
    ASSERT_FALSE(anotherList == list);
}

TEST_F(LinkedListInt, RemoveIfTest) {
    list.InsertAtEnd(1);
    list.InsertAtEnd(2);
    list.InsertAtEnd(3);
    list.InsertAtEnd(4);
    list.InsertAtEnd(5);

    list.RemoveIf([](const int& value) { return value % 2 == 0; });

    ASSERT_EQ(list.GetSize(), 3);
    ASSERT_EQ(list.Find(1)->GetData(), 1);
    ASSERT_EQ(list.Find(3)->GetData(), 3);
    ASSERT_EQ(list.Find(5)->GetData(), 5);
    ASSERT_EQ(list.Find(2), nullptr);
    ASSERT_EQ(list.Find(4), nullptr);

    std::stringstream ss;
    ss << list;
    ASSERT_EQ(ss.str(), "1->3->5->nullptr");
}