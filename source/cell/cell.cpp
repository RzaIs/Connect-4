#include "cell.hpp"

Cell::Cell(int col, int row) {
  this->col = col;
  this->row = row;
  this->state = none;
}

Cell::~Cell() {}

int Cell::getCol() {
  return this->col;
}

int Cell::getRow() {
  return this->row;
}

State Cell::getState() {
  return this->state;
}

void Cell::setCol(int col) {
  this->col = col;
}

void Cell::setRow(int row) {
  this->row = row;
}

void Cell::setState(State state) {
  this->state = state;
}

void Cell::show() {
  if (this->state == red) {
    std::cout << "\033[1;31m O\033[0m";
  } else if (this->state == blue) {
    std::cout << "\033[1;34m O\033[0m";
  } else {
    std::cout << "\033[1;37m O\033[0m";
  }
}
