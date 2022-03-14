#include "BallMovement.h"
#include "../GameObject/GameObject.h"
#include "../Physics/RigidBody.h"

void BallMovement::init()
{
	rigidBody = gameObject->get_component<RigidBody>();
}

void BallMovement::update()
{
	rigidBody->velocity.y = 1;
}

void BallMovement::on_collision(Collider* other)
{

}

void BallMovement::on_collision_enter(Collider* other)
{

}

void BallMovement::on_collision_exit()
{

}