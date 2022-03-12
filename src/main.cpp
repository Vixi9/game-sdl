#include <SDL2/SDL.h>
#include "Raycaster.h"
#include "GameController.h"

/* Function Prototypes */
void PrintKeyInfo( SDL_KeyboardEvent *key );

int main(int argc, char* argv[]) {
    auto *gameController = new GameController();
    gameController->init();
    return 0;
}
