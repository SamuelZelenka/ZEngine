#include "RigidBody.h"
#include "../GameObject/GameObject.h"
#include "../Components/Colliders/Collider.h"


void RigidBody::init()
{
	get_colliders();
}

void RigidBody::update_position()
{
	Vector2 nextPos = gameObject->position;
	for (Collider* collider : colliders)
	{
		Vector2 prevPosition = collider->position;
		collider->position.Set(prevPosition.x + velocity.x, prevPosition.y + velocity.y);
		
	}
}

void RigidBody::get_colliders()
{
	for (Collider* collider : gameObject->get_components<Collider>())
	{
		colliders.push_back(collider);
	}
}