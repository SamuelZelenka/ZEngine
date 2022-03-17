#include "BreakablePrefab.h"

#include "../../GameObject/GameObject.h"

#include "../../Components/Breakable.h"
#include "../../Components/Colliders/AABBCollider.h"
#include "../../Components/RectRenderer.h"


void BreakablePrefab::construct_components(GameObject* object)
{
	Breakable* newBreakable = new Breakable(object, 5);
	object->add_component(newBreakable);
	object->add_component(new AABBCollider(object, 50.0f, 25.0f, true));
	object->add_component(new RectRenderer(object, 50.0f, 25.0f, newBreakable->color, 3));
	
}