#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

class Vector {
 public:
    explicit Vector(std::size_t capacity);
    Vector(const Vector& vector);
    virtual ~Vector();
    void operator=(const Vector& vector);
    int& operator[](const int index);
    int size() const;
    int capacity() const;
    void PushBack(int elem);
    void PopBack();
    bool IsEmpty() const;
 private:
    int* elements_;
    int capacity_;
    int size_;
};

#endif
