#include "postorder_traversal.h"
#include "int_node.h"
#include "string_node.h"

void PostorderTraversal::EnterIntNode(IntNode* node) {
}

void PostorderTraversal::ExitIntNode(IntNode* node) {
    std::string node_value = "(Int " + node->value() + ") :: ";
    result_ += node_value;
}

void PostorderTraversal::EnterStringNode(StringNode* node) {
}

void PostorderTraversal::ExitStringNode(StringNode* node) {
    std::string node_value = "(String " + node->value() + ") :: ";
    result_ += node_value;
}

std::string PostorderTraversal::Result() {
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
