#pragma once

struct SDL_Renderer;

namespace BE
{
    inline SDL_Renderer *renderer;

    void render_drawpixel(float x, float y, int color);

    void render_fillrect(float ax, float ay, float width, float height, int color);
} // namespace BE
