#include "../Components/PlayerMovement.h"
#include "../GameObject/GameObject.h"
#include "../Input/Input.h"
#include "../GameTime.h"
#include "../Physics/RigidBody.h"
#include "../Components/RectRenderer.h"

void PlayerMovement::init()
{
	rigidBody = gameObject->get_component<RigidBody>();
	rectRenderer = gameObject->get_component<RectRenderer>();
}

void PlayerMovement::update()
{
	int speed = 1000;
	if (Input::getKey(SDL_SCANCODE_A))
	{
		rigidBody->velocity.x = -speed;
	}
	else if (Input::getKey(SDL_SCANCODE_D))
	{
		rigidBody->velocity.x = speed;
	}
	else
	{
		rigidBody->velocity.x = 0;
	}
}

void PlayerMovement::on_collision(Collider* other)
{
	rectRenderer->color = { 255,0,0,255 };
}
void PlayerMovement::on_collision_enter(Collider* other)
{
	rectRenderer->color = { 255,0,0,255 };
}
void PlayerMovement::on_collision_exit()
{
	rectRenderer->color = { 0,0,0,255 };
}