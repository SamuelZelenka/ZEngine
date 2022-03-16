#include "RigidBody.h"
#include "../GameObject/GameObject.h"
#include "../Components/Colliders/Collider.h"
#include "../Physics/PhysicsManager.h"
#include "../GameTime.h"
#include "../Game/game.h"
#include "../Physics/CollisionInfo.h"


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
	bool canMove = true;
	for (Collider* collider : colliders)
	{
		Vector2 prevPosition = collider->gameObject->position;
		Vector2 deltaVelocity;
		deltaVelocity.x = velocity.x * delta_time;
		deltaVelocity.y = velocity.y * delta_time;

		Vector2 newPosition = gameObject->position + deltaVelocity;

		collider->gameObject->position.Set(newPosition);

		CollisionInfo collisionInfo;

		if (gameObject->game->physicsManager->check_collision_all(collider, &collisionInfo))
		{
			for (Component* component : gameObject->get_components<Component>())
			{
				if (!isColliding)
				{
					on_collision_enter(&collisionInfo);
				}
				component->on_collision(&collisionInfo);
			}

			isColliding = true;
			canMove = false;

			collider->gameObject->position.Set(prevPosition);
			break;
		}
		else
		{
			if (isColliding)
			{
				for (Component* component : gameObject->get_components<Component>())
				{
					component->on_collision_exit();
				}
				isColliding = false;
			}

			gameObject->position.Set(newPosition);
		}
	}
}

void RigidBody::on_collision_enter(CollisionInfo* collisionInfo)
{
	cout << "Normal X:" << collisionInfo->normal.x << endl;
	cout << "Normal Y:" << collisionInfo->normal.y << endl << endl;
}

void RigidBody::on_collision(CollisionInfo* collisionInfo)
{
	
}

void RigidBody::on_collision_exit()
{

}

void RigidBody::get_colliders()
{
	for (Collider* collider : gameObject->get_components<Collider>())
	{
		colliders.push_back(collider);
	}
}