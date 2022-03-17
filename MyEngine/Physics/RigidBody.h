#pragma once
#include "../Components/Component.h"
#include "../Vector/Vector2.h"
#include <vector>

using namespace std;

struct CollisionInfo;
class Collider;

class RigidBody : public Component
{
public :
	RigidBody(GameObject* gameObject) : Component(gameObject) {};
	~RigidBody() {};

	Vector2 velocity;
	vector<Collider*> colliders;

	void on_collision(CollisionInfo* collisionInfo);
	void on_collision_exit();
	void on_collision_enter(CollisionInfo* collisionInfo);
	void update() override;

private : 
	bool isColliding;


	void init() override;
	void get_colliders();
	void update_position();
};