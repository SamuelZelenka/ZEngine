#include "GameRenderer.h"
#include "RenderBuffer/RenderBuffer.h"

GameRenderer::GameRenderer(SDL_Window* window)
{
	scene = SDL_CreateRenderer(window, -1, 0);
	renderBuffer = new RenderBuffer();
}
GameRenderer::~GameRenderer()
{
	clean();
}
void GameRenderer::clean()
{
	SDL_DestroyRenderer(scene);
}

void GameRenderer::render()
{
	SDL_SetRenderDrawColor(scene, 0x59, 0x33, 0x6b, 0xff);
	SDL_RenderClear(scene);
	renderBuffer->render();
	SDL_RenderPresent(scene);
}