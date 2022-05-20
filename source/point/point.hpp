#pragma once

#include "cell.hpp"

class Point {
public:
  int x, y;
  Point(int x, int y);
  Point(Cell cell);
  Point();
  ~Point();

  Point add(int time, Point point);
};
