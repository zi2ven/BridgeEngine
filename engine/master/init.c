#include "publics.h"
#include <SDL2/SDL.h>
#include <stdio.h>

int engine_init(char *title, int width, int height)
{
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("[ENGINE] **ERROR** Failed to initialize SDL: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_SHOWN);

    if (!window) {
        SDL_Log("[ENGINE] **ERROR** Failed to create window: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    return 0;
}
