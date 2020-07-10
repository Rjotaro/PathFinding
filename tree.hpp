#ifndef TREE_HPP
#define TREE_HPP

#include <memory>
#include "point.hpp"
#include "node.hpp"

class Tree {
public:
  Node startNode_;
//  std::shared_ptr<Field> fieldPtr_;

  Tree(std::shared_ptr<Point>);
};

#endif
