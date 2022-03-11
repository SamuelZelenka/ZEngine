#include "../PrefabOriginals/CollisionBoxPrefab.h"
#include "../../GameObject/GameObject.h"
#include "../../Components/Colliders/AABBCollider.h"
#include "../../Components/RectRenderer.h"
#include "SDL.h"

void CollisionBoxPrefab::construct_components(GameObject* object)
{
	SDL_Color color = { 0,0,255,255 };
	object->add_component(new AABBCollider(object, object->position, 25.0f, 600.0f, true));
	object->add_component(new RectRenderer(object, 25.0f, 600.0f, color, 2));
}