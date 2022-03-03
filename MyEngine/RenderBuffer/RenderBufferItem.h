#pragma once
#include "SDL.h"

class GameRenderer;

class RenderBufferItem
{
public :
	RenderBufferItem(GameRenderer* renderer, Uint8 layer) 
	{
		this->renderer = renderer;
		this->layer = layer;
	};
	~RenderBufferItem() {};
	
	Uint8 layer;
	virtual void render() {};

protected :
	GameRenderer* renderer;
};

class RenderBufferItemRect : public RenderBufferItem
{
public:
	RenderBufferItemRect(GameRenderer* renderer, Uint8 layer, const SDL_Rect* rect, SDL_Color color) : RenderBufferItem(renderer, layer)
	{
		this->rect = *rect;
		this->color = color;
	}
	void render() override;
private:
	SDL_Rect rect;
	SDL_Color color;
};