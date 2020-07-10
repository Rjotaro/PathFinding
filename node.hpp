#ifndef NODE_HPP
#define NODE_HPP

#include <memory>
#include <vector>
#include "point.hpp"
#include "field.hpp"

class Node : std::enable_shared_from_this<Node> {
public:

  Node();
  Node(std::shared_ptr<Point>, std::weak_ptr<Node>);
  void createChild(std::shared_ptr<Point>);

  std::vector<std::shared_ptr<Node>> childNodes_;

  std::shared_ptr<Point> pointPtr_;
  std::weak_ptr<Node> parentNode_;
  inline static std::shared_ptr<Field> fieldPtr_;

private:


};

#endif
