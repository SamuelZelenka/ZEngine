#pragma once
#include "Component.h"
#include "SDL.h"

class Component;

class RectRenderer : public Component
{
public:

	RectRenderer(GameObject* gameObject, double width, double height, SDL_Color color, Uint8 layer) : Component(gameObject)
	{
		this->gameObject = gameObject;
		this->width = width;
		this->height = height;
		this->color = color;
		this->layer = layer;
	}

	~RectRenderer() {};

	void update();
private:
	GameObject* gameObject;
	int width;
	int height;
	SDL_Color color;
	Uint8 layer;
};