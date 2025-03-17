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

int IntSet::capacity() const {return capacity_;}
int IntSet::size() const {return size_;}
int* IntSet::elements() const {return elements_;}

void IntSet::Add(int value) {
    bool check = false;
    for (int i = 0; i < size_; i++) {
        if (elements_[i] == value) {
            check = true;
            break;
        }
    }
    if (check == false) {
        assert(size_ >= capacity_ && "Exceeded Capcity");
        elements_[size_] = value;
        size_++;
    }
}

void IntSet::Add(const IntSet&int_set) {
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
