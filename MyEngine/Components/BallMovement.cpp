#include <iostream>
#include <stdlib.h>

#include "../Game/Game.h"
#include "BallMovement.h"
#include "../GameObject/GameObject.h"
#include "../Physics/RigidBody.h"
#include "../Input/Input.h"
#include "../Physics/CollisionInfo.h"
#include "../../Components/Colliders/Collider.h"
#include "../Prefab/PrefabOriginals/BallPrefab.h"
#include "Breakable.h"
#include "PlayerMovement.h"


BallMovement::BallMovement(GameObject* gameObject) : Component(gameObject){}

void BallMovement::init()
{
	isReleased = false;
	speed = 300;
	rigidBody = gameObject->get_component<RigidBody>();
}
void BallMovement::awake()
{

}
void BallMovement::update()
{
	if (!isReleased)
	{
		rigidBody->velocity = { 0, speed };
		isReleased = true;	
	}

	if (gameObject->position.x >= gameObject->game->windowWidth || gameObject->position.x <= 0)
	{
		rigidBody->velocity.x *= -1;
	}

	if (gameObject->position.y <= 0)
	{
		rigidBody->velocity.y *= -1;
	}
	if (gameObject->position.y > gameObject->game->windowHeight)
	{
		//Remove Ball
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
	PlayerMovement* player = collisionInfo->colliderHit->gameObject->get_component<PlayerMovement>();

	if (breakableComponent != nullptr)
	{
		breakableComponent->hit();
		gameObject->game->add_score(1);
	}
	if (player != nullptr)
	{
		Vector2 playerCenter;
			
		playerCenter.x = player->gameObject->position.x + player->rectRenderer->width / 2;
		playerCenter.y = player->gameObject->position.y + player->rectRenderer->height / 2;

		Vector2 newdir = (gameObject->position - playerCenter).normalized();
		rigidBody->velocity = newdir * speed;
	}
}

void BallMovement::on_collision_enter(CollisionInfo* collisionInfo)
{
	
}

void BallMovement::on_collision_exit()
{

}