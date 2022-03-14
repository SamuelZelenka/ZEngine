#pragma once
#include "Collider.h"

class AABBCollider : public Collider
{
public:
	AABBCollider(GameObject* gameObject, Vector2 pos, float width, float height, bool isStatic) : Collider(gameObject, isStatic)
	{
		colliderTypeID = ColliderType::AABB;
		position = pos;
		this->width = width;
		this->height = height;
	}
	float width;
	float height;

	bool check_collision(Collider* otherCollider, Collider* hitCollider) override;
	bool check_vs_AABB(AABBCollider* collider1, AABBCollider* collider2) override;
};