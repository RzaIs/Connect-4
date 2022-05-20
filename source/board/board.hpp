#pragma once

#include <vector>

#include "cell.hpp"
#include "point.hpp"

typedef enum _Direction {horizontal, vertical, diagonal1, diagonal2} Direction;

class Board {
private:
  int cols, rows;
  std::vector<std::vector<Cell>> table;
public:
  Board();
  ~Board();

  Cell addTile(int col, State state);
  bool inBoard(Point point);
  std::vector<Cell> getSequence(Cell centerCell, Direction direction);
  State checkWinner(Cell lastCell);
  void show();
  int getCols();
  int getRows();
};

