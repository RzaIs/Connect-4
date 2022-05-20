#creating new library
add_library(point point.cpp)

# linking included libraries
target_link_libraries(point
  cell
)

# importing include directory
target_include_directories(point
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
