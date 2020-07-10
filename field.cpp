#include <iostream>
#include <memory>
#include "field.hpp"
//#include "node.hpp"

Field::Field() {};

Field::Field(std::pair<short, short> size,
             std::pair<short, short> startCoor,
             std::pair<short, short> finishCoor) :
             size_ {size},
             startPoint_(startCoor),
             finishPoint_(finishCoor)
{
  freePoints_.reserve(size_.first * size_.second - 2);

  for (short int i = 0; i < size_.first; i++) {
    for (short int j = 0; j < size_.second; j++) {
      if (!(std::make_pair(i, j) == startPoint_.getCoordinates() ||
      std::make_pair(i, j) == finishPoint_.getCoordinates())) {
        freePoints_.push_back(Point(std::make_pair(i, j)));
      }
    }
  }
}

std::shared_ptr<Field> Field::getFieldPtr() {
  return shared_from_this();
}

std::pair<short int, short int> Field::getSize() {
  return size_;
}

Point Field::getPoint(std::pair<short int, short int> coordinates) {
  if (startPoint_.getCoordinates() == coordinates) return startPoint_;
  else if (finishPoint_.getCoordinates() == coordinates) return finishPoint_;
  else {
    if (freePoints_.size() > 0) {
      for(auto point : freePoints_) {
        if (point.getCoordinates() == coordinates) return point;
      }
    }
    if (pathPoints_.size() > 0) {
      for(auto point : pathPoints_) {
        if (point.getCoordinates() == coordinates) return point;
      }
    }
    std::cout << "Point with entered coordinates doen't exist on field" << std::endl;
    return Point();
  }
}

void Field::drowField() {
  for (short int i = 0; i < size_.first; i++) {
    for (short int j = 0; j < size_.second; j++) {
      if (std::make_pair(i,j) == startPoint_.getCoordinates()) std::cout << "s";
      else if (std::make_pair(i,j) == finishPoint_.getCoordinates()) std::cout << "f";
      else {
        for (auto point : wallPoints_) {
          if (std::make_pair(i,j) == point.getCoordinates()) std::cout << "#";
        }
        for (auto point : freePoints_) {
          if (std::make_pair(i,j) == point.getCoordinates()) std::cout << ".";
        }
        for (auto point : pathPoints_) {
          if (std::make_pair(i,j) == point.getCoordinates()) std::cout << "o";
        }
      }
      if (j == size_.second - 1) {
        std::cout << std::endl;
      }
    }
  }
}
