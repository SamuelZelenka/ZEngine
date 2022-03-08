#include "RigidBody.h"
#include "../GameObject/GameObject.h"

void RigidBody::update_position()
{
	Vector2 nextPos = gameObject->position;
	

}

void RigidBody::get_colliders()
{
	colliders = gameObject->get_components<Collider>();
}