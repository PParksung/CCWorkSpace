#ifndef POSTORDER_TRAVERSAL_H_
#define POSTORDER_TRAVERSAL_H_

#include "visitor.h"
#include <string>

class PostorderTraversal : public Visitor {
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
