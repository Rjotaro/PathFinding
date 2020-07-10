#include "point.hpp"

Point::Point() {};

Point::Point(std::pair<short, short> coordinates) :
             coordinates_ {coordinates},
             inNode_ {false} {}

std::pair<short int, short int> Point::getCoordinates() {
  return coordinates_;
}

/*void Point::setPoint(short int x, short int y, bool isWalkable) {
  coordinates_.first = x;
  coordinates_.second = y;
  isWalkable_ = isWalkable;
}*/
