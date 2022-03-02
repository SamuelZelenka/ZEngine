#include "GameRenderer.h"

GameRenderer::GameRenderer(SDL_Window* window)
{
	scene = SDL_CreateRenderer(window, -1, 0);
	UI = SDL_CreateRenderer(window, 1, 0);
	if (scene)
	{
		SDL_SetRenderDrawColor(scene, 255, 255, 255, 255);
	}
}
GameRenderer::~GameRenderer()
{
	clean();
}
void GameRenderer::clean()
{
	SDL_DestroyRenderer(scene);
	SDL_DestroyRenderer(UI);
}

void GameRenderer::render()
{
	SDL_SetRenderDrawColor(scene, 0xff, 0xff, 0xff, 0xff);

	SDL_RenderClear(scene);
	SDL_RenderPresent(scene);
}

void GameRenderer::render_rect(SDL_Rect* rect)
{

}