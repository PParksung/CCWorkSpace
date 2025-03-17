#ifndef LIST_H
#define LIST_H

class List {
 public:
    List();
    List(const List& list);
    virtual ~List();
    void operator=(const List& list);
    int size() const;
    void PushBack(int elem);
    void PushFront(int elem);
    void PopBack();
    void PopFront();
    int& At(int index);
    bool IsEmpty() const;
 private:
    struct Elem {
        int value;
        Elem* next;
    };
    Elem* head;
    int size_;
};

#endif
