//
// Created by victor on 11/03/2022.
//

#include "Raycaster.h"

Raycaster::Raycaster(SDL_Renderer &sdlRenderer, Player &player) : sdlRenderer(sdlRenderer), player(player) {}

void Raycaster::cast() {
    SDL_SetRenderDrawColor(&sdlRenderer, 0, 255, 0, SDL_ALPHA_OPAQUE);
    for (int i = -9; i < 9; ++i) {
        double x = player.getViewportDirection()[0] * cos(i * 0.0872665) -
                   player.getViewportDirection()[1] * sin(i * 0.0872665);
        double y = player.getViewportDirection()[0] * sin(i * 0.0872665) +
                   player.getViewportDirection()[1] * cos(i * 0.0872665);
        SDL_RenderDrawLine(&sdlRenderer, (int) player.getX(), (int) player.getY(),
                           (int) (player.getX() + x * VIEW_DISTANCE),
                           (int) (player.getY() + y * VIEW_DISTANCE));
    }
}
