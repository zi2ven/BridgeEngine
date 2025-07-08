#include <SDL3/SDL.h>
#include "render/render.h"

namespace BE
{
    typedef struct rgba
    {
        int r;
        int g;
        int b;
        int a;
    } rgba_t;

    static rgba_t render_hex2rgba(const int color)
    {
        rgba_t target;

        target.r = (color >> 24) & 0xFF;
        target.g = (color >> 16) & 0xFF;
        target.b = (color >> 8) & 0xFF;
        target.a = color & 0xFF;

        return target;
    }

    void render_drawpixel(const float x, const float y, const int color)
    {
        const rgba_t rgba_color = render_hex2rgba(color);

        SDL_SetRenderDrawColor(renderer, rgba_color.r, rgba_color.g, rgba_color.b, rgba_color.a);

        SDL_Log("Create pixel. x = %f y = %f color = %#x rgba = (%d, %d, %d, %d)\n", x, y, color,
                rgba_color.r, rgba_color.g, rgba_color.b, rgba_color.a);

        SDL_RenderPoint(renderer, x, y);
    }

    void render_fillrect(const float ax, const float ay, const float width, const float height,
                         const int color)
    {
        const auto [r, g, b, a] = render_hex2rgba(color);

        SDL_SetRenderDrawColor(renderer, r, g, b, a);

        SDL_FRect rect;
        rect.x = ax;
        rect.y = ay;
        rect.w = width;
        rect.h = height;

        SDL_Log("Create rect. x = %f y = %f w = %f h = %f color = %#x rgba = (%d, %d, %d, %d)\n",
                rect.x, rect.y, rect.w, rect.h, color, r, g, b, a);

        SDL_RenderFillRect(renderer, &rect);
    }
} // namespace BE
