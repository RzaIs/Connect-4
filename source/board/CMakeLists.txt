#creating new library
add_library(board board.cpp)

# linking included libraries
target_link_libraries(board
  cell
  point
)

# importing include directory
target_include_directories(board
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)