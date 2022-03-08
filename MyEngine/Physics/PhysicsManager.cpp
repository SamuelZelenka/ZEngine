#include "PhysicsManager.h"

void PhysicsManager::check_collision_all(Collider movedCollider)
{
	for (int i = 0; i < dynamicColliders.size(); i++)
	{
		for (int j = i + 1; j < dynamicColliders.size(); j++)
		{
			if (&movedCollider != &dynamicColliders[j])
			{
				movedCollider.CheckCollision(dynamicColliders[j]);
			}
		}
		for (int j = 0; j < staticColliders.size(); j++)
		{
			movedCollider.CheckCollision(dynamicColliders[j]);
		}
	}
}