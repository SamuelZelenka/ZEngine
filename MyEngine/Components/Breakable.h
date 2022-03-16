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

	RectRenderer* renderer;
private: 
	Uint8 mapLifeColorValue(Uint8 value, Uint8 inMin, Uint8 inMax, Uint8 outMin, Uint8 outMax);
};