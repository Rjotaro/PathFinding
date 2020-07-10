#include <iostream>
#include "node.hpp"

Node::Node() {}

Node::Node(std::shared_ptr<Point> pointPtr, std::weak_ptr<Node> parentNode) :
           pointPtr_{pointPtr},
           parentNode_{parentNode} {
             pointPtr_->inNode_ = true;
}

void Node::createChild(std::shared_ptr<Point> childPointPtr) {
  if (!childPointPtr->inNode_) {
  Node childNode(childPointPtr, weak_from_this());
  childNodes_.push_back(std::make_shared<Node>(childNode));
  }
}
