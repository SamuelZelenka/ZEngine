#pragma once
#include "SDL.h"

class RenderBuffer;

class GameRenderer
{
public :
	GameRenderer(SDL_Window* window);
	~GameRenderer();

	SDL_Renderer* scene = nullptr;
	RenderBuffer* renderBuffer;

	void render();
	void clean();
};

