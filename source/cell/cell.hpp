#pragma once

#include <iostream>

typedef enum _State {red, blue, none} State;

class Cell {
private:
  int col, row;
  State state;
public:
  Cell(int col, int row);
  ~Cell();

  int getCol();
  int getRow();
  State getState();

  void setCol(int col);
  void setRow(int row);
  void setState(State state);
  void show();
};
