#pragma once
#include "Component.h"


class RigidBody;
class Component;

class PlayerMovement : public Component
{
public :
	void init() override;
	PlayerMovement(GameObject* gameObject) : Component(gameObject){};
	~PlayerMovement();

	void update() override;
private:
	RigidBody* rigidBody;
};