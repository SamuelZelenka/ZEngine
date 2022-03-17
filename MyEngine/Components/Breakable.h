#pragma once
#include "../Components/Component.h"
#include "../Components/RectRenderer.h"
class Breakable : public Component
{
public :
	Breakable(GameObject* gameObject, int lives);

	int lives;
	int maxLives;
	void hit();
	void init() override;

	SDL_Color color;
	RectRenderer* renderer;
private: 
	SDL_Color get_color();
	static Uint8 map_life_color_value(Uint8 value, Uint8 inMin, Uint8 inMax, Uint8 outMin, Uint8 outMax);
};