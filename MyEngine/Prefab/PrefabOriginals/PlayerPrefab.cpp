#include "../PrefabOriginals/PlayerPrefab.h"

#include "../../GameObject/GameObject.h"

#include "../../Components/Colliders/AABBCollider.h"
#include "../../Physics/RigidBody.h"
#include "../../Components/PlayerMovement.h"
#include "../../Components/RectRenderer.h"

#include "SDL.h"

void PlayerPrefab::construct_components(GameObject* object)
{
	SDL_Color color = { 255,0,0,255 };
	object->add_component(new AABBCollider(object, object->position, 75.0f, 25.0f, false));
	object->add_component(new RigidBody(object));
	object->add_component(new PlayerMovement(object));
	object->add_component(new RectRenderer(object, 75.0f, 25.0f, color, 1));
}