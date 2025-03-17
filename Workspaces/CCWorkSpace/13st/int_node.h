#ifndef INT_NODE_H_
#define INT_NODE_H_

#include "node.h"
#include <string>

class Visitor;

class IntNode : public Node {
 public:
    explicit IntNode(int value, Node* left, Node* right);
    void Visit(Visitor* visitor);
    std::string value();
 private:
    int value_;
};

#endif
