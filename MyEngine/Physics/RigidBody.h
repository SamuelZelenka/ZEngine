#pragma once
#include "../Components/Component.h"
#include "../Vector/Vector2.h"
#include <vector>

using namespace std;

class Collider;

class RigidBody : Component
{
public :
	Vector2 velocity;
	vector<Collider&> colliders;
private : 
	void get_colliders();
	void update_position();
};