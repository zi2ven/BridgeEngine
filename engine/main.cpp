#include "master/master.h"
#include "publics.h"
#include "render/render.h"
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include "window/manager.h"

extern SDL_Window* window;

static void arg_parser(const int count, char* arg[])
{
    if (count > 1)
    {
        if (strcmp(arg[1], "--help") == 0 || strcmp(arg[1], "-h") == 0)
        {
            printf("BridgeEngine demo\n");
            exit(EXIT_SUCCESS);
        }
    }
}

int main(const int argc, char* argv[])
{
    arg_parser(argc, argv);

    BE::WindowManager wm;
    wm.create(800, 600, "demo");

    if (engine_init("demo", 800, 600) != 0)
    {
        SDL_Log("Exit...\n");
        SDL_Quit();
    }

    bool running = true;
    SDL_Event event;

    while (running)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_EVENT_QUIT) running = false;
        }

        engine_render_create();

        BE::render_fillrect(10, 10, 100, 100, 0x114514ff);
        BE::render_drawpixel(200, 200, 0xfffffff);

        SDL_RenderPresent(BE::renderer);
        SDL_Delay(10);
    }

    SDL_DestroyRenderer(BE::renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
