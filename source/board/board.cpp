#include "board.hpp"

Board::Board() {
  this->cols = 7;
  this->rows = 6;
  for (int i = 0; i < this->cols; i++) {
    this->table.push_back(std::vector<Cell>());
    for (int j = 0; j < this->rows; j++) {
      this->table
        .at(i)
        .push_back(Cell(i, j));
    }
  }
}

Board::~Board() {}

Cell Board::addTile(int col, State state) {
  if (this->table.at(col).front().getState() != none) {
    return Cell(-1, -1);
  }

  if (this->table.at(col).back().getState() == none) {
    this->table.at(col).back().setState(state);
    return table.at(col).back();
  }

  for (int i = 0; i < this->rows; i++) {
    if (this->table.at(col).at(i).getState() != none) {
      this->table.at(col).at(i - 1).setState(state);
      return this->table.at(col).at(i - 1);
    }
  }
  return Cell(-1, -1);
}

bool Board::inBoard(Point point) {
  return (
    point.x >= 0 && point.x < this->cols &&
    point.y >= 0 && point.y < this->rows
  );
}

std::vector<Cell> Board::getSequence(Cell centerCell, Direction direction) {
  Point point, center = Point(centerCell);
  switch (direction) {
    case horizontal:
      point = Point(1, 0);
      break;
    case vertical:
      point = Point(0, 1);
      break;
    case diagonal1:
      point = Point(1, 1);
      break;
    case diagonal2:
      point = Point(1, -1);
      break;
    default:
      break;
  }

  std::vector<Point> points = {
    center.add(-3, point),
    center.add(-2, point),
    center.add(-1, point),
    center,
    center.add(1, point),
    center.add(2, point),
    center.add(3, point)
  };

  std::vector<Cell> sequence;

  for (Point & p : points)
    if (this->inBoard(p))
      sequence.push_back(this->table.at(p.x).at(p.y));

  return sequence;
}

State Board::checkWinner(Cell lastCell) {
  State player = lastCell.getState();

  std::vector<Direction> directions = {
    horizontal,
    vertical,
    diagonal1,
    diagonal2
  };

  for (Direction & dir : directions) {
    std::vector<Cell> sequence = this->getSequence(lastCell, dir);

    int count = 0;
    for (Cell & cell : sequence) {
      if (cell.getState() == player)
        count++;
      else
        count = 0;
      
      if (count >= 4)
        return player;
    }
  }
  return none;
}

void Board::show() {
  std::cout << std::endl << "  0 1 2 3 4 5 6" << std::endl;

  for (int i = 0; i < this->rows; i++) {
    std::cout << (char)('A' + i);
    for (int j = 0; j < this->cols; j++) {
      this->table
        .at(j)
        .at(i)
        .show();
    }
    std::cout << std::endl;
  }
}

int Board::getCols() {
  return this->cols;
}

int Board::getRows() {
  return this->rows;
}