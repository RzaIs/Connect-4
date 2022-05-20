#creating new library
add_library(point point.cpp)

# importing include directory
target_include_directories(point
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)
