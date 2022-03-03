#pragma once
#include "Component.h"

class Component;

class PlayerMovement : public Component
{
public :
	PlayerMovement(GameObject* gameObject) : Component(gameObject){};
	~PlayerMovement();

	void update() override;
};