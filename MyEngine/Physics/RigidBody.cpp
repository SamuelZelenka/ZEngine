#include "RigidBody.h"
#include "../GameObject/GameObject.h"
#include "../Components/Colliders/Collider.h"
#include "../Physics/PhysicsManager.h"
#include "../GameTime.h"


void RigidBody::init()
{
	get_colliders();
	velocity.x = 0;
	velocity.y = 0;
}
void RigidBody::update()
{
	if (velocity.magnitude() != 0)
	{
		update_position();
	}
}

void RigidBody::update_position()
{
	Vector2 deltaVelocity = velocity * delta_time;
	for (Collider* collider : colliders)
	{
		Vector2 prevPosition = collider->position;
		Vector2 newPosition = gameObject->position + deltaVelocity;


		collider->position.Set(newPosition);

		if (gameObject->game->physicsManager->check_collision_all(collider))
		{
			collider->position.Set(prevPosition);
		}
		else
		{
			gameObject->position.Set(newPosition);
		}
	}
}

void RigidBody::get_colliders()
{
	for (Collider* collider : gameObject->get_components<Collider>())
	{
		colliders.push_back(collider);
	}
}