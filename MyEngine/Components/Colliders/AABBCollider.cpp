#include "AABBCollider.h"
#include "CircleCollider.h"

bool AABBCollider::CheckCollision(Collider* otherCollider, Collider* hitCollider)
{
	bool isColliding = false;

	switch ((int)colliderTypeID | (int)otherCollider->colliderTypeID)
	{

	case (int)ColliderType::AABB | (int)ColliderType::AABB:
		isColliding = check_vs_AABB(this, dynamic_cast<AABBCollider*>(otherCollider));
		break;

	case (int)ColliderType::AABB | (int)ColliderType::Circle:
		isColliding = check_vs_circle(this, dynamic_cast<CircleCollider*>(otherCollider));
		break;
	default:
		break;
	}

	hitCollider = isColliding ? otherCollider : nullptr;
	return isColliding;
}

bool Collider::check_vs_AABB(AABBCollider* collider1, AABBCollider* collider2)
{
	float col1Left = collider1->position.x;
	float col1Right = collider1->position.x + collider1->width;
	float col1Up = collider1->position.y;
	float col1Down = collider1->position.y + collider1->height;

	float col2Left = collider2->position.x;
	float col2Right = collider2->position.x + collider2->width;
	float col2Up = collider2->position.y;
	float col2Down = collider2->position.y + collider2->height;

	bool collisionRight = col1Left <= col2Right;
	bool collisionLeft = col1Right >= col2Left;
	bool collisionDown = col1Up <= col2Down;
	bool collisionUp = col1Down >= col2Up;

	bool isColliding = collisionRight && collisionLeft && collisionDown && collisionUp;

	return isColliding;
}
