#include "master/master.h"
#include "publics.h"
#include "render/render.h"
#include <SDL2/SDL.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>

extern SDL_Window *window;

extern SDL_Renderer *renderer;

static void arg_parser(int count, char *arg[]);

static void arg_parser(int count, char *arg[]){
    if (count > 1) {
        if (strcmp(arg[1], "--help") == 0 || strcmp(arg[1], "-h") == 0){
            printf("BridgeEngine demo\n");
            exit(EXIT_SUCCESS);
        }
    }
    return;
}

int main(int argc, char *argv[])
{
    arg_parser(argc, argv);

    if (engine_init("demo", 800, 600) != 0) {
        SDL_Log("Exit...\n");
        SDL_Quit();
    }

    engine_render_create();

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
