#include "../PrefabOriginals/Ball.h"
#include "../../Components/BallMovement.h"
#include "../../GameObject/GameObject.h"
#include "../../Components/Colliders/AABBCollider.h"
#include "../../Components/CircleRenderer.h"
#include "../../Physics/RigidBody.h"
#include "SDL.h"

void Ball::construct_components(GameObject* object)
{
	SDL_Color color = { 0,0,0,255 };
	object->add_component(new AABBCollider(object, 10.0f, 10.0f, false));
	object->add_component(new BallMovement(object));
	object->add_component(new RigidBody(object));
	object->add_component(new CircleRenderer(object, 10, color, 2));
}