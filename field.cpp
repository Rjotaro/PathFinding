#include <iostream>
#include <memory>
#include "field.hpp"
//#include "node.hpp"

Field::Field() {};

Field::Field(std::pair<short, short> size,
             std::pair<short, short> startCoor,
             std::pair<short, short> finishCoor) :
             size_ {size},
             startPointPtr_{std::make_shared<Point>(Point(startCoor))},
             finishPointPtr_{std::make_shared<Point>(Point(finishCoor))}
{
  freePointsPtr_.reserve(size_.first * size_.second - 2);

  for (short int i = 0; i < size_.first; i++) {
    for (short int j = 0; j < size_.second; j++) {
      if (!(std::make_pair(i, j) == startPointPtr_->getCoordinates() ||
      std::make_pair(i, j) == finishPointPtr_->getCoordinates())) {
        freePointsPtr_.push_back(std::make_shared<Point>(Point(std::make_pair(i, j))));
      }
    }
  }
}

/*std::shared_ptr<Field> Field::getFieldPtr() {
  return shared_from_this();
}*/

std::pair<short int, short int> Field::getSize() {
  return size_;
}

std::shared_ptr<Point> Field::getPointPtr(std::pair<short int, short int> coordinates) {
  if (startPointPtr_->getCoordinates() == coordinates) return startPointPtr_;
  else if (finishPointPtr_->getCoordinates() == coordinates) return finishPointPtr_;
  else {
    if (freePointsPtr_.size() > 0) {
      for(auto pointPtr : freePointsPtr_) {
        if (pointPtr->getCoordinates() == coordinates) return pointPtr;
      }
    }
    if (pathPointsPtr_.size() > 0) {
      for(auto pointPtr : pathPointsPtr_) {
        if (pointPtr->getCoordinates() == coordinates) return pointPtr;
      }
    }
    std::cout << "Point with entered coordinates doen't exist on field" << std::endl;
    return std::make_shared<Point>(Point());
  }
}

void Field::drowField() {
  for (short int i = 0; i < size_.first; i++) {
    for (short int j = 0; j < size_.second; j++) {
      if (std::make_pair(i,j) == startPointPtr_->getCoordinates()) std::cout << "s";
      else if (std::make_pair(i,j) == finishPointPtr_->getCoordinates()) std::cout << "f";
      else {
        for (auto point : wallPointsPtr_) {
          if (std::make_pair(i,j) == point->getCoordinates()) std::cout << "#";
        }
        for (auto point : freePointsPtr_) {
          if (std::make_pair(i,j) == point->getCoordinates()) std::cout << ".";
        }
        for (auto point : pathPointsPtr_) {
          if (std::make_pair(i,j) == point->getCoordinates()) std::cout << "o";
        }
      }
      if (j == size_.second - 1) {
        std::cout << std::endl;
      }
    }
  }
}
