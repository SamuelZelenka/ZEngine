#pragma once
#include <vector>

class Collider;

using namespace std;

class PhysicsManager
{
public :
	bool check_collision_all(Collider* movedCollider);
	void add_collider(Collider* collider);
private : 
	vector<Collider*> staticColliders;
	vector<Collider*> dynamicColliders;
	
};