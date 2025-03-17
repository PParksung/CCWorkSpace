#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

template <typename T>
class Vector {
 public:
    explicit Vector(std::size_t capacity)
    : capacity_(capacity), size_(0) {
      elements_ = new T[capacity_];
    }
    Vector(const Vector& vector)
    : capacity_(vector.capacity_), size_(vector.size_) {
      elements_ = new T[capacity_];
         for (int i = 0; i < size_; i++) {
         elements_[i] = vector.elements_[i];
         }
      }
    virtual ~Vector() {
      delete[] elements_;
    }
    void operator=(const Vector& vector) {
      delete[] elements_;
      capacity_ = vector.capacity_;
      size_ = vector.size_;
      elements_ = new T[capacity_];
      for (int i = 0; i < size_; i++) {
        elements_[i] = vector.elements_[i];
      }
    }
    T& operator[](const int index) {
    assert(index >= 0 && index < size_ && "Out-of-bound");
    return elements_[index];
    }
    int size() const {
    return size_;
    }
    int capacity() const {
    return capacity_;
    }
    void PushBack(T elem) {
      if (size_ == capacity_) {
        T* new_elements = new T[capacity_ + 4];
        for (int i = 0; i < size_; i++) {
            new_elements[i] = elements_[i];
        }
        delete[] elements_;
        elements_ = new_elements;
        capacity_ += 4;
      }
      elements_[size_++] = elem;
    }
    void PopBack() {
    assert(size_ > 0 && "Out-of-bound");
    size_--;
    }
    bool IsEmpty() const {
    return size_ == 0;
    }

 private:
    T* elements_;
    int capacity_;
    int size_;
};

#endif
