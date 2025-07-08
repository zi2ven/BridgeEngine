#pragma once
#include "SDL3/SDL_stdinc.h"
#include "SDL3/SDL_video.h"

namespace BE
{
    struct IWindow
    {
        virtual ~IWindow() = default;
        virtual void pollEvents() = 0;
        virtual bool shouldClose() const = 0;
        virtual void swapBuffers() = 0;
    };

    class SdlWindow final : public IWindow
    {
    public:
        SdlWindow(int w, int h, const char* title,
                  Uint32 flags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);
        ~SdlWindow() override;

        void pollEvents() override;
        bool shouldClose() const override { return closed; }
        void swapBuffers() override { SDL_GL_SwapWindow(win); }

        SDL_Window* native() const { return win; }

    private:
        SDL_Window* win = nullptr;
        SDL_GLContext glCtx = nullptr;
        bool closed = false;
    };
}
