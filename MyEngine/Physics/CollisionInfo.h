#pragma once
#include "../Vector/Vector2.h"

class Collider;

struct CollisionInfo
{
public :
	CollisionInfo()
	{
	}
	Collider* colliderHit;
	Vector2 normal;
	Vector2 point;
	Vector2 delta;
	float t;
};