#include <gtest/gtest.h>
#include "Node.h"

template<typename T>
class NodeTestBase : public testing::Test {
protected:
    Node<T>* node;

    void SetUp() override {
        node = new Node<T>(T{});
    }

    void TearDown() override {
        delete node;
    }
};

class NodeTestInt : public NodeTestBase<int> {};
class NodeTestDouble : public NodeTestBase<double> {};
class NodeTestString : public NodeTestBase<std::string> {};

TEST_F(NodeTestInt, InitializesWithDefaultValue) {
    EXPECT_EQ(node->GetData(), 0);
}

TEST_F(NodeTestInt, HandlesNextNode) {
    Node<int>* nextNode = new Node<int>(123);
    node->SetNextNode(nextNode);
    ASSERT_EQ(node->GetNextNode(), nextNode);
    EXPECT_EQ(node->GetNextNode()->GetData(), 123);
    delete nextNode;
}

TEST_F(NodeTestDouble, InitializesWithDefaultValue) {
    EXPECT_EQ(node->GetData(), 0.0);
}

TEST_F(NodeTestDouble, ModificationOfData) {
    node->SetData(1.234);
    EXPECT_EQ(node->GetData(), 1.234);
}

TEST_F(NodeTestString, InitializesWithDefaultValue) {
    EXPECT_EQ(node->GetData(), "");
}

TEST_F(NodeTestString, ModificationOfData) {
    node->SetData("Hello");
    EXPECT_EQ(node->GetData(), "Hello");
}

TEST_F(NodeTestString, CheckCopyConstructor) {
    node->SetData("Test");
    Node<std::string> copy(*node);
    EXPECT_EQ(copy.GetData(), "Test");
}

TEST_F(NodeTestString, EqualityOperator) {
    Node<std::string> node1("test");
    Node<std::string> node2("test");
    Node<std::string> node3("diff");

    EXPECT_TRUE(node1 == node2);
    EXPECT_FALSE(node1 == node3);
}

TEST_F(NodeTestString, InequalityOperator) {
    Node<std::string> node1("test");
    Node<std::string> node2("test");
    Node<std::string> node3("diff");

    EXPECT_FALSE(node1 != node2);
    EXPECT_TRUE(node1 != node3);
}

TEST_F(NodeTestString, OutputStreamOperator) {
    std::stringstream ss;
    node->SetData("Test Node");
    ss << *node;
    EXPECT_EQ(ss.str(), "Node(data : Test Node)");
}
