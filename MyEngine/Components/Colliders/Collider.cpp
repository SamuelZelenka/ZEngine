#include "Collider.h"	
#include "../../Physics/PhysicsManager.h"
#include "../../Game/game.h"

#include "../../GameObject/GameObject.h"

void Collider::init()
{
	gameObject->game->physicsManager->add_collider(this);
};
