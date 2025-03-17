#include "stack.h"

Stack::Stack(std::size_t capacity) : Vector(capacity) {}

Stack::Stack(const Stack& stack) : Vector(stack) {}

void Stack::operator=(const Stack& stack) {
    Vector::operator=(stack);
}

int Stack::size() const {
    return Vector::size();
}

int Stack::capacity() const {
    return Vector::capacity();
}

void Stack::Push(int elem) {
    PushBack(elem);
}

int Stack::Pop() {
    int last_Index = size() - 1;
    int last_element = operator[](last_Index);
    PopBack();
    return last_element;
}


bool Stack::IsEmpty() const {
    return Vector::IsEmpty();
}
