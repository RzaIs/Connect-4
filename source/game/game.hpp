#pragma once

#include "board.hpp"

class Game {
private:
  Board board;
  State turn;
  bool gameRunning;
public:
  Game(State startingPlayer);
  ~Game();

  void start();
  void cycle();
  int inputColumn();
};
