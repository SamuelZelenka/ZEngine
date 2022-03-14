#pragma once
#include "../Components/Component.h"

class RigidBody;
class CircleRenderer;

class BallMovement : public Component
{
public:

	BallMovement(GameObject* gameObject) : Component(gameObject) {}
	~BallMovement(){}

	void init() override;
	void update() override;
	void on_collision(Collider* other) override;
	void on_collision_enter(Collider* other) override;
	void on_collision_exit() override;
private:
	RigidBody* rigidBody;
	CircleRenderer* rectRenderer;
};