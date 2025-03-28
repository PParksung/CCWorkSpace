#include "string_node.h"

StringNode::StringNode(std::string value, const Node* left, const Node* right) :
Node(left, right), value_(value) {}

const std::string StringNode::value() const {
    return value_;
}
