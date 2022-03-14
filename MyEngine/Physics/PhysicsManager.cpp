#include "PhysicsManager.h"
#include "../Components/Colliders/Collider.h"

bool PhysicsManager::check_collision_all(Collider* movedCollider, Collider* colliderHit )
{
	
	for (int i = 0; i < dynamicColliders.size(); i++)
	{
		for (int j = i + 1; j < dynamicColliders.size(); j++)
		{
			if (&movedCollider != &dynamicColliders[j])
			{
				if (movedCollider->CheckCollision(movedCollider, dynamicColliders[j], colliderHit))
					return true;
			}
		}
		for (int j = 0; j < staticColliders.size(); j++)
		{
			if (movedCollider->CheckCollision(movedCollider, staticColliders[j], colliderHit))
			{
				return true;
			}
		}
	}
	return false;
}

void PhysicsManager::add_collider(Collider* collider)
{
	if (collider->isStatic)
	{
		staticColliders.push_back(collider);
	}
	else
	{
		dynamicColliders.push_back(collider);
	}
}