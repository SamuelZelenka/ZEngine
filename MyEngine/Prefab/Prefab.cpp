#include "Prefab.h"
#include "../GameObject/GameObject.h"
#include "../Components/Component.h"


GameObject* Prefab::construct(Game* game, Vector2 pos)
{
	GameObject* object = new GameObject(game);
	object->position = pos;
	construct_components(object);
	return object;
}
