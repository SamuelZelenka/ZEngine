#include <iostream>
#include "PhysicsManager.h"
#include "../Components/Colliders/Collider.h"
#include "../GameObject/GameObject.h"

bool PhysicsManager::check_collision_all(Collider* movedCollider, CollisionInfo* collisionInfo)
{
	
	for (int i = 0; i < dynamicColliders.size(); i++)
	{
		for (int j = i + 1; j < dynamicColliders.size(); j++)
		{
			if (movedCollider != dynamicColliders[j] && *dynamicColliders[j]->gameObject->enabled)
			{
				if (movedCollider->check_collision(dynamicColliders[j], *collisionInfo))
					return true;
			}
		}
		for (int j = 0; j < staticColliders.size(); j++)
		{
			if (movedCollider->check_collision(staticColliders[j], *collisionInfo) && *staticColliders[j]->gameObject->enabled)
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