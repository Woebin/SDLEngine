#include "GameObject.h"
#include "System.h"


namespace lazyEngine {

	GameObject::GameObject(const SDL_Rect& r) : rect(r)
	{
	}





	GameObject::~GameObject()
	{
	
		SDL_DestroyTexture(texture);
	}
}


