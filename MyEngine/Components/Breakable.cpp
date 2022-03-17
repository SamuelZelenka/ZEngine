#include <iostream>
#include "Breakable.h"
#include "../GameObject/GameObject.h"

Breakable::Breakable(GameObject* gameObject, int lives) : Component(gameObject)
{
	maxLives = lives;
	srand((int)gameObject);
	this->lives = 2 + (rand() % maxLives - 1);

}

void Breakable::init()
{
	renderer = gameObject->get_component<RectRenderer>();
	renderer->color = get_color();
}

void Breakable::hit()
{
	lives--;
	std::cout << "hit" << endl;
	if (lives <= 0)
	{
		gameObject->set_active(false);
		return;
	}
	renderer->color = get_color();
}

SDL_Color Breakable::get_color()
{
	return  { map_life_color_value(lives, 0, maxLives, 0, 255),0,0,255 };
}

Uint8 Breakable::map_life_color_value(Uint8 value, Uint8 inMin, Uint8 inMax, Uint8 outMin, Uint8 outMax)
{
	return (value - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}