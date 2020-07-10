#include <iostream>
#include "field.hpp"
#include "tree.hpp"

int main () {
  Field field(std::make_pair(10, 10), std::make_pair(0, 0), std::make_pair(9, 9));
  Tree tree(field.getPointPtr(std::make_pair(0, 0)));
  std::cout << std::endl;
  return 0;
}
