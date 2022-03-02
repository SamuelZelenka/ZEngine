#pragma once
#include "Component.h"

class Component;

class RectRenderer : public Component
{
public:

	RectRenderer(GameObject* gameObject, double width, double height) : Component(gameObject)
	{
		this->gameObject = gameObject;
		this->width = width;
		this->height = height;
	}

	~RectRenderer();

	void update();
private:
	GameObject* gameObject;
	double width;
	double height;
};