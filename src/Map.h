//
// Created by victor on 11/03/2022.
//

#ifndef SDL_MAP_H
#define SDL_MAP_H

#include "Tile.h"

#define MAP_SIZE 16

class Map {
    Tile[MAP_SIZE][MAP_SIZE][MAP_SIZE] tiles;
public:
    Map();
};


#endif //SDL_MAP_H
