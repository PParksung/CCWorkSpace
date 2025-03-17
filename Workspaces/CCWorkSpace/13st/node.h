#ifndef NODE_H_
#define NODE_H_

#include <string>

class Visitor;

class Node {
 public:
    explicit Node(Node* left, Node* right);
    Node* left();
    Node* right();
    virtual void Visit(Visitor* visitor) = 0;
    virtual std::string value() = 0;
 protected:
    Node* left_;
    Node* right_;
};

#endif
