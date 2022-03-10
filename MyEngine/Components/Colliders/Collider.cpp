#include "Collider.h"	
#include "../../Physics/PhysicsManager.h"


void Collider::init()
{
	gameObject->game->physicsManager->add_collider(this);
};