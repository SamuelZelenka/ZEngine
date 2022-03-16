#include "BreakablePrefab.h"

#include "../../GameObject/GameObject.h"

#include "../../Components/Breakable.h"
#include "../../Components/Colliders/AABBCollider.h"
#include "../../Components/RectRenderer.h"


void BreakablePrefab::construct_components(GameObject* object)
{
	SDL_Color color = { 0,0,0,255 };
	object->add_component(new AABBCollider(object, 50.0f, 25.0f, true));
	object->add_component(new RectRenderer(object, 50.0f, 25.0f, color, 3));
	object->add_component(new Breakable(object, 3));
}