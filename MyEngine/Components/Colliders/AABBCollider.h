#pragma once
#include "Collider.h"

class AABBCollider : public Collider
{
public:
	AABBCollider(GameObject* gameObject, float width, float height, bool isStatic);

	Vector2 size;

	bool check_collision(Collider* otherCollider, CollisionInfo& collisionInfo) override;
	bool check_vs_AABB(AABBCollider& other, CollisionInfo& collisionInfo) override;
};