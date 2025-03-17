#ifndef PREORDER_TRAVERSAL_H_
#define PREORDER_TRAVERSAL_H_

#include "visitor.h"
#include <string>

class PreorderTraversal : public Visitor {
 public:
    void EnterIntNode(IntNode* node);
    void ExitIntNode(IntNode* node);
    void EnterStringNode(StringNode* node);
    void ExitStringNode(StringNode* node);
    std::string Result();
 private:
    std::string result_;
};

#endif
