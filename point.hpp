#ifndef POINT_HPP
#define POINT_HPP

#include <utility>

class Point {
public:

  Point();
  Point(std::pair<short, short>);
  std::pair<short, short> getCoordinates();
//  void setPoint(short int, short int, bool);

private:

  const std::pair<short, short> coordinates_;
  bool inNode_;
};

#endif
