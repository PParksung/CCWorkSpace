#include "gtest/gtest.h"
#include "int_accumulator.h"
#include "float_accumulator.h"

class IntAccTest : public ::testing::Test{
 public:
    IntAccTest() : accumulator_(3) {}
 protected:
    void SetUp() override { }
    void TearDown() override { }
    int_accumulator::Accumulator accumulator_;
};

class FloatAccTest : public ::testing::Test{
 public:
    FloatAccTest() : accumulator_(2.5) {}
 protected:
    void SetUp() override { }
    void TearDown() override { }
    float_accumulator::Accumulator accumulator_;
};

TEST_F(IntAccTest, IntTest) {
    accumulator_.Add(3);
    EXPECT_EQ(accumulator_.acc(), 6);

    accumulator_.Add(5);
    EXPECT_EQ(accumulator_.acc(), 11);

    accumulator_.Add(7);
    EXPECT_EQ(accumulator_.acc(), 18);

    accumulator_.Sub(3);
    EXPECT_EQ(accumulator_.acc(), 15);

    accumulator_.Sub(5);
    EXPECT_EQ(accumulator_.acc(), 10);

    accumulator_.Sub(7);
    EXPECT_EQ(accumulator_.acc(), 3);

    accumulator_.Mul(3);
    EXPECT_EQ(accumulator_.acc(), 9);

    accumulator_.Mul(2);
    EXPECT_EQ(accumulator_.acc(), 18);

    accumulator_.Mul(1);
    EXPECT_EQ(accumulator_.acc(), 18);

    accumulator_.Div(6);
    EXPECT_EQ(accumulator_.acc(), 3);

    accumulator_.Div(3);
    EXPECT_EQ(accumulator_.acc(), 1);

    ASSERT_DEATH(accumulator_.Div(0), "Divide-by-Zero");
}

TEST_F(FloatAccTest, FloatTest) {
    accumulator_.Add(2.5);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 5.0);

    accumulator_.Add(5.5);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 10.5);

    accumulator_.Add(7.5);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 18.0);

    accumulator_.Sub(3.5);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 14.5);

    accumulator_.Sub(4.5);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 10.0);

    accumulator_.Sub(7.5);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 2.5);

    accumulator_.Mul(2);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 5.0);

    accumulator_.Mul(3);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 15.0);

    accumulator_.Mul(1);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 15.0);

    accumulator_.Div(3);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 5.0);

    accumulator_.Div(5);
    EXPECT_FLOAT_EQ(accumulator_.acc(), 1.0);

    ASSERT_DEATH(accumulator_.Div(0), "Divide-by-Zero");
}
