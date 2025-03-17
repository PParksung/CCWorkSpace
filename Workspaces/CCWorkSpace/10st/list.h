#ifndef LIST_H
#define LIST_H

#include <cassert>
template <typename T>
class List {
 public:
    List() : head(nullptr), size_(0) {}
    List(const List& list) : head(nullptr), size_(0) {
        Elem* current = list.head;
        while (true) {
            if (current == nullptr) {
                break;
            }
            PushBack(current->value);
            current = current->next;
        }
    }
    virtual ~List() {
        while (!IsEmpty()) {
            PopFront();
        }
    }
    void operator=(const List& list) {
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
    int size() const {
        return size_;
    }
    void PushBack(T elem) {
        Elem* new_elem = new Elem;
        new_elem->value = elem;
        new_elem->next = nullptr;
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
    void PushFront(T elem) {
        Elem* new_elem = new Elem;
        new_elem->value = elem;
        new_elem->next = head;
        head = new_elem;
        size_++;
    }
    void PopBack() {
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
    void PopFront() {
        assert(!IsEmpty() && "Out-of-bound");
        Elem* temp = head;
        head = head->next;
        delete temp;
        size_--;
    }
    T& At(int index) {
        assert(index >= 0 && index < size_ && "Out-of-bound");
        Elem* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }
    bool IsEmpty() const {
        return head == nullptr;
    }
 private :
    struct Elem {
        T value;
        Elem* next;
    };
    Elem* head;
    int size_;
};

#endif
