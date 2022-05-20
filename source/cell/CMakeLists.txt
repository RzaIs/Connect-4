#creating new library
add_library(cell cell.cpp)

# importing include directory
target_include_directories(cell
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
