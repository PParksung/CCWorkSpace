#include "gtest/gtest.h"
#include "int_node.h"
#include "string_node.h"
#include "postorder_traversal.h"
#include "preorder_traversal.h"

class PreTest : public ::testing::Test {
 protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(PreTest, PreTest1) {
    Node* root = new IntNode(3, nullptr, nullptr);

    PreorderTraversal preorder;
    root->Visit(&preorder);
    std::string result = preorder.Result();
    EXPECT_EQ(result, "(Int 3)");
}

TEST_F(PreTest, PreTest2) {
    Node* leftChild = new StringNode("hi", nullptr, nullptr);
    Node* root = new IntNode(3, leftChild, nullptr);

    PreorderTraversal preorder;
    root->Visit(&preorder);
    std::string result = preorder.Result();
    EXPECT_EQ(result, "(Int 3) :: (String hi)");
}

TEST_F(PreTest, PreTest3) {
    Node* leftChild = new StringNode("hi", nullptr, nullptr);
    Node* rightChild = new IntNode(-42, nullptr, nullptr);
    Node* root = new IntNode(3, leftChild, rightChild);

    PreorderTraversal preorder;
    root->Visit(&preorder);
    std::string result = preorder.Result();
    EXPECT_EQ(result, "(Int 3) :: (String hi) :: (Int -42)");
}

TEST_F(PreTest, PreTest4) {
    Node* leftChild = new StringNode("hi", nullptr, nullptr);
    Node* rightChild =
    new IntNode(-42,  new IntNode(0, nullptr, nullptr), nullptr);
    Node* root = new IntNode(3, leftChild, rightChild);

    PreorderTraversal preorder;
    root->Visit(&preorder);
    std::string result = preorder.Result();
    EXPECT_EQ(result, "(Int 3) :: (String hi) :: (Int -42) :: (Int 0)");
}

TEST_F(PreTest, PreTest5) {
    Node* leftChild = new StringNode("hi", nullptr, nullptr);
    Node* rightChild =
    new IntNode(-42, new IntNode(0, nullptr, nullptr),
    new StringNode("bye", nullptr, nullptr));
    Node* root = new IntNode(3, leftChild, rightChild);

    PreorderTraversal preorder;
    root->Visit(&preorder);
    std::string result = preorder.Result();
    EXPECT_EQ(result,
    "(Int 3) :: (String hi) :: (Int -42) :: (Int 0) :: (String bye)");
}

class PostTest : public ::testing::Test {
 protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(PostTest, PostTest1) {
    Node* root = new IntNode(3, nullptr, nullptr);

    PostorderTraversal postorder;
    root->Visit(&postorder);
    std::string result = postorder.Result();
    EXPECT_EQ(result, "(Int 3)");
}

TEST_F(PostTest, PostTest2) {
    Node* leftChild = new StringNode("hi", nullptr, nullptr);
    Node* root = new IntNode(3, leftChild, nullptr);

    PostorderTraversal postorder;
    root->Visit(&postorder);
    std::string result = postorder.Result();
    EXPECT_EQ(result, "(String hi) :: (Int 3)");
}

TEST_F(PostTest, PostTest3) {
    Node* leftChild = new StringNode("hi", nullptr, nullptr);
    Node* rightChild = new IntNode(-42, nullptr, nullptr);
    Node* root = new IntNode(3, leftChild, rightChild);

    PostorderTraversal postorder;
    root->Visit(&postorder);
    std::string result = postorder.Result();
    EXPECT_EQ(result, "(String hi) :: (Int -42) :: (Int 3)");
}

TEST_F(PostTest, PostTest4) {
    Node* leftChild = new StringNode("hi", nullptr, nullptr);
    Node* rightChild =
    new IntNode(-42, new IntNode(0, nullptr, nullptr), nullptr);
    Node* root = new IntNode(3, leftChild, rightChild);

    PostorderTraversal postorder;
    root->Visit(&postorder);
    std::string result = postorder.Result();

    EXPECT_EQ(result, "(String hi) :: (Int 0) :: (Int -42) :: (Int 3)");
}

TEST_F(PostTest, PostTest5) {
    Node* leftChild = new StringNode("hi", nullptr, nullptr);
    Node* rightChild =
    new IntNode(-42, new IntNode(0, nullptr, nullptr),
    new StringNode("bye", nullptr, nullptr));
    Node* root = new IntNode(3, leftChild, rightChild);

    PostorderTraversal postorder;
    root->Visit(&postorder);
    std::string result = postorder.Result();
    EXPECT_EQ(result,
    "(String hi) :: (Int 0) :: (String bye) :: (Int -42) :: (Int 3)");
}
