#include "master/master.h"
#include "publics.h"
#include "render/render.h"
#include <SDL2/SDL.h>
#include <stdio.h>

int main(int argc, char *argv[])
{
    if (!engine_init("demo", 800, 600)) {
        printf("Error.\n");
        return 1;
    }

    SDL_CreateRenderer(window, -1, 0);

    return 0;
}
