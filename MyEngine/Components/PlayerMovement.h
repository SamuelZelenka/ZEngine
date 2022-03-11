#pragma once
#include "Component.h"

class RigidBody;
class Component;

class PlayerMovement : public Component
{
public :
	PlayerMovement(GameObject* gameObject) : Component(gameObject){};
	~PlayerMovement() {};

	void init() override;
	void update() override;
private:
	RigidBody* rigidBody;
};
