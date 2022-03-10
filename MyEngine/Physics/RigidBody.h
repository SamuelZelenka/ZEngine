#pragma once
#include "../Components/Component.h"
#include "../Vector/Vector2.h"
#include <vector>

using namespace std;

class Collider;

class RigidBody : public Component
{
public :
	RigidBody(GameObject* gameObject) : Component(gameObject) {};
	~RigidBody() {};
	Vector2 velocity;
	vector<Collider*> colliders;

private : 
	void init() override;
	void get_colliders();
	void update_position();
};