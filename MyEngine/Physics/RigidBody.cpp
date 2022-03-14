#include "RigidBody.h"
#include "../GameObject/GameObject.h"
#include "../Components/Colliders/Collider.h"
#include "../Physics/PhysicsManager.h"
#include "../GameTime.h"
#include "../Game/game.h"


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
		Vector2 prevPosition = collider->position;
		Vector2 deltaVelocity = velocity * delta_time;
		Vector2 newPosition = gameObject->position + deltaVelocity;

		collider->position.Set(newPosition);

		Collider* collidedCollider = nullptr;

		if (gameObject->game->physicsManager->check_collision_all(collider, collidedCollider))
		{

			for (Component* component : gameObject->get_components<Component>())
			{
				if (!isColliding)
				{
					on_collision_enter(collidedCollider);
				}
				component->on_collision(collidedCollider);
			}

			isColliding = true;
			canMove = false;

			collider->position.Set(prevPosition);
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

void RigidBody::on_collision_enter(Collider* collider)
{
	cout << "Collision Enter " << endl;
}

void RigidBody::on_collision(Collider* collider)
{
	
}

void RigidBody::on_collision_exit()
{
	cout << "Collision exit " << endl;
}

void RigidBody::get_colliders()
{
	for (Collider* collider : gameObject->get_components<Collider>())
	{
		colliders.push_back(collider);
	}
}