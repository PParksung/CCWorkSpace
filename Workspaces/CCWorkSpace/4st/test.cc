#include "gtest/gtest.h"
#include "int_set.h"

class IntSetTest : public ::testing::Test {
 protected:
        void SetUp() override {}
        void TearDown() override { }
};

TEST_F(IntSetTest, Test1) {
    IntSet int_set = IntSet(1);
    int_set.Add(3);
    int_set.Add(3);
    EXPECT_EQ(int_set.capacity(), 1);
    ASSERT_DEATH(int_set.Add(5), "Exceeded capacity");
}

TEST_F(IntSetTest, Test2) {
    IntSet int_set = IntSet(0);
    EXPECT_EQ(int_set.size(), 0);
    EXPECT_EQ(int_set.capacity(), 0);
    ASSERT_DEATH(int_set.Add(1), "Exceeded capacity");
}

TEST_F(IntSetTest, Test3) {
    IntSet int_set = IntSet(3);
    int_set.Add(4);
    IntSet int_set_1 = IntSet(3);
    IntSet int_set_2 = IntSet(5);
    IntSet int_set_3 = IntSet(6);
    int_set_3.Add(7);
    int_set.Add(int_set_1);
    int_set.Add(int_set_2);
    EXPECT_EQ(int_set.size(), 3);
    ASSERT_DEATH(int_set.Add(int_set_3), "Exceeded capacity");
}

TEST_F(IntSetTest, Test4) {
    IntSet int_set = IntSet(1);
    int_set.Add(3);
    int_set.Add(4);
    int_set.Add(5);
    int_set.Map([](int i){return i*2;});

    int * elements = int_set.elements();

    EXPECT_EQ(elements[0], 6);
    EXPECT_EQ(elements[1], 8);
    EXPECT_EQ(elements[2], 10);
}

TEST_F(IntSetTest, Test5) {
    IntSet int_set = IntSet(3);
    int_set.Add(3);
    int_set.Add(4);
    int_set.Add(5);
    EXPECT_EQ(int_set.ForAll([](int x){ return x > 0; }), true);
}

TEST_F(IntSetTest, Test6) {
    IntSet int_set(5);
    int_set.Add(-1);
    int_set.Add(-2);
    int_set.Add(-3);

    EXPECT_EQ(int_set.ForAll([](int x) { return x > 0; }), false);
    EXPECT_EQ(int_set.size(), 3);
}

TEST_F(IntSetTest, Test7) {
    IntSet int_set(5);
    int_set.Add(11);
    int_set.Add(22);
    int_set.Add(33);

    int_set.Map([](int i) {return i*2;});
    EXPECT_EQ(int_set.ForAll([](int x) { return x % 2 == 0; }), true);
}

TEST_F(IntSetTest, Test8) {
    IntSet int_set(3);
    int_set.Add(1);
    int_set.Add(2);

    int_set.Map([](int i) {return i*3;});
    EXPECT_EQ(int_set.ForAll([](int x) { return x > 2; }), true);
}

TEST_F(IntSetTest, Test9) {
    IntSet int_set(3);
    int_set.Add(10);
    int_set.Add(20);
    int_set.Add(30);

    int_set.Map([](int i) {return i*i;});
    EXPECT_EQ(int_set.ForAll([](int x) { return x >= 100; }), true);
}

TEST_F(IntSetTest, Test10) {
    IntSet int_set(5);
    int_set.Add(12);
    int_set.Add(24);
    int_set.Add(36);

    int_set.Map([](int i) {return i/12;});
    EXPECT_EQ(int_set.ForAll([](int x) { return x <= 3; }), true);
}

TEST_F(IntSetTest, Test11) {
    IntSet int_set(5);
    int_set.Add(1);
    int_set.Add(2);

    int_set.Map([](int i) {return i+1;});
    EXPECT_EQ(int_set.ForAll([](int x) { return x <= 2; }), false);
}

TEST_F(IntSetTest, Test12) {
    IntSet int_set(10);
    int_set.Add(4);
    int_set.Add(8);
    int_set.Add(12);
    int_set.Add(16);
    int_set.Map([](int i) {return i/3;});
    EXPECT_EQ(int_set.ForAll([](int x) { return x > 1; }), false);
    int_set.Map([](int i) {return i*2;});
    EXPECT_EQ(int_set.ForAll([](int x) { return x % 2 == 0; }), true);
    EXPECT_EQ(int_set.ForAll([](int x) { return x > 2; }), true);
}
