#include "Movable.h"


namespace lazyEngine {

	Movable::Movable(const SDL_Rect& r, int s) : GameObject(r), speed(s)
	{
	}

	void Movable::move(int xx, int yy) {

		rect.y += yy;
		rect.x += xx;

	}

	Movable::~Movable()
	{
	}





}
