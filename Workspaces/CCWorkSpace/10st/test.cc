#include "gtest/gtest.h"
#include "vector.h"
#include "list.h"
#include "stack.h"
#include "queue.h"

class VectorStringTest : public ::testing::Test {
 protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(VectorStringTest, PushBackTest1) {
    Vector<std::string> v(4);
    v.PushBack("Cat");
    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v.capacity(), 4);
}

TEST_F(VectorStringTest, PushBackTest2) {
    Vector<std::string> v(4);
    v.PushBack("Dog");
    v.PushBack("Fish");
    v.PushBack("Bird");
    v.PushBack("Mouse");
    v.PushBack("Frog");
    EXPECT_EQ(v.size(), 5);
    EXPECT_EQ(v.capacity(), 8);
}

TEST_F(VectorStringTest, PopBackTest) {
    Vector<std::string> v(4);
    v.PushBack("Apple");
    v.PushBack("Banana");
    v.PopBack();
    EXPECT_EQ(v.size(), 1);
    EXPECT_EQ(v[0], "Apple");
}

TEST_F(VectorStringTest, IndexingTest) {
    Vector<std::string> v(4);
    v.PushBack("Orange");
    v.PushBack("Peach");
    EXPECT_EQ(v[0], "Orange");
    EXPECT_EQ(v[1], "Peach");
}

TEST_F(VectorStringTest, IsEmptyTest) {
    Vector<std::string> v(4);
    EXPECT_TRUE(v.IsEmpty());
    v.PushBack("Grape");
    EXPECT_FALSE(v.IsEmpty());
}

class ListStringTest : public ::testing::Test {
 protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(ListStringTest, PushFrontTest) {
    List<std::string> l;
    l.PushFront("Red");
    l.PushFront("Blue");
    l.PushFront("Green");
    EXPECT_EQ(l.size(), 3);
    EXPECT_EQ(l.At(0), "Green");
    EXPECT_EQ(l.At(1), "Blue");
    EXPECT_EQ(l.At(2), "Red");
}

TEST_F(ListStringTest, PushBackTest) {
    List<std::string> l;
    l.PushBack("Yellow");
    l.PushBack("Purple");
    l.PushBack("Pink");
    EXPECT_EQ(l.size(), 3);
    EXPECT_EQ(l.At(0), "Yellow");
    EXPECT_EQ(l.At(1), "Purple");
    EXPECT_EQ(l.At(2), "Pink");
}

TEST_F(ListStringTest, PopFrontTest) {
    List<std::string> l;
    l.PushFront("Lemon");
    l.PushFront("Mango");
    l.PushFront("Nectarine");
    l.PopFront();
    EXPECT_EQ(l.size(), 2);
    EXPECT_EQ(l.At(0), "Mango");
    EXPECT_EQ(l.At(1), "Lemon");
}

TEST_F(ListStringTest, PopBackTest) {
    List<std::string> l;
    l.PushBack("Kiwi");
    l.PushBack("Papaya");
    l.PushBack("Peach");
    l.PopBack();
    EXPECT_EQ(l.size(), 2);
    EXPECT_EQ(l.At(1), "Papaya");
}

TEST_F(ListStringTest, IsEmptyTest) {
    List<std::string> l;
    EXPECT_TRUE(l.IsEmpty());
    l.PushBack("Cherry");
    EXPECT_FALSE(l.IsEmpty());
}

class StackStringTest : public ::testing::Test {
 protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(StackStringTest, PushTest) {
    Stack<std::string> s(5);
    s.Push("Nut");
    EXPECT_EQ(s.size(), 1);
    s.Push("Seed");
    EXPECT_EQ(s.size(), 2);
}

TEST_F(StackStringTest, PopTest) {
    Stack<std::string> s(5);
    s.Push("Jam");
    s.Push("Honey");
    EXPECT_EQ(s.Pop(), "Honey");
    EXPECT_EQ(s.size(), 1);
}

TEST_F(StackStringTest, IsEmptyTest) {
    Stack<std::string> s(5);
    EXPECT_TRUE(s.IsEmpty());
    s.Push("Butter");
    EXPECT_FALSE(s.IsEmpty());
}

TEST_F(StackStringTest, CapacityTest) {
    Stack<std::string> s(2);
    s.Push("Egg");
    s.Push("Milk");
    s.Push("Cheese");
    EXPECT_EQ(s.size(), 3);
    EXPECT_EQ(s.capacity(), 6);
}

TEST_F(StackStringTest, OutOfBoundTest) {
    Stack<std::string> s(5);
    EXPECT_DEATH(s.Pop(), "Out-of-bound");
}

class QueueStringTest : public ::testing::Test {
 protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(QueueStringTest, AddTest) {
    Queue<std::string> q;
    q.Add("Ice");
    EXPECT_EQ(q.size(), 1);
    q.Add("Tea");
    EXPECT_EQ(q.size(), 2);
}

TEST_F(QueueStringTest, PollTest) {
    Queue<std::string> q;
    q.Add("Soda");
    q.Add("Water");
    EXPECT_EQ(q.Poll(), "Soda");
    EXPECT_EQ(q.size(), 1);
}

TEST_F(QueueStringTest, IsEmptyTest) {
    Queue<std::string> q;
    EXPECT_TRUE(q.IsEmpty());
    q.Add("Coffee");
    EXPECT_FALSE(q.IsEmpty());
}

TEST_F(QueueStringTest, MultiplePollTest) {
    Queue<std::string> q;
    q.Add("Tea");
    q.Add("Juice");
    EXPECT_EQ(q.Poll(), "Tea");
    EXPECT_EQ(q.Poll(), "Juice");
    EXPECT_TRUE(q.IsEmpty());
}

TEST_F(QueueStringTest, LastTest) {
    Queue<std::string> q;
    q.Add("Pasta");
    q.Add("Rice");
    q.Add("Bread");
    EXPECT_EQ(q.size(), 3);
    EXPECT_EQ(q.Poll(), "Pasta");
    EXPECT_EQ(q.Poll(), "Rice");
    EXPECT_EQ(q.Poll(), "Bread");
    EXPECT_TRUE(q.IsEmpty());
}
