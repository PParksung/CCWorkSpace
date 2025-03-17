#include "int_set.h"
#include <assert.h>

IntSet::IntSet(int capacity)
    :capacity_(capacity), size_(0), elements_(new int[capacity_]) {}
IntSet::IntSet(const IntSet&int_set)
    :capacity_(int_set.capacity_), size_(int_set.size_),
    elements_(new int[int_set.capacity_]) {
    for (int i=0; i < size_; i++) {
        elements_[i] = int_set.elements_[i];
    }
}

IntSet::~IntSet() {
    delete [] elements_;
}

int IntSet::capacity() const {return capacity_;}
int IntSet::size() const {return size_;}
int* IntSet::elements() const {return elements_;}

int IntSet::operator[](int index) {
    assert((index <=(size_-1)&&index >= 0) && "Out-of-bound");
    return elements_[index];
}

void IntSet::Add(int value) {
    bool check = false;
    for (int i = 0; i < size_; i++) {
        if (elements_[i] == value) {
            check = true;
            break;
        }
    }
    if (check == false) {
        if (size_ >= capacity_) {
            int new_capacity = capacity_+4;
            int * new_elements = new int[new_capacity];

            for (int i =0; i < size_; i++) {
                new_elements[i] = elements_[i];
            }

            delete[] elements_;

            elements_ = new_elements;
            capacity_ = new_capacity;
        }

        elements_[size_] = value;
        size_++;
    }
}

void IntSet::Add(const IntSet&int_set) {
    int more_capacity = size_ + int_set.size_;
    if (more_capacity > capacity_) {
        int new_capacity = capacity_;

        if (capacity_ <= 4) {
            new_capacity += 4;
        } else {
            new_capacity = ((capacity_+3)/4+1)*4;
        }
        while (new_capacity < more_capacity) {
            new_capacity+=4;
        }

        int* new_elements = new int[new_capacity];

        for (int i=0; i < size_; i++) {
            new_elements[i] = elements_[i];
        }

        delete[] elements_;
        elements_ = new_elements;
        capacity_ = new_capacity;
    }
    for (int i = 0; i < int_set.size_; i++) {
        Add(int_set.elements_[i]);
    }
}

void IntSet::Map(std::function<int(int)> f) {
    for (int i = 0; i < size_; i++) {
        elements_[i] = f(elements_[i]);
    }
}

bool IntSet::ForAll(std::function<bool(int)>f) {
    for (int i = 0; i < size_; i++) {
        if (!f(elements_[i])) {
            return false;
        }
    }
    return true;
}
