#include "Collider.h"

bool AABBCollider::CheckCollision(Collider* other)
{
	if (dynamic_cast<AABBCollider*>(other))
	{
		AABBCollider collider = *dynamic_cast<AABBCollider*>(other);
		if (position.x <= collider.position.x + collider.width &&
			position.x + width >= collider.position.x &&
			position.y <= collider.position.y + collider.height &&
			position.y + height >= collider.position.y)
		{
			return true;
		}
	}

	return false;
}