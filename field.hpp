#ifndef FIELD_HPP
#define FIELD_HPP

#include <vector>
#include <memory>
#include <string>
#include "point.hpp"

class Field : std::enable_shared_from_this<Field> {
public:

  Field();
  Field(std::pair<short, short>, std::pair<short, short>, std::pair<short, short>);
  std::shared_ptr<Field> getFieldPtr();
  std::pair<short int, short int> getSize();
  Point getPoint(std::pair<short int, short int>);
  void drowField();

private:

  std::pair<short int, short int> size_;
  Point startPoint_;
  Point finishPoint_;
  std::vector<Point> wallPoints_;
  std::vector<Point> freePoints_;
  std::vector<Point> pathPoints_;
};

#endif
