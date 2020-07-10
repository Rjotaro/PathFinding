#ifndef POINT_HPP
#define POINT_HPP

#include <utility>
#include <memory>

class Point {
public:
  bool inNode_;

  Point();
  Point(std::pair<short, short>);
  std::pair<short, short> getCoordinates();
//  void setPoint(short int, short int, bool);

private:
  const std::pair<short, short> coordinates_;
};

#endif
