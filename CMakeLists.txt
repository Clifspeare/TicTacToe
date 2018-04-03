cmake_minimum_required(VERSION 3.9)

# project configuration
project(TicTacToe)

# compiler settings
set(CMAKE_CXX_STANDARD 14)

set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2 REQUIRED network audio graphics window system)
include_directories("${CMAKE_SOURCE_DIR}/include")

# compilation directives
add_executable(${PROJECT_NAME} src/main.cpp src/SceneNode.cpp include/SceneNode.h src/SpriteNode.cpp include/SpriteNode.h src/GameBoard.cpp include/GameBoard.h src/MarkNode.cpp include/MarkNode.h)

# linking, etc
target_link_libraries(${PROJECT_NAME} ${SFML_LIBRARIES})