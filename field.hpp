#ifndef FIELD_HPP
#define FIELD_HPP

#include <vector>
#include <memory>
#include <string>
#include "point.hpp"

class Field : std::enable_shared_from_this<Field> {
public:

  std::pair<short int, short int> size_;
  std::shared_ptr<Point> startPointPtr_;
  std::shared_ptr<Point> finishPointPtr_;
  std::vector<std::shared_ptr<Point>> wallPointsPtr_;
  std::vector<std::shared_ptr<Point>> freePointsPtr_;
  std::vector<std::shared_ptr<Point>> pathPointsPtr_;

  Field();
  Field(std::pair<short, short>, std::pair<short, short>, std::pair<short, short>);
//  std::shared_ptr<Field> getFieldPtr();
  std::pair<short int, short int> getSize();
  std::shared_ptr<Point> getPointPtr(std::pair<short int, short int>);
  void drowField();

private:


};

#endif
