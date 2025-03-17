#include "gtest/gtest.h"
#include "vector.h"
#include "list.h"
#include "stack.h"
#include "queue.h"

class VectorTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(VectorTest, PushBackTest1) {
    Vector v(4);
    v.PushBack(1);
    v.PushBack(2);
    v.PushBack(3);
    EXPECT_EQ(v.size(), 3);
    EXPECT_EQ(v.capacity(), 4);
}

TEST_F(VectorTest, PushBackTest2) {
    Vector v(4);
    v.PushBack(1);
    v.PushBack(2);
    v.PushBack(3);
    v.PushBack(4);
    v.PushBack(5);
    EXPECT_EQ(v.size(), 5);
    EXPECT_EQ(v.capacity(), 8);
}

TEST_F(VectorTest, PopBackTest) {
    Vector v(4);
    v.PushBack(1);
    v.PushBack(2);
    v.PushBack(3);
    v.PopBack();
    EXPECT_EQ(v.size(), 2);
    EXPECT_EQ(v.capacity(), 4);
}

TEST_F(VectorTest, IsEmptyTest) {
    Vector v(2);
    EXPECT_TRUE(v.IsEmpty());
    v.PushBack(1);
    EXPECT_FALSE(v.IsEmpty());
}

TEST_F(VectorTest, OutOfBoundTest) {
    Vector v(2);
    EXPECT_DEATH(v.PopBack(), "Out-of-bound");
}

class ListTest : public ::testing::Test {
 protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(ListTest, PushFrontTest) {
    List l;
    l.PushFront(3);
    l.PushFront(2);
    EXPECT_EQ(l.size(), 2);
    l.PushFront(1);
    EXPECT_EQ(l.size(), 3);
    EXPECT_EQ(l.At(0), 1);
    EXPECT_EQ(l.At(1), 2);
    EXPECT_EQ(l.At(2), 3);
}

TEST_F(ListTest, PushBackTest) {
    List l;
    l.PushBack(2);
    l.PushBack(3);
    EXPECT_EQ(l.size(), 2);
    l.PushBack(1);
    EXPECT_EQ(l.size(), 3);
    EXPECT_EQ(l.At(0), 2);
    EXPECT_EQ(l.At(1), 3);
    EXPECT_EQ(l.At(2), 1);
}

TEST_F(ListTest, PopFrontTest) {
    List l;
    l.PushFront(3);
    l.PushFront(2);
    l.PushFront(1);
    l.PopFront();
    EXPECT_EQ(l.size(), 2);
    EXPECT_EQ(l.At(0), 2);
    EXPECT_EQ(l.At(1), 3);
}

TEST_F(ListTest, PopBackTest) {
    List l;
    l.PushBack(1);
    l.PushBack(2);
    l.PushBack(3);
    l.PopBack();
    EXPECT_EQ(l.size(), 2);
    EXPECT_EQ(l.At(0), 1);
    EXPECT_EQ(l.At(1), 2);
}

TEST_F(ListTest, OutOfBoundTest) {
    List l;
    l.PushBack(1);
    EXPECT_DEATH(l.At(1), "Out-of-bound");
}

class StackTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(StackTest, PushTest1) {
    Stack s(5);
    s.Push(1);
    EXPECT_EQ(s.size(), 1);
    s.Push(2);
    EXPECT_EQ(s.size(), 2);
    EXPECT_EQ(s.capacity(), 5);
}

TEST_F(StackTest, PushTest2) {
    Stack s(2);
    s.Push(1);
    s.Push(2);
    s.Push(3);
    EXPECT_EQ(s.size(), 3);
    EXPECT_EQ(s.capacity(), 6);
}

TEST_F(StackTest, PopTest) {
    Stack s(5);
    s.Push(1);
    s.Push(2);
    EXPECT_EQ(s.Pop() , 2);
    EXPECT_EQ(s.size() , 1);
    EXPECT_EQ(s.capacity(), 5);
}

TEST_F(StackTest, IsEmptyTest) {
    Stack s(5);
    EXPECT_TRUE(s.IsEmpty());
    s.Push(1);
    EXPECT_FALSE(s.IsEmpty());
}

TEST_F(StackTest, OutOfBoundTest) {
    Stack s(5);
    EXPECT_DEATH(s.Pop(), "Out-of-bound");
}

class QueueTest : public ::testing::Test {
protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(QueueTest, AddTest) {
    Queue q;
    q.Add(1);
    EXPECT_EQ(q.size(), 1);
    q.Add(2);
    EXPECT_EQ(q.size(), 2);
}

TEST_F(QueueTest, PollTest) {
    Queue q;
    q.Add(1);
    q.Add(2);
    EXPECT_EQ(q.Poll(), 1);
    EXPECT_EQ(q.size(), 1);
}

TEST_F(QueueTest, IsEmptyTest) {
    Queue q;
    EXPECT_TRUE(q.IsEmpty());
    q.Add(1);
    EXPECT_FALSE(q.IsEmpty());
}

TEST_F(QueueTest, OutOfBoundTest) {
    Queue q;
    EXPECT_DEATH(q.Poll(), "Out-of-bound");
}

TEST_F(QueueTest, LastTest) {
    Queue q;
    q.Add(1);
    q.Add(2);
    q.Add(3);
    q.Add(4);
    q.Add(5);
    EXPECT_EQ(q.size(), 5);
    //1,2,3,4,5
    EXPECT_EQ(q.Poll(), 1);
    EXPECT_EQ(q.size(), 4);
    EXPECT_EQ(q.Poll(), 2);
    EXPECT_EQ(q.size(), 3);
    EXPECT_EQ(q.Poll(), 3);
    EXPECT_EQ(q.size(), 2); 
    //4,5
    q.Add(6);
    q.Add(7);
    //4,5,6,7
    EXPECT_EQ(q.size(), 4);
    EXPECT_EQ(q.Poll(), 4);
    EXPECT_EQ(q.Poll(), 5);
    EXPECT_EQ(q.size(), 2);
    //6,7
    EXPECT_EQ(q.Poll(), 6);
    EXPECT_EQ(q.size(), 1);
    //7
    EXPECT_EQ(q.Poll(), 7);
    EXPECT_TRUE(q.IsEmpty());
}
