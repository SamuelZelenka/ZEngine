
#include "AABBCollider.h"
#include "../../Physics/RigidBody.h"
#include "../../GameObject/GameObject.h"
#include "../../Time/GameTime.h"
#include "../../Physics/CollisionInfo.h"
#include <math.h>

AABBCollider::AABBCollider(GameObject* gameObject, float width, float height, bool isStatic) : Collider(gameObject, isStatic)
{
	colliderType = ColliderType::AABB;
	size = { width, height };
}

bool AABBCollider::check_collision(Collider* otherCollider, CollisionInfo& collisionInfo)
{
	bool isColliding = false;

	if (((int)colliderType | (int)otherCollider->colliderType) == ((int)ColliderType::AABB | (int)ColliderType::AABB))
	{
		AABBCollider* otherAABB = dynamic_cast<AABBCollider*>(otherCollider);
		isColliding = check_vs_AABB(*otherAABB, collisionInfo);
	}

	collisionInfo.colliderHit = isColliding ? otherCollider : nullptr;
	return isColliding;
}

bool AABBCollider::check_vs_AABB(AABBCollider& other, CollisionInfo& collisionInfo)
{
	Vector2 thisPos = this->gameObject->position;
	Vector2 otherPos = other.gameObject->position;

	const float thisWidth = this->size.x;
	const float thisHeight = this->size.y;

	const float otherWidth = other.size.x;
	const float otherHeight = other.size.y;

	const bool collisionRight = thisPos.x - 0.1f <= (otherPos.x + otherWidth);
	const bool collisionDown = thisPos.y <= (otherPos.y + otherHeight);
	const bool collisionLeft = otherPos.x - 0.1f <= (thisPos.x + thisWidth);
	const bool collisionUp = otherPos.y <= (thisPos.y + thisHeight);

	const bool isColliding = collisionRight && collisionLeft && collisionDown && collisionUp;

	collisionInfo.t = INFINITY;

	if (isColliding)
	{
		Vector2 deltaPosition = otherPos - thisPos;

		float xDot = Vector2::dot(deltaPosition, { 1,0 });
		float yDot = Vector2::dot(deltaPosition, { 0,1 });

		if (abs(xDot) > abs(yDot))
		{
			collisionInfo.normal = { 1,0 };
			collisionInfo.normal.x *= (float)((0 < xDot) - (xDot < 0));
		}
		else
		{
			collisionInfo.normal = { 0,1 };
			collisionInfo.normal.y *= (float)((0 < yDot) - (yDot < 0));
		}
	}
	return isColliding;
}

