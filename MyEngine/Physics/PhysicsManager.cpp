#include <iostream>
#include "PhysicsManager.h"
#include "../Components/Colliders/Collider.h"
#include "../GameObject/GameObject.h"

bool PhysicsManager::check_collision_all(Collider* movedCollider, CollisionInfo* collisionInfo)
{
	//PROBLEM: 
	//	colliders can hit multiple colliders at once when only the first is relevant
	// 
	//POSSIBLE SOLUTION:
	// 
	// Record all collisions
	// find P(T) on each edge on each collider
	// 
	// P = start point
	// V = velocity
	// T = magnitude of vector
	// 
	// 
	// P(T) = point at the magnitude of t in the direction of the velocity
	// 
	// P(T) = P + V * T
	// 
	// T is solved by 
	// 
	// Tx = other.x - this.x / velocity.x to get points on vertical lines
	// or
	// Ty = other.y - this.y / velocity.y to get points on horizontal lines
	// 
	// T = (P(Tx), P(Ty)).magnitude
	// 
	// collider with closest P(T) is hit. the other collisions are discarded to not have an unpredictable collision order.
	//

	for (int i = 0; i < dynamicColliders.size(); i++)
	{
		for (int j = i + 1; j < dynamicColliders.size(); j++)
		{
			if (movedCollider != dynamicColliders[j] && dynamicColliders[j]->gameObject->is_active())
			{
				if (movedCollider->check_collision(dynamicColliders[j], *collisionInfo))
					return true;
			}
		}
		for (int j = 0; j < staticColliders.size(); j++)
		{
			if (movedCollider->check_collision(staticColliders[j], *collisionInfo) && staticColliders[j]->gameObject->is_active())
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
