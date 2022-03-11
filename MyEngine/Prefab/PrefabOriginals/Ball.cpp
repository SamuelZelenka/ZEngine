#include "../PrefabOriginals/Ball.h"

#include "../../GameObject/GameObject.h"
#include "../../Components/Colliders/CircleCollider.h"
#include "../../Components/RectRenderer.h"
#include "SDL.h"

void Ball::construct_components(GameObject* object)
{
	SDL_Color color = { 0,0,255,255 };
	object->add_component(new CircleCollider(object, object->position, 25, true));
	object->add_component(new RectRenderer(object, 25.0f, 25.0f, color, 2));
}