#pragma once
#include "Component.h"
#include "SDL.h"


class CircleRenderer : public Component
{
public:
	CircleRenderer(GameObject* gameObject, float radius, SDL_Color color, Uint8 layer) : Component(gameObject)
	{
		this->gameObject = gameObject;
		this->radius = radius;
		this->color = color;
		this->layer = layer;
	}
	~CircleRenderer() {};

	float radius;

	SDL_Color color;
	Uint8 layer;

	void update();

private:
	GameObject* gameObject;

};