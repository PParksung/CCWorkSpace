#include "queue.h"

Queue::Queue() : List() {}

Queue::Queue(const Queue& queue) : List(queue) {}

void Queue::operator=(const Queue& queue) {
    List::operator=(queue);
}

int Queue::size() const {
    return List::size();
}

void Queue::Add(int elem) {
    PushBack(elem);
}

int Queue::Poll() {
    int first_element = At(0);
    PopFront();
    return first_element;
}


bool Queue::IsEmpty() const {
    return List::IsEmpty();
}
