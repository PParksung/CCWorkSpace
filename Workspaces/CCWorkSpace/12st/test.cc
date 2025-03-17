#include "gtest/gtest.h"
#include "vector.h"
#include "list.h"
#include "safe_int.h"
#include "empty_container_exception.h"
#include "divide_by_zero_exception.h"

class VectorStringTest : public ::testing::Test {
 protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(VectorStringTest, VectorTest1) {
    try {
        Vector<std::string> v(4);
        v.PushBack("CNU");
        EXPECT_EQ(v.size(), 1);
        EXPECT_EQ(v.capacity(), 4);
    } catch (...) {
        EXPECT_TRUE(false) << "Catch any types of exceptions.";
    }
}

TEST_F(VectorStringTest, VectorTest2) {
    try {
        Vector<std::string> v(4);
        v.PushBack("TEST");
        v.PushBack("PLEASE");
        EXPECT_EQ(v.size(), 2);
        EXPECT_EQ(v[0], "TEST");
        EXPECT_EQ(v[1], "PLEASE");
    } catch (...) {
        EXPECT_TRUE(false) << "Catch any types of exceptions.";
    }
}

TEST_F(VectorStringTest, VectorTest3) {
    try {
        Vector<std::string> v(4);
        v.PushBack("CNU");
        v.PushBack("TEST");
        v.PushBack("PLEASE");
        v.PushBack("CNU");
        v.PushBack("TEST");
        EXPECT_EQ(v.size(), 5);
        EXPECT_EQ(v.capacity(), 8);
    } catch (...) {
        EXPECT_TRUE(false) << "Catch any types of exceptions.";
    }
}

TEST_F(VectorStringTest, VectorTest4) {
    try {
        Vector<std::string> v(4);
        v.PushBack("PLEASE");
        v.PushBack("TEST");
        v.PopBack();
        EXPECT_EQ(v.size(), 1);
        EXPECT_EQ(v[0], "PLEASE");
    } catch (...) {
        EXPECT_TRUE(false) << "Catch any types of exceptions.";
    }
}

TEST_F(VectorStringTest, VectorTest5) {
    try {
        Vector<std::string> v(4);
        v[0];
    } catch (const std::out_of_range& e) {
        EXPECT_EQ(std::string(e.what()),
        std::string("The index is 0, but the size is 0"));
    } catch (...) {
        EXPECT_TRUE(false) << "Catch any types of exceptions.";
    }
}


class ListStringTest : public ::testing::Test {
 protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(ListStringTest, ListTest1) {
    try {
        List<std::string> l;
        l.PushFront("CNU");
        l.PushFront("TEST");
        l.PushFront("PLEASE");
        EXPECT_EQ(l.size(), 3);
        EXPECT_EQ(l.At(0), "PLEASE");
        EXPECT_EQ(l.At(1), "TEST");
        EXPECT_EQ(l.At(2), "CNU");
    } catch (...) {
        EXPECT_TRUE(false) << "Catch any types of exceptions.";
    }
}

TEST_F(ListStringTest, ListTest2) {
    try {
        List<std::string> l;
        l.PushFront("A");
        l.PushFront("B");
        l.PopFront();
        EXPECT_EQ(l.size(), 1);
        EXPECT_EQ(l.At(0), "A");
    } catch (...) {
        EXPECT_TRUE(false) << "Catch any types of exceptions.";
    }
}

TEST_F(ListStringTest, ListTest3) {
    try {
        List<std::string> l;
        EXPECT_EQ(l.IsEmpty(), true);
        l.PushFront("Data");
        EXPECT_EQ(l.IsEmpty(), false);
    } catch (...) {
        EXPECT_TRUE(false) << "Catch any types of exceptions.";
    }
}

TEST_F(ListStringTest, ListTest4) {
    try {
        List<std::string> l;
        l.PopFront();
    } catch (const EmptyContainerException& e) {
        EXPECT_EQ(std::string(e.what()),
        std::string("This list is empty"));
    } catch (...) {
        EXPECT_TRUE(false) << "Catch any types of exceptions.";
    }
}

TEST_F(ListStringTest, ListTest5) {
    try {
        List<std::string> l;
        l.PushFront("Peach");
        l.At(1);
    } catch (const std::out_of_range& e) {
        EXPECT_EQ(std::string(e.what()),
        std::string("The index is 1, but the size is 1"));
    } catch (...) {
        EXPECT_TRUE(false) << "Catch any types of exceptions.";
    }
}

class SafeIntTest : public ::testing::Test {
 protected:
    void SetUp() override {}
    void TearDown() override {}
};

TEST_F(SafeIntTest, SafeIntTest1) {
    try {
        SafeInt a(2147483);
        SafeInt b(1);
        a + b;
    } catch (const std::overflow_error& e) {
        EXPECT_EQ(std::string(e.what()),
        std::string("Integer overflow occurs in 2147483 + 1"));
    } catch (...) {
        EXPECT_TRUE(false) << "Catch any types of exceptions.";
    }
}

TEST_F(SafeIntTest, SafeIntTest2) {
    try {
        SafeInt a(-2147483);
        SafeInt b(1);
        a - b;
    } catch (const std::overflow_error& e) {
        EXPECT_EQ(std::string(e.what()),
        std::string("Integer overflow occurs in -2147483 - 1"));
    } catch (...) {
        EXPECT_TRUE(false) << "Catch any types of exceptions.";
    }
}

TEST_F(SafeIntTest, SafeIntTest3) {
    try {
        SafeInt a(111);
        SafeInt b(3);
        EXPECT_EQ((a * b).value(), 333);
    } catch (...) {
        EXPECT_TRUE(false) << "Catch any types of exceptions.";
    }
}

TEST_F(SafeIntTest, SafeIntTest4) {
    try {
        SafeInt a(222);
        SafeInt b(111);
        EXPECT_EQ((a / b).value(), 2);
    } catch (...) {
        EXPECT_TRUE(false) << "Catch any types of exceptions.";
    }
}

TEST_F(SafeIntTest, SafeIntTest5) {
    try {
        SafeInt a(1243);
        SafeInt b(0);
        a / b;
    } catch (const DivideByZeroException& e) {
        EXPECT_EQ(std::string(e.what()),
        std::string("Divide-by-zero exception occurs in 1243 / 0"));
    } catch (...) {
        EXPECT_TRUE(false) << "Catch any types of exceptions.";
    }
}

TEST_F(SafeIntTest, SafeIntTest6) {
    try {
        SafeInt a(1243);
        SafeInt b(0);
        a % b;
    } catch (const DivideByZeroException& e) {
        EXPECT_EQ(std::string(e.what()),
        std::string("Divide-by-zero exception occurs in 1243 % 0"));
    } catch (...) {
        EXPECT_TRUE(false) << "Catch any types of exceptions.";
    }
}
