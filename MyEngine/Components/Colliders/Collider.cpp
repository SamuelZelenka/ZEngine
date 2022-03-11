#include "Collider.h"	
#include "../../Physics/PhysicsManager.h"
#include "../../Game/game.h"

#include "AABBCollider.h"
#include "CircleCollider.h"


void Collider::init()
{
	gameObject->game->physicsManager->add_collider(this);
};


bool Collider::CheckCollision(Collider* collider1, Collider* collider2)
{
	switch (((int)collider1->colliderTypeID | (int)collider2->colliderTypeID))
	{
	case (int)ColliderType::AABB | (int)ColliderType::AABB:
		return CheckAABBvsAABB(dynamic_cast<AABBCollider*>(collider1), dynamic_cast<AABBCollider*>(collider2));
	case (int)ColliderType::AABB | (int)ColliderType::Circle:
		return CheckAABBvsCircle(dynamic_cast<AABBCollider*>(collider1), dynamic_cast<CircleCollider*>(collider2));
	case (int)ColliderType::Circle | (int)ColliderType::Circle:
		return CheckCirclevsCircle(dynamic_cast<CircleCollider*>(collider1), dynamic_cast<CircleCollider*>(collider2));
	default:
		break;
	}
}
bool Collider::CheckAABBvsCircle(AABBCollider* AABB, CircleCollider* Circle)
{


	return false;

}
bool Collider::CheckAABBvsAABB(AABBCollider* collider1, AABBCollider* collider2)
{

	if (collider1->position.x <= collider2->position.x + collider2->width &&
		collider1->position.x + collider1->width >= collider2->position.x &&
		collider1->position.y <= collider2->position.y + collider2->height &&
		collider1->position.y + collider1->height >= collider2->position.y)
	{
		return true;
	}
	return false;
}
bool Collider::CheckCirclevsCircle(CircleCollider* collider1, CircleCollider* collider2)
{
	return true;
}