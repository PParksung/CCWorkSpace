#ifndef _STRING_NODE_H_
#define _STRING_NODE_H_

#include <iostream>
#include "node.h"
#include <string>

class StringNode: public Node {
 public:
    explicit StringNode(std::string value, const Node* left, const Node* righy);
    const std::string value() const;
 private:
    const std::string value_;
};

#endif  //  _STRING_NODE_H_
