#include "GameObject.h"
#include <SDL.h>

namespace engine {

	GameObject::GameObject(const SDL_Rect& r) :rect(r)
	{
	}


	GameObject::~GameObject()
	{
	}

}
