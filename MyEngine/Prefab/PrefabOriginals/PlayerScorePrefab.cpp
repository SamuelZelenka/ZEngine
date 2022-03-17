#include "../PrefabOriginals/PlayerScorePrefab.h"

#include "../../GameObject/GameObject.h"

#include "../../Components/Colliders/AABBCollider.h"

#include "SDL.h"

void PlayerScorePrefab::construct_components(GameObject* object)
{
	object->add_component(new AABBCollider(object, 100.0f, 25.0f, false));
}