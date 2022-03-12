//
// Created by victor on 11/03/2022.
//

#include <iostream>
#include "GameController.h"

GameController::GameController() {
    forward = SDL_FALSE;
    backward = SDL_FALSE;
    left = SDL_FALSE;
    right = SDL_FALSE;
    done = SDL_FALSE;
}

void GameController::init() {
    if (SDL_Init(SDL_INIT_VIDEO) == 0) {
        window = nullptr;
        renderer = nullptr;
        if (SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_HEIGHT, 0, &window, &renderer) == 0) {
            Vector3d viewportDirection;
            viewportDirection << 1, 0, 0;
            player = new Player(WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2, 0, viewportDirection);
            raycaster = new Raycaster(*renderer, *player);
            mainLoop();
        }

        if (renderer) {
            SDL_DestroyRenderer(renderer);
        }
        if (window) {
            SDL_DestroyWindow(window);
        }
    }
    SDL_Quit();
}

void GameController::mainLoop() {
    while (!done) {
        auto start = std::chrono::high_resolution_clock::now();
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(renderer);
        raycaster->cast();
        SDL_RenderPresent(renderer);
        manageEvents();
        auto finish = std::chrono::high_resolution_clock::now();
        update(std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() / 100000);
    }
    SDL_Quit();
}

void GameController::manageEvents() {
    /* Check for events */
    SDL_Event event;
    while( SDL_PollEvent( &event ) ){
        switch( event.type ){
            case SDL_KEYDOWN:
                switch( event.key.keysym.sym ){
                    case SDLK_z:
                        forward = SDL_TRUE;
                        break;
                    case SDLK_q:
                        left = SDL_TRUE;
                        break;
                    case SDLK_s:
                        backward = SDL_TRUE;
                        break;
                    case SDLK_d:
                        right = SDL_TRUE;
                        break;
                    default:
                        break;
                }
                break;
            case SDL_KEYUP:
                switch( event.key.keysym.sym ){
                    case SDLK_z:
                        forward = SDL_FALSE;
                        break;
                    case SDLK_q:
                        left = SDL_FALSE;
                        break;
                    case SDLK_s:
                        backward = SDL_FALSE;
                        break;
                    case SDLK_d:
                        right = SDL_FALSE;
                        break;
                    default:
                        break;
                }
                break;
            case SDL_QUIT:
                done = SDL_TRUE;
                break;
        }
    }
}

void GameController::update(time_t elapsedTime) {
    Vector3d playerPosition;
    Vector3d playerDirection = player->getViewportDirection();
    if (forward) {
        playerPosition << playerDirection[0] * PLAYER_MOVE_SPEED * (double) elapsedTime, playerDirection[1] * PLAYER_MOVE_SPEED * (double) elapsedTime, 0;
    } else if (backward) {
        playerPosition << (double) -playerDirection[0] * PLAYER_MOVE_SPEED * (double) elapsedTime , (double) -playerDirection[1] * PLAYER_MOVE_SPEED * (double) elapsedTime, 0;
    }
    player->move(playerPosition[0], playerPosition[1], playerPosition[2]);
    if (left) {
        player->rotate(MOUSE_X_SENSIBILITY * (double) elapsedTime, 0);
    } else if (right) {
        player->rotate(-MOUSE_X_SENSIBILITY * (double) elapsedTime, 0);
    }
}