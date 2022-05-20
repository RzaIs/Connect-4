# setting minumum version for cmake
cmake_minimum_required(VERSION 3.23.1)

#setting project name
project(CONNECT4)

# setting C/C++ version
set (CMAKE_CXX_STANDARD 14)

# setting executable name
add_executable(${PROJECT_NAME} main.cpp)

# adding subdirectories
add_subdirectory(cell)
add_subdirectory(point)
add_subdirectory(board)
add_subdirectory(game)

# importing include directory
target_include_directories(${PROJECT_NAME} 
  PRIVATE game

)

# linking included libraries
target_link_libraries(${PROJECT_NAME}
  game
)
