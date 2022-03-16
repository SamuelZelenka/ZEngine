#pragma once
#include "Component.h"

class RigidBody;
class Component;
class RectRenderer;

class PlayerMovement : public Component
{
public :
	PlayerMovement(GameObject* gameObject) : Component(gameObject){};
	~PlayerMovement() {};

	void init() override;
	void update() override;
	void on_collision(CollisionInfo* collisionInfo) override;
	void on_collision_enter(CollisionInfo* collisionInfo) override;
	void on_collision_exit() override;
private:
	RigidBody* rigidBody;
	RectRenderer* rectRenderer;
};
