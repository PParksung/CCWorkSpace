#ifndef STRING_NODE_H_
#define STRING_NODE_H_

#include "node.h"
#include <string>

class Visitor;

class StringNode : public Node {
 public:
    explicit StringNode(std::string value, Node* left, Node* right);
    void Visit(Visitor* visitor);
    std::string value();
 private:
    std::string value_;
};

#endif
