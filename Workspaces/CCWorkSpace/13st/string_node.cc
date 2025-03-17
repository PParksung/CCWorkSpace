#include "string_node.h"
#include "visitor.h"

StringNode::StringNode(std::string value, Node* left, Node* right)
    : Node(left, right), value_(value) {}

void StringNode::Visit(Visitor* visitor) {
    visitor->EnterStringNode(this);

    Node* cNode = left_;
    while (cNode != nullptr) {
        cNode->Visit(visitor);
        cNode = nullptr;
    }

    cNode = right_;
    while (cNode != nullptr) {
        cNode->Visit(visitor);
        cNode = nullptr;
    }

    visitor->ExitStringNode(this);
}

std::string StringNode::value() {
    return value_;
}
