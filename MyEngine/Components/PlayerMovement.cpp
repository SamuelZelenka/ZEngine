#include "../Components/PlayerMovement.h"
#include "../GameObject/GameObject.h"
#include "../Input/Input.h"
#include "../GameTime.h"
#include "../Physics/RigidBody.h"
#include "../Components/RectRenderer.h"
#include "../Physics/CollisionInfo.h"
#include "../Components/Colliders/Collider.h"
#include "../Game/Game.h"
#include "../Prefab/PrefabOriginals/BallPrefab.h"

void PlayerMovement::init()
{
	rigidBody = gameObject->get_component<RigidBody>();
	rectRenderer = gameObject->get_component<RectRenderer>();
}

void PlayerMovement::update()
{


	
	if (Input::getKey(SDL_SCANCODE_SPACE))
	{
		spacePressed = true;
	}
	if (spacePressed && !Input::getKey(SDL_SCANCODE_SPACE))
	{
		gameObject->game->instantiate(new BallPrefab(), { gameObject->position.x + rectRenderer->width / 2, gameObject->position.y - 20 });
		spacePressed = false;
	}
	float speed = 500.0f;
	if (Input::getKey(SDL_SCANCODE_A) && gameObject->position.x > 0)
	{
		rigidBody->velocity.x = -speed;
	}
	else if (Input::getKey(SDL_SCANCODE_D) && gameObject->position.x + rectRenderer->width < gameObject->game->windowWidth)
	{
		rigidBody->velocity.x = speed;
	}
	else
	{
		rigidBody->velocity.x = 0;
	}
}

void PlayerMovement::on_collision(CollisionInfo* collisionInfo)
{

}
void PlayerMovement::on_collision_enter(CollisionInfo* collisionInfo)
{

}
void PlayerMovement::on_collision_exit()
{

}