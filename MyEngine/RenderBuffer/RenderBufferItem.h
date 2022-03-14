#pragma once
#include "SDL.h"
#include "../Vector/Vector2.h"

class GameRenderer;
class Vector2;

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
	RenderBufferItemRect(GameRenderer* renderer, Uint8 layer, const SDL_FRect* rect, SDL_Color color) : RenderBufferItem(renderer, layer)
	{
		this->rect = *rect;
		this->color = color;
	}
	void render() override;
private:
	SDL_FRect rect;
	SDL_Color color;
};

class RenderBufferItemCircle : public RenderBufferItem
{
public:

	RenderBufferItemCircle(GameRenderer* renderer, Uint8 layer, const Vector2 center, const float radius, SDL_Color color) : RenderBufferItem(renderer, layer)
	{
		this->radius = radius;
		this->color = color;
		this->center = center;
	}
	void render() override;

private:
	float radius;

	Vector2 center;
	SDL_Color color;
};