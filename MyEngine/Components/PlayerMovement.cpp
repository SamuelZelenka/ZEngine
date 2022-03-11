#include "../Components/PlayerMovement.h"
#include "../GameObject/GameObject.h"
#include "../Input/Input.h"
#include "../GameTime.h"
#include "../Physics/RigidBody.h"

void PlayerMovement::init()
{
	rigidBody = gameObject->get_component<RigidBody>();
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