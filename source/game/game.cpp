#include "game.hpp"

Game::Game(State startingPlayer) {
  this->board = Board();
  this->turn = startingPlayer;
  this->gameRunning = true;
}

Game::~Game() {}

void Game::start() {
  this->board.show();

  while (this->gameRunning)
    this->cycle();  
}

void Game::cycle() {
  int column = this->inputColumn();
  if (column == -1) return;

  Cell placedCell = this->board.addTile(column, this->turn);

  if (placedCell.getState() == none) {
    std::cout << "The column is full!" << std::endl;
    return;
  }

  State winnerIf = this->board.checkWinner(placedCell);

  this->board.show();

  if (winnerIf == none) {
    this->turn = (this->turn == red) ? blue : red;
    return;
  } else if (winnerIf == red) {
    std::cout << "Red win!" << std::endl;
  } else if (winnerIf == blue) {
    std::cout << "Blue win!" << std::endl;
  }
  this->gameRunning = false;
}

int Game::inputColumn() {
  if (this->turn == red)
    std::cout << "player (red) - enter the col you want to insert: ";
  else
    std::cout << "player (blue) - enter the col you want to insert: ";

  int column; std::cin >> column;

  if (column < 0 || column >= this->board.getCols()) {
    std::cout << "Out of bounds!" << std::endl;
    return -1;
  }

  return column;
}
