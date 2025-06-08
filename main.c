#include "master/master.h"
#include "publics.h"
#include "render/render.h"
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdio.h>

extern SDL_Window *window;

SDL_Renderer *renderer = NULL;

int main(int argc, char *argv[])
{
    if (engine_init("demo", 800, 600) != 0) {
        SDL_Log("Exit...\n");
        SDL_Quit();
    }

    renderer = SDL_CreateRenderer(window, -1, 0);   // Create renderer

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);      // Clear renderer
    SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);  // Set blend mode
    SDL_RenderPresent(renderer);

    engine_render_fillrect(10, 10, 100, 100, 0x114514ff);
    engine_render_drawpixel(200, 200, 0xffffffff);

    bool running = true;
    SDL_Event event;

    while (running) {
        if (running == false) break;    // Dead

        if (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) running = false;    // Quit button event
        }

        SDL_RenderPresent(renderer);    // Update renderer
        SDL_Delay(10);      // FPS control
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
