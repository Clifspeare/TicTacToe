cmake_minimum_required(VERSION 3.9)

# project configuration
project(TicTacToe)

# compiler settings
set(CMAKE_CXX_STANDARD 11)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED network audio graphics window system)

# compilation directives
add_executable(${PROJECT_NAME} main.cpp SceneNode.cpp SceneNode.h SpriteNode.cpp SpriteNode.h GameBoard.cpp GameBoard.h)

# linking, etc
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})