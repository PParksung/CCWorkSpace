#include "vector.h"
#include <cassert>
#include <iostream>

Vector::Vector(std::size_t capacity)
    : capacity_(capacity), size_(0) {
    elements_ = new int[capacity_];
}

Vector::Vector(const Vector& vector)
    : capacity_(vector.capacity_), size_(vector.size_) {
    elements_ = new int[capacity_];
    for (int i = 0; i < size_; i++) {
        elements_[i] = vector.elements_[i];
    }
}

Vector::~Vector() {
    delete[] elements_;
}

void Vector::operator=(const Vector& vector) {
    delete[] elements_;
    capacity_ = vector.capacity_;
    size_ = vector.size_;
    elements_ = new int[capacity_];
    for (int i = 0; i < size_; i++) {
        elements_[i] = vector.elements_[i];
    }
}

int& Vector::operator[](const int index) {
    assert(index >= 0 && index < size_ && "Out-of-bound");
    return elements_[index];
}

int Vector::size() const {
    return size_;
}

int Vector::capacity() const {
    return capacity_;
}

void Vector::PushBack(int elem) {
    if (size_ == capacity_) {
        int* new_elements = new int[capacity_ + 4];
        for (int i = 0; i < size_; i++) {
            new_elements[i] = elements_[i];
        }
        delete[] elements_;
        elements_ = new_elements;
        capacity_ += 4;
    }
    elements_[size_++] = elem;
}

void Vector::PopBack() {
    assert(size_ > 0 && "Out-of-bound");
    size_--;
}

bool Vector::IsEmpty() const {
    return size_ == 0;
}
