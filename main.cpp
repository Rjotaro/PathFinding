#include <iostream>
#include <vector>

class Point {
public:
  virtual std::pair<short int, short int> getPoint() {
    return coordinates_;
  }
  virtual void setPoint(short int x, short int y) {
    coordinates_.first = x;
    coordinates_.second = y;
  }
protected:
  std::pair<short int, short int> coordinates_;
  bool isWalkable;
};

class StartPoint : public Point {
public:
  StartPoint(short int x, short int y) {
    coordinates_.first = x;
    coordinates_.second = y;
    bool isWalkable = true;
  }
};

class FinishPoint : public Point {
public:
  FinishPoint(short int x, short int y) {
    coordinates_.first = x;
    coordinates_.second = y;
    bool isWalkable = true;
  }
};

class WallPoint : public Point {
public:
  WallPoint(short int x, short int y) {
    coordinates_.first = x;
    coordinates_.second = y;
    bool isWalkable = false;
  }
};

class FreePoint : public Point {
public:
  FreePoint(short int x, short int y) {
    coordinates_.first = x;
    coordinates_.second = y;
    bool isWalkable = true;
  }
};

class Field {
public:
  Field(short int xsize, short int ysize,
        short int xstart, short int ystart,
        short int xfinish, short int yfinish) :
        size_{10,10},
        startPoint_(xstart,ystart),
        finishPoint_(xfinish,yfinish)
  {
    freePoints_.reserve(size_.first * size_.second - 2);
    for (short int i = 0; i < size_.first; i++) {
      for (short int j = 0; j < size_.second; j++) {
        if (!(std::make_pair(i, j) == startPoint_.getPoint() ||
        std::make_pair(i, j) == finishPoint_.getPoint())) {
          freePoints_.push_back(FreePoint(i,j));
        }
      }
    }
    DrowField();
  }
private:
  std::pair<short int, short int> size_;
  StartPoint startPoint_;
  FinishPoint finishPoint_;
  std::vector<FreePoint> freePoints_;

  void DrowField() {
    for (short int i = 0; i < size_.first; i++) {
      for (short int j = 0; j < size_.second; j++) {
        if (i == startPoint_.getPoint().first && j == startPoint_.getPoint().second) {
          std::cout << "s";
        } else if (i == finishPoint_.getPoint().first && j == finishPoint_.getPoint().second) {
          std::cout << "f";
        } else {
          for (short int k = 0; k < freePoints_.size(); k++) {
            if (i == freePoints_[k].getPoint().first && j == freePoints_[k].getPoint().second) {
              std::cout << ".";
            }
          }
        }
        if (j == size_.second - 1) {
          std::cout << std::endl;
        }
      }
    }
  }
};

int main () {
  Field field(10, 10, 0, 0, 9, 9);
  std::cout << std::endl;
  return 0;
}
