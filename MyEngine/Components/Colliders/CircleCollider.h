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
	bool CheckCollision(Collider* otherCollider, Collider* hitCollider) override;
private:
	float radius;
};