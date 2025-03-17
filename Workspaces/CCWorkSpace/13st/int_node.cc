#include "int_node.h"
#include "visitor.h"

IntNode::IntNode(int value, Node* left, Node* right)
    : Node(left, right), value_(value) {}

void IntNode::Visit(Visitor* visitor) {
    visitor->EnterIntNode(this);

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

    visitor->ExitIntNode(this);
}

std::string IntNode::value() {
    return std::to_string(value_);
}
