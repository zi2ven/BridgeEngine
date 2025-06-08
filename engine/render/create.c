#include "render/render.h"
#include <SDL2/SDL.h>

extern SDL_Window *window;

SDL_Renderer *renderer = NULL;

void engine_render_create(void)
{
	renderer = SDL_CreateRenderer(window, -1, 0); // Create renderer

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderClear(renderer);								   // Clear renderer
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND); // Set blend mode
	SDL_RenderPresent(renderer);
}
