#include <iostream>
#include "../Game/Game.h"
#include "BallMovement.h"
#include "../GameObject/GameObject.h"
#include "../Physics/RigidBody.h"
#include "../Input/Input.h"
#include "../Physics/CollisionInfo.h"
#include "../../Components/Colliders/Collider.h"
#include "Breakable.h"

void BallMovement::init()
{
	rigidBody = gameObject->get_component<RigidBody>();
}

void BallMovement::update()
{
	if (Input::getKey(SDL_SCANCODE_SPACE))
	{
		rigidBody->velocity.x = 300;
		rigidBody->velocity.y = -300;

	}
	if (gameObject->position.x >= gameObject->game->windowWidth || gameObject->position.x <= 0)
	{
		rigidBody->velocity.x *= -1;
	}

	if (gameObject->position.y <= 0)
	{
		rigidBody->velocity.y *= -1;
	}
}

void BallMovement::on_collision(CollisionInfo* collisionInfo)
{
	if (collisionInfo->normal.x != 0 )
	{
		rigidBody->velocity.x *= -1;
	}	

	if (collisionInfo->normal.y != 0)
	{
		rigidBody->velocity.y *= -1;
	}

	Breakable* breakableComponent = collisionInfo->colliderHit->gameObject->get_component<Breakable>();
	if (breakableComponent != nullptr)
	{
		breakableComponent->hit();
	}
}

void BallMovement::on_collision_enter(CollisionInfo* collisionInfo)
{
	
}

void BallMovement::on_collision_exit()
{

}