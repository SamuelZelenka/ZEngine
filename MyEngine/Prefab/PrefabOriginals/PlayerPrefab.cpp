#include "../PrefabOriginals/PlayerPrefab.h"

#include "../../GameObject/GameObject.h"

#include "../../Components/Colliders/AABBCollider.h"
#include "../../Physics/RigidBody.h"
#include "../../Components/PlayerMovement.h"
#include "../../Components/RectRenderer.h"

#include "SDL.h"

void PlayerPrefab::construct_components(GameObject* object)
{
	enabled = true;
	SDL_Color color = { 0,0,0,255 };
	object->add_component(new AABBCollider(object, 100.0f, 10.0f, false));
	object->add_component(new RigidBody(object));
	object->add_component(new PlayerMovement(object));
	object->add_component(new RectRenderer(object, 100.0f, 10.0f, color, 3));
}