#include "render/render.h"
#include <SDL2/SDL.h>
#include <stdio.h>

typedef struct rgba {
	int r;
	int g;
	int b;
	int a;
} rgba_t;

extern SDL_Renderer *renderer;

static rgba_t engine_render_hex2rgba(int color);

static rgba_t engine_render_hex2rgba(int color)
{
	rgba_t target;

	target.r = (color >> 24) & 0xFF;
	target.g = (color >> 16) & 0xFF;
	target.b = (color >> 8) & 0xFF;
	target.a = color & 0xFF;

	return target;
}

void engine_render_drawpixel(int x, int y, int color)
{
	rgba_t rgba_color = engine_render_hex2rgba(color);

	SDL_SetRenderDrawColor(renderer, rgba_color.r, rgba_color.g, rgba_color.b, rgba_color.a);

	SDL_Log("Create pixle. x = %d y = %d color = %#x rgba = (%d, %d, %d, %d)\n", x, y, color,
			rgba_color.r, rgba_color.g, rgba_color.b, rgba_color.a);

	SDL_RenderDrawPoint(renderer, x, y);

	return;
}

void engine_render_fillrect(int ax, int ay, int width, int height, int color)
{
	rgba_t rgba_color = engine_render_hex2rgba(color);

	SDL_SetRenderDrawColor(renderer, rgba_color.r, rgba_color.g, rgba_color.b, rgba_color.a);

	SDL_Rect rect;
	rect.x = ax;
	rect.y = ay;
	rect.w = width;
	rect.h = height;

	SDL_Log("Create rect. x = %d y = %d w = %d h = %d color = %#x rgba = (%d, %d, %d, %d)\n",
			rect.x, rect.y, rect.w, rect.h, color, rgba_color.r, rgba_color.g, rgba_color.b,
			rgba_color.a);

	SDL_RenderFillRect(renderer, &rect);

	return;
}
