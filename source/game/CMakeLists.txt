#creating new library
add_library(game game.cpp)

# linking included libraries
target_link_libraries(game
  board
)
