#include "../Components/PlayerMovement.h"
#include "../GameObject/GameObject.h"
#include "../Input/Input.h"
#include "../GameTime.h"

void PlayerMovement::update()
{
	if (Input::getKey(SDL_SCANCODE_A))
	{
		int speed = 1000 * deltatime;
		gameObject->position.x -= speed;
	}
	if (Input::getKey(SDL_SCANCODE_D))
	{
		int speed = 1000 * deltatime;
		gameObject->position.x += speed;
	}

	if (Input::getKey(SDL_SCANCODE_W))
	{
		int speed = 1000 * deltatime;
		gameObject->position.y -= speed;
	}
	if (Input::getKey(SDL_SCANCODE_S))
	{
		int speed = 1000 * deltatime;
		gameObject->position.y += speed;
	}
}