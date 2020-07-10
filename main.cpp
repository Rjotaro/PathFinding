#include <iostream>
#include "field.hpp"
#include "tree.hpp"

int main () {
  Field field(std::make_pair(10, 10), std::make_pair(0, 0), std::make_pair(9, 9));
  Tree tree(std::make_shared<Point>(field.getPoint(std::make_pair(0, 0))));
  tree.startNode_.createChild(std::make_shared<Point>(field.getPoint(std::make_pair(0, 1))));
  tree.startNode_.createChild(std::make_shared<Point>(field.getPoint(std::make_pair(0, 2))));
  tree.startNode_.childNodes_[0]->createChild(std::make_shared<Point>(field.getPoint(std::make_pair(0, 3))));
  std::cout << tree.startNode_.pointPtr_->getCoordinates().first << " "
  << tree.startNode_.pointPtr_->getCoordinates().second << std::endl;
  std::cout << tree.startNode_.childNodes_[0]->pointPtr_->getCoordinates().first << " "
  << tree.startNode_.childNodes_[0]->pointPtr_->getCoordinates().second << std::endl;
  std::cout << tree.startNode_.childNodes_[1]->pointPtr_->getCoordinates().first << " "
  << tree.startNode_.childNodes_[1]->pointPtr_->getCoordinates().second<< std::endl;
  std::cout << tree.startNode_.childNodes_[0]->childNodes_[0]->pointPtr_->getCoordinates().first << " "
  << tree.startNode_.childNodes_[0]->childNodes_[0]->pointPtr_->getCoordinates().second << std::endl;
  field.drowField();
  std::cout << std::endl;
  return 0;
}
