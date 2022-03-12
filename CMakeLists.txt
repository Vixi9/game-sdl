cmake_minimum_required(VERSION 3.21)
project(SDL)

set(CMAKE_CXX_STANDARD 23)

find_package(SDL2 REQUIRED SDL2)

add_executable(SDL src/main.cpp src/Raycaster.cpp src/Raycaster.h src/Player.cpp src/Player.h src/GameController.cpp src/GameController.h src/Map.cpp src/Map.h src/Tile.cpp src/Tile.h)

target_link_libraries(SDL PRIVATE SDL2::SDL2)