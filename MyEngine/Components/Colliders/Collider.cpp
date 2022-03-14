#include "Collider.h"	
#include "../../Physics/PhysicsManager.h"
#include "../../Game/game.h"

#include "AABBCollider.h"
#include "CircleCollider.h"



void Collider::init()
{
	gameObject->game->physicsManager->add_collider(this);
};

bool Collider::check_collision(Collider* collider2, Collider* hitCollider)
{
	

}

bool Collider::check_vs_circle(AABBCollider* AABB, CircleCollider* Circle)
{
	return false;
}

