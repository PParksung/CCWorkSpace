#include "gtest/gtest.h"
#include "sort.h"
#include <vector>
#include <list>
#include <deque>
#include <array>
#include <string>

class TemplateIncreasing {
 public:
    template<typename T>
    bool operator()(const T& a, const T& b) const {
        return a > b;
    }
};

class TemplateDecreasing {
 public:
    template<typename T>
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};

class SortTest : public ::testing::Test {
 protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(SortTest, ArrayTest1) {
    std::array<int, 8> a = {1, 3, 5, 2, 6, 8, 4, 0};
    Sort<std::array<int, 8>, TemplateIncreasing>(a.begin(), a.end());
    EXPECT_EQ(a, (std::array<int, 8>{{0, 1, 2, 3, 4, 5, 6, 8}}));
}

TEST_F(SortTest, ArrayTest2) {
    std::array<int, 8> a = {1, 3, 5, 2, 6, 8, 4, 0};
    Sort<std::array<int, 8>, TemplateDecreasing>(a.begin(), a.end());
    EXPECT_EQ(a, (std::array<int, 8>{{8, 6, 5, 4, 3, 2, 1, 0}}));
}

TEST_F(SortTest, ArrayTest3) {
    std::array<std::string, 3> a = {"cake", "bye", "air"};
    Sort<std::array<std::string, 3>, TemplateIncreasing>(a.begin(), a.end());
    EXPECT_EQ(a, (std::array<std::string, 3>{{"air", "bye", "cake"}}));
}

TEST_F(SortTest, ArrayTest4) {
    std::array<std::string, 3> a = {"cake", "bye", "air"};
    Sort<std::array<std::string, 3>, TemplateDecreasing>(a.begin(), a.end());
    EXPECT_EQ(a, (std::array<std::string, 3>{{"cake", "bye", "air"}}));
}

TEST_F(SortTest, VectorTest1) {
    std::vector<int> v = {1, 3, 5, 2, 6, 8, 4, 0};
    Sort<std::vector<int>, TemplateIncreasing>(v.begin(), v.end());
    EXPECT_EQ(v, (std::vector<int>{0, 1, 2, 3, 4, 5, 6, 8}));
}

TEST_F(SortTest, VectorTest2) {
    std::vector<int> v = {1, 3, 5, 2, 6, 8, 4, 0};
    Sort<std::vector<int>, TemplateDecreasing>(v.begin(), v.end());
    EXPECT_EQ(v, (std::vector<int>{8, 6, 5, 4, 3, 2, 1, 0}));
}

TEST_F(SortTest, VectorTest3) {
    std::vector<std::string> v = {"cake", "bye", "air"};
    Sort<std::vector<std::string>, TemplateIncreasing>(v.begin(), v.end());
    EXPECT_EQ(v, (std::vector<std::string>{"air", "bye", "cake"}));
}

TEST_F(SortTest, VectorTest4) {
    std::vector<std::string> v = {"cake", "bye", "air"};
    Sort<std::vector<std::string>, TemplateDecreasing>(v.begin(), v.end());
    EXPECT_EQ(v, (std::vector<std::string>{"cake", "bye", "air"}));
}

TEST_F(SortTest, ListTest1) {
    std::list<int> l = {1, 3, 5, 2, 6, 8, 4, 0};
    Sort<std::list<int>, TemplateIncreasing>(l.begin(), l.end());
    EXPECT_EQ(l, (std::list<int>{0, 1, 2, 3, 4, 5, 6, 8}));
}

TEST_F(SortTest, ListTest2) {
    std::list<int> l = {1, 3, 5, 2, 6, 8, 4, 0};
    Sort<std::list<int>, TemplateDecreasing>(l.begin(), l.end());
    EXPECT_EQ(l, (std::list<int>{8, 6, 5, 4, 3, 2, 1, 0}));
}

TEST_F(SortTest, ListTest3) {
    std::list<std::string> l = {"cake", "bye", "air"};
    Sort<std::list<std::string>, TemplateIncreasing>(l.begin(), l.end());
    EXPECT_EQ(l, (std::list<std::string>{"air", "bye", "cake"}));
}

TEST_F(SortTest, ListTest4) {
    std::list<std::string> l = {"cake", "bye", "air"};
    Sort<std::list<std::string>, TemplateDecreasing>(l.begin(), l.end());
    EXPECT_EQ(l, (std::list<std::string>{"cake", "bye", "air"}));
}

TEST_F(SortTest, DequeTest1) {
    std::deque<int> d = {1, 3, 5, 2, 6, 8, 4, 0};
    Sort<std::deque<int>, TemplateIncreasing>(d.begin(), d.end());
    EXPECT_EQ(d, (std::deque<int>{0, 1, 2, 3, 4, 5, 6, 8}));
}

TEST_F(SortTest, DequeTest2) {
    std::deque<int> d = {1, 3, 5, 2, 6, 8, 4, 0};
    Sort<std::deque<int>, TemplateDecreasing>(d.begin(), d.end());
    EXPECT_EQ(d, (std::deque<int>{8, 6, 5, 4, 3, 2, 1, 0}));
}

TEST_F(SortTest, DequeTest3) {
    std::deque<std::string> d = {"cake", "bye", "air"};
    Sort<std::deque<std::string>, TemplateIncreasing>(d.begin(), d.end());
    EXPECT_EQ(d, (std::deque<std::string>{"air", "bye", "cake"}));
}

TEST_F(SortTest, DequeTest4) {
    std::deque<std::string> d = {"cake", "bye", "air"};
    Sort<std::deque<std::string>, TemplateDecreasing>(d.begin(), d.end());
    EXPECT_EQ(d, (std::deque<std::string>{"cake", "bye", "air"}));
}
