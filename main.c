#include "master/master.h"
#include "publics.h"
#include "render/render.h"
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

extern SDL_Window *window;

int main(int argc, char *argv[])
{
    if (!engine_init("demo", 800, 600)) {
        printf("Error.\n");
        return 1;
    }

    SDL_CreateRenderer(window, -1, 0);

    bool running = 1;
    SDL_Event *event = NULL;

    while (running) {
        if (!running) return 0;

        SDL_PollEvent(event);
    }

    return 0;
}
