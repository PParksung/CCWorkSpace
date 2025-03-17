#include "gtest/gtest.h"
#include "int_set.h"

class IntSetTest : public ::testing::Test {
 protected:
        void SetUp() override {}
        void TearDown() override { }
};

TEST_F(IntSetTest, Test1) {
    IntSet int_set = IntSet(2);
    int_set.Add(3);
    EXPECT_EQ(int_set.size(), 1);
    EXPECT_EQ(int_set[0], 3);
}

TEST_F(IntSetTest, Test2) {
    IntSet int_set = IntSet(2);
    int_set.Add(3);
    int_set.Add(3);
    EXPECT_EQ(int_set.size(), 1);
}

TEST_F(IntSetTest, Test3) {
    IntSet int_set = IntSet(3);
    int_set.Add(1);
    int_set.Add(2);
    int_set.Add(3);
    EXPECT_EQ(int_set.size(), 3);
    EXPECT_EQ(int_set.capacity(), 3);
    int_set.Add(4);
    EXPECT_EQ(int_set.size(), 4);
    EXPECT_EQ(int_set.capacity(), 7);
}

TEST_F(IntSetTest, Test4) {
    IntSet int_set = IntSet(2);
    int_set.Add(1);
    int_set.Add(2);

    IntSet int_set_1 = IntSet(2);
    int_set_1.Add(3);
    int_set_1.Add(4);

    int_set.Add(int_set_1);
    EXPECT_EQ(int_set.capacity(), 6);
}

TEST_F(IntSetTest, Test5) {
    IntSet int_set = IntSet(2);
    int_set.Add(1);
    int_set.Add(2);

    IntSet int_set_1(2);
    int_set.Add(int_set_1);
    EXPECT_EQ(int_set.size(), 2);
}

TEST_F(IntSetTest, Test6) {
    IntSet int_set = IntSet(2);
    int_set.Add(1);
    IntSet int_set_1 = IntSet(5);
    int_set_1.Add(2);
    int_set_1.Add(3);
    int_set_1.Add(4);
    int_set_1.Add(5);
    int_set.Add(int_set_1);
    EXPECT_EQ(int_set.size(), 5);
    EXPECT_EQ(int_set.capacity(), 6);
}

TEST_F(IntSetTest, Test7) {
    IntSet int_set(3);
    int_set.Add(11);
    int_set.Add(22);

    EXPECT_EQ(int_set[0], 11);
    EXPECT_EQ(int_set[1], 22);
}

TEST_F(IntSetTest, Test8) {
    IntSet int_set(2);
    int_set.Add(10);

    ASSERT_DEATH(int_set[1], "Out-of-bound");
}

TEST_F(IntSetTest, Test9) {
    IntSet int_set = IntSet(2);
    int_set.Add(20);

    ASSERT_DEATH(int_set[-1], "Out-of-bound");
}
