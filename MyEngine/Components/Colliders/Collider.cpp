#include "Collider.h"	
#include "../../Physics/PhysicsManager.h"
#include "../../Game/game.h"

#include "AABBCollider.h"
#include "CircleCollider.h"



void Collider::init()
{
	gameObject->game->physicsManager->add_collider(this);
};

bool Collider::CheckCollision(Collider* collider1, Collider* collider2, Collider* hitCollider)
{
	Uint8 colider1Type = (Uint8)collider1->colliderTypeID;
	Uint8 colider2Type = (Uint8)collider2->colliderTypeID;

	bool isColliding = false;

	switch (colider1Type | colider2Type)
	{

	case (int)ColliderType::AABB | (int)ColliderType::AABB:
		isColliding = CheckAABBvsAABB(dynamic_cast<AABBCollider*>(collider1), dynamic_cast<AABBCollider*>(collider2));
		break;

	case (int)ColliderType::AABB | (int)ColliderType::Circle:
		isColliding = CheckAABBvsCircle(dynamic_cast<AABBCollider*>(collider1), dynamic_cast<CircleCollider*>(collider2));
		break;

	case (int)ColliderType::Circle | (int)ColliderType::Circle:
		isColliding = CheckCirclevsCircle(dynamic_cast<CircleCollider*>(collider1), dynamic_cast<CircleCollider*>(collider2));
		break;

	default:
		break;
	}

	hitCollider = isColliding ? collider2 : nullptr;
	return isColliding;
}

bool Collider::CheckAABBvsCircle(AABBCollider* AABB, CircleCollider* Circle)
{
	return false;
}

bool Collider::CheckAABBvsAABB(AABBCollider* collider1, AABBCollider* collider2)
{
	float col1Left = collider1->position.x;
	float col1Right = collider1->position.x + collider1->width;
	float col1Up = collider1->position.y;
	float col1Down = collider1->position.y + collider1->height;

	float col2Left = collider2->position.x;
	float col2Right = collider2->position.x + collider2->width;
	float col2Up = collider2->position.y;
	float col2Down = collider2->position.y + collider2->height;

	bool collisionRight = col1Left <= col2Right;
	bool collisionLeft = col1Right >= col2Left;
	bool collisionDown = col1Up <= col2Down;
	bool collisionUp = col1Down >= col2Up;

	bool isColliding = collisionRight && collisionLeft && collisionDown && collisionUp;

	return isColliding;
}

bool Collider::CheckCirclevsCircle(CircleCollider* collider1, CircleCollider* collider2)
{
	return true;
}