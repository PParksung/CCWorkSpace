#include "tree_util.h"
#include "int_node.h"
#include "string_node.h"

TreeUtil::TreeUtil() {}

TreeUtil* TreeUtil::GetInstance() {
    static TreeUtil instance;
    return &instance;
}

const std::string TreeUtil::PreOrderTraversal(const Node* node) const {
    if (!node) {
        return "";
    }

    std::string result;
    if (const IntNode* intNode = dynamic_cast<const IntNode*>(node)) {
        result += std::to_string(intNode->value());
    } else if (const StringNode* strNode =
    dynamic_cast<const StringNode*>(node)) {
        result +=strNode->value();
    }
    std::string leftResult = PreOrderTraversal(node->left());
    std::string rightResult = PreOrderTraversal(node->right());
    if (leftResult.size() > 0) {
        if (result.size() > 0) {
            result+=",";
        }
        result+= leftResult;
    }
    if (rightResult.size() > 0) {
        if (result.size() > 0) {
            result+=",";
        }
        result+= rightResult;
    }
    return result;
}

const std::string TreeUtil::InOrderTraversal(const Node* node) const {
    if (!node) {
        return "";
    }

    std::string result;
    std::string leftResult = InOrderTraversal(node->left());
    if (leftResult.size() > 0) {
        result+= leftResult + ",";
    }

    if (const IntNode* intNode = dynamic_cast<const IntNode*>(node)) {
        result += std::to_string(intNode->value());
    } else if (const StringNode* strNode
    = dynamic_cast<const StringNode*>(node)) {
        result +=strNode->value();
    }

    std::string rightResult = InOrderTraversal(node->right());
    if (rightResult.size() > 0) {
        result+= "," + rightResult;
    }

    return result;
}

const std::string TreeUtil::PostOrderTraversal(const Node* node) const {
    if (!node) {
        return "";
    }

    std::string result;
    std::string leftResult = PostOrderTraversal(node->left());
    if (leftResult.size() > 0) {
        result+= leftResult + ",";
    }

    std::string rightResult = PostOrderTraversal(node->right());
    if (rightResult.size() > 0) {
        result+= rightResult + ",";
    }

    if (const IntNode* intNode = dynamic_cast<const IntNode*>(node)) {
        result += std::to_string(intNode->value());
    } else if (const StringNode* strNode
    = dynamic_cast<const StringNode*>(node)) {
        result +=strNode->value();
    }

    return result;
}
