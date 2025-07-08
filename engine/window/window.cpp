#include "window/window.hpp"

#include <stdexcept>

#include "SDL3/SDL_init.h"
#include "SDL3/SDL_oldnames.h"

namespace BE
{
    SdlWindow::SdlWindow(const int w, const int h, const char* title, const Uint32 flags)
    {
        static bool sdlInited = SDL_Init(SDL_INIT_VIDEO);
        if (!sdlInited) throw std::runtime_error(SDL_GetError());

        win = SDL_CreateWindow(title, w, h, flags);
        glCtx = SDL_GL_CreateContext(win);
    }

    void SdlWindow::pollEvents()
    {
        SDL_Event e;
        while (SDL_PollEvent(&e))
        {
            if (e.type == SDL_EVENT_QUIT) closed = true;
            if (e.type == SDL_EVENT_WINDOW_CLOSE_REQUESTED
                && e.window.windowID == SDL_GetWindowID(win))
                closed = true;
            /* TODO: 转发键鼠事件给 InputSystem */
        }
    }

    SdlWindow::~SdlWindow()
    {
        if (glCtx)
        {
            if (!SDL_GL_DestroyContext(glCtx))
            {
                std::fprintf(stderr, "SDL_GL_DestroyContext failed: %s\n",
                             SDL_GetError());
            }
        }
        SDL_DestroyWindow(win);
        SDL_Quit();
    }
}
