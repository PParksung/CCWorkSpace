#include "gtest/gtest.h"
#include "int_node.h"
#include "node.h"
#include "string_node.h"
#include "tree_util.h"

class TreeUtilTest : public ::testing::Test {
 protected:
        void SetUp() override {}
        void TearDown() override { }
};

TEST_F(TreeUtilTest, PreOrderTraversalTest1) {
    Node* leftchild = new IntNode(2, new StringNode("A", nullptr, nullptr),
    new StringNode("B", nullptr, nullptr));
    Node* rightchild = new IntNode(3, nullptr, nullptr);
    Node* root = new IntNode(1, leftchild, rightchild);

    TreeUtil* treeUtil = TreeUtil::GetInstance();
    std::string result = treeUtil->PreOrderTraversal(root);
    EXPECT_EQ(result, "1,2,A,B,3");
}

TEST_F(TreeUtilTest, InOrderTraversalTest1) {
    Node* leftchild = new IntNode(2, new StringNode("A", nullptr, nullptr),
    new StringNode("B", nullptr, nullptr));
    Node* rightchild = new IntNode(3, nullptr, nullptr);
    Node* root = new IntNode(1, leftchild, rightchild);

    TreeUtil* treeUtil = TreeUtil::GetInstance();
    std::string result = treeUtil->InOrderTraversal(root);
    EXPECT_EQ(result, "A,2,B,1,3");
}

TEST_F(TreeUtilTest, PostOrderTraversalTest1) {
    Node* leftchild = new IntNode(2, new StringNode("A", nullptr, nullptr),
    new StringNode("B", nullptr, nullptr));
    Node* rightchild = new IntNode(3, nullptr, nullptr);
    Node* root = new IntNode(1, leftchild, rightchild);

    TreeUtil* treeUtil = TreeUtil::GetInstance();
    std::string result = treeUtil->PostOrderTraversal(root);
    EXPECT_EQ(result, "A,B,2,3,1");
}

TEST_F(TreeUtilTest, PreOrderTraversalTest2) {
    Node* leftChild = new IntNode(55, nullptr, nullptr);
    Node* rightChild = new IntNode(66, nullptr, nullptr);
    Node* root = new IntNode(44, leftChild, rightChild);

    TreeUtil* treeUtil = TreeUtil::GetInstance();
    std::string result = treeUtil->PreOrderTraversal(root);
    EXPECT_EQ(result, "44,55,66");
}

TEST_F(TreeUtilTest, InOrderTraversalTest2) {
    Node* leftChild = new IntNode(55, nullptr, nullptr);
    Node* rightChild = new IntNode(66, nullptr, nullptr);
    Node* root = new IntNode(44, leftChild, rightChild);

    TreeUtil* treeUtil = TreeUtil::GetInstance();
    std::string result = treeUtil->InOrderTraversal(root);
    EXPECT_EQ(result, "55,44,66");
}

TEST_F(TreeUtilTest, PostOrderTraversalTest2) {
    Node* leftChild = new IntNode(55, nullptr, nullptr);
    Node* rightChild = new IntNode(66, nullptr, nullptr);
    Node* root = new IntNode(44, leftChild, rightChild);

    TreeUtil* treeUtil = TreeUtil::GetInstance();
    std::string result = treeUtil->PostOrderTraversal(root);
    EXPECT_EQ(result, "55,66,44");
}

TEST_F(TreeUtilTest, PreOrderTraversalTest3) {
    Node* leftchild = new IntNode(2, nullptr, nullptr);
    Node* rightchild = new IntNode(3, new StringNode("B", nullptr, nullptr),
    new StringNode("C", nullptr, nullptr));
    Node* root = new IntNode(1, leftchild, rightchild);

    TreeUtil* treeUtil = TreeUtil::GetInstance();
    std::string result = treeUtil->PreOrderTraversal(root);
    EXPECT_EQ(result, "1,2,3,B,C");
}

TEST_F(TreeUtilTest, InOrderTraversalTest3) {
    Node* leftchild = new IntNode(2, nullptr, nullptr);
    Node* rightchild = new IntNode(3, new StringNode("B", nullptr, nullptr),
    new StringNode("C", nullptr, nullptr));
    Node* root = new IntNode(1, leftchild, rightchild);

    TreeUtil* treeUtil = TreeUtil::GetInstance();
    std::string result = treeUtil->InOrderTraversal(root);
    EXPECT_EQ(result, "2,1,B,3,C");
}

TEST_F(TreeUtilTest, PostOrderTraversalTest3) {
    Node* leftchild = new IntNode(2, nullptr, nullptr);
    Node* rightchild = new IntNode(3, new StringNode("B", nullptr, nullptr),
    new StringNode("C", nullptr, nullptr));
    Node* root = new IntNode(1, leftchild, rightchild);

    TreeUtil* treeUtil = TreeUtil::GetInstance();
    std::string result = treeUtil->PostOrderTraversal(root);
    EXPECT_EQ(result, "2,B,C,3,1");
}
