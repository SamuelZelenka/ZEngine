#include "Breakable.h"
#include "../GameObject/GameObject.h"

Breakable::Breakable(GameObject* gameObject, int lives) : Component(gameObject)
{
	this->lives = lives;
	maxLives = lives;
	renderer = gameObject->get_component<RectRenderer>();
}


void Breakable::hit()
{
	lives--;
	if (lives <= 0)
	{
		*gameObject->enabled = false;
		return;
	}



	Uint8 colorValue = mapLifeColorValue(maxLives / lives, 0, maxLives, 0, 255);
	renderer->color = { colorValue ,colorValue ,colorValue ,255 };
}

Uint8 Breakable::mapLifeColorValue(Uint8 value, Uint8 inMin, Uint8 inMax, Uint8 outMin, Uint8 outMax)
{
	return (value - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}