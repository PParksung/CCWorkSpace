#include "preorder_traversal.h"
#include "int_node.h"
#include "string_node.h"

void PreorderTraversal::EnterIntNode(IntNode* node) {
    std::string node_value = node->value();
    result_ += "(Int " + node_value + ") :: ";
}

void PreorderTraversal::ExitIntNode(IntNode* node) {
}

void PreorderTraversal::EnterStringNode(StringNode* node) {
    std::string node_value = node->value();
    result_ += "(String " + node_value + ") :: ";
}

void PreorderTraversal::ExitStringNode(StringNode* node) {
}

std::string PreorderTraversal::Result() {
    if (result_.length() >= 4) {
        std::string final_result;
        int strlen = result_.length();
        for (int i=0; i < strlen - 4; i++) {
            final_result += result_[i];
        }
        return final_result;
    }
    return result_;
}
