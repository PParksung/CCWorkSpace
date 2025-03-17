#include "list.h"
#include <cassert>

List::List() : head(nullptr), size_(0) {}

List::List(const List& list) : head(nullptr), size_(0) {
    Elem* current = list.head;
    while (true) {
        if (current == nullptr) {
            break;
        }
        PushBack(current->value);
        current = current->next;
    }
}

List::~List() {
    while (!IsEmpty()) {
        PopFront();
    }
}

void List::operator=(const List& list) {
    while (!IsEmpty()) {
        PopFront();
    }
    Elem* current = list.head;
    while (true) {
        if (current == nullptr) {
            break;
        }
        PushBack(current->value);
        current = current->next;
    }
}

int List::size() const {
    return size_;
}

void List::PushBack(int elem) {
    Elem* new_elem = new Elem{elem, nullptr};
    if (IsEmpty()) {
        head = new_elem;
    } else {
        Elem* current = head;
        while (true) {
            if (current->next == nullptr) {
                break;
            }
            current = current->next;
        }
        current->next = new_elem;
    }
    size_++;
}

void List::PushFront(int elem) {
    Elem* new_elem = new Elem{elem, head};
    head = new_elem;
    size_++;
}

void List::PopBack() {
    assert(!IsEmpty() && "Out-of-bound");
    if (size_ == 1) {
        delete head;
        head = nullptr;
    } else {
        Elem* current = head;
        while (true) {
            if (current->next->next == nullptr) {
                break;
            }
            current = current->next;
        }
        delete current->next;
        current->next = nullptr;
    }
    size_--;
}

void List::PopFront() {
    assert(!IsEmpty() && "Out-of-bound");
    Elem* temp = head;
    head = head->next;
    delete temp;
    size_--;
}

int& List::At(int index) {
    assert(index >= 0 && index < size_ && "Out-of-bound");
    Elem* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current->value;
}

bool List::IsEmpty() const {
    return head == nullptr;
}
