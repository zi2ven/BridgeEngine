#include "render/render.h"
#include <SDL3/SDL.h>

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

void engine_render_drawpixel(float x, float y, int color)
{
	rgba_t rgba_color = engine_render_hex2rgba(color);

	SDL_SetRenderDrawColor(renderer, rgba_color.r, rgba_color.g, rgba_color.b, rgba_color.a);

	SDL_Log("Create pixel. x = %f y = %f color = %#x rgba = (%d, %d, %d, %d)\n", x, y, color,
			rgba_color.r, rgba_color.g, rgba_color.b, rgba_color.a);

	SDL_RenderPoint(renderer, x, y);
}

void engine_render_fillrect(float ax, float ay, float width, float height, int color)
{
	rgba_t rgba_color = engine_render_hex2rgba(color);

	SDL_SetRenderDrawColor(renderer, rgba_color.r, rgba_color.g, rgba_color.b, rgba_color.a);

	SDL_FRect rect;
	rect.x = ax;
	rect.y = ay;
	rect.w = width;
	rect.h = height;

	SDL_Log("Create rect. x = %f y = %f w = %f h = %f color = %#x rgba = (%d, %d, %d, %d)\n",
			rect.x, rect.y, rect.w, rect.h, color, rgba_color.r, rgba_color.g, rgba_color.b,
			rgba_color.a);

	SDL_RenderFillRect(renderer, &rect);
}
