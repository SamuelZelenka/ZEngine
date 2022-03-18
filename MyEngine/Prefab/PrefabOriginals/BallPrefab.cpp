#include "../PrefabOriginals/BallPrefab.h"
#include "../../Components/BallMovement.h"
#include "../../GameObject/GameObject.h"
#include "../../Components/Colliders/AABBCollider.h"
#include "../../Components/RectRenderer.h"
#include "../../Physics/RigidBody.h"
#include "SDL.h"

void BallPrefab::construct_components(GameObject* object)
{
	SDL_Color color = { 0,0,0,255 };
	object->add_component(new AABBCollider(object, 1, 1, false));
	object->add_component(new BallMovement(object));
	object->add_component(new RigidBody(object));
	object->add_component(new RectRenderer(object, 10.0f, 10.0f, color, 2));

}