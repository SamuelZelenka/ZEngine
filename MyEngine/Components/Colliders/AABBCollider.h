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
};