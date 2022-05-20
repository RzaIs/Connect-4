#include "point.hpp"

Point::Point(int x, int y) {
  this->x = x;
  this->y = y;
}

Point::Point(Cell cell) {
  Point(cell.getCol(), cell.getRow());
}

Point::Point() {
  Point(0, 0);
}
Point::~Point() {}

Point Point::add(int time, Point point) {
  return Point(this->x + point.x * time, this->y + point.y * time);
}