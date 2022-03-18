#pragma once
#include "../Components/Component.h"

class RigidBody;
class CircleRenderer;
class ScoreTracker;

class BallMovement : public Component
{
public:

	BallMovement(GameObject* gameObject);
	~BallMovement() {};

	void init() override;
	void awake() override;
	void update() override;
	void on_collision(CollisionInfo* collisionInfo) override;
	void on_collision_enter(CollisionInfo* collisionInfo) override;
	void on_collision_exit() override;
private:
	bool isReleased;
	float speed;
	static bool firstReleased;
	RigidBody* rigidBody;
	CircleRenderer* rectRenderer;
	ScoreTracker* scoreTracker;
};