//
// Created by victor on 11/03/2022.
//

#ifndef SDL_GAMECONTROLLER_H
#define SDL_GAMECONTROLLER_H

#include <ctime>
#include "Raycaster.h"
#include "Player.h"
#include <SDL2/SDL.h>
#include <chrono>

#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

class GameController {
    long lastClockTime{};
    SDL_bool forward;
    SDL_bool backward;
    SDL_bool left;
    SDL_bool right;
    SDL_bool done;
    SDL_Window *window{};
    Raycaster *raycaster{};
    SDL_Renderer *renderer{};
    Player *player{};

public:
    GameController();

    void init();

    void mainLoop();

    void manageEvents();

    void update(time_t elapsedTime);
};

void printKeyInfo(SDL_KeyboardEvent);

#endif //SDL_GAMECONTROLLER_H
