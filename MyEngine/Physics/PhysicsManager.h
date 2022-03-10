#pragma once
#include <vector>

class Collider;

using namespace std;

class PhysicsManager
{
private : 
	vector<Collider*> staticColliders;
	vector<Collider*> dynamicColliders;
	void check_collision_all(Collider* movedCollider);
};