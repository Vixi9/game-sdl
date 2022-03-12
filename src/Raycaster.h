//
// Created by victor on 11/03/2022.
//

#ifndef SDL_RAYCASTER_H
#define SDL_RAYCASTER_H

#include <eigen3/Eigen/Dense>
#include <SDL2/SDL.h>
#include "Player.h"

using namespace Eigen;
using namespace std;

#define FOV M_PI_4
#define VIEW_DISTANCE 300
#define RAYCASTER_RAY_INCREMENT 0.0872665

class Raycaster {
    SDL_Renderer &sdlRenderer;
    Player &player;

public:
    Raycaster(SDL_Renderer &sdlRenderer, Player &player);

    void cast();
};

#endif //SDL_RAYCASTER_H
