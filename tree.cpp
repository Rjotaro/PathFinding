#include <memory>
#include "tree.hpp"
#include "node.hpp"
#include "field.hpp"

Tree::Tree(std::shared_ptr<Point> startPointPtr) :
           startNode_ {Node(startPointPtr, std::make_shared<Node>())} {}
