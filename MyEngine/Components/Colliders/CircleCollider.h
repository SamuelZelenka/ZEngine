#pragma once
#include "Collider.h"

class CircleCollider : public Collider
{
public:
	CircleCollider(GameObject* gameObject, Vector2 pos, float radius, bool isStatic) : Collider(gameObject, isStatic)
	{
		colliderTypeID  = ColliderType::Circle;
		position = pos;
		radius = radius;
	}
private:
	float radius;
};