#pragma once
#include "SDL.h"

class GameRenderer
{
public :
	GameRenderer(SDL_Window* window);
	~GameRenderer();

	void render();
	void clean();
	void render_rect(SDL_Rect* rect);
private:
	SDL_Renderer* scene = nullptr;
	SDL_Renderer* UI = nullptr;
};

class RenderBufferItem
{
	virtual void render(SDL_Renderer* renderer);
};

class RenderRect : RenderBufferItem
{
public :
	void render() override
	{
		SDL_SetRenderDrawColor(scene, 180, 0, 10, 255);
		SDL_RenderFillRect(scene, rect);
	}
};


