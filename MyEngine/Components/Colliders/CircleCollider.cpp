#include "CircleCollider.h"

bool CircleCollider::CheckCollision(Collider* otherCollider, Collider* hitCollider)
{
	bool isColliding = false;

	switch ((int)colliderTypeID | (int)otherCollider->colliderTypeID)
	{

	case (int)ColliderType::AABB | (int)ColliderType::AABB:
		isColliding = CheckAABBvsCircle(this, dynamic_cast<AABBCollider*>(otherCollider));
		break;

	case (int)ColliderType::AABB | (int)ColliderType::Circle:
		isColliding = CheckAABBvsCircle(this, dynamic_cast<CircleCollider*>(otherCollider));
		break;
	default:
		break;
	}

	hitCollider = isColliding ? otherCollider : nullptr;
	return isColliding;
}