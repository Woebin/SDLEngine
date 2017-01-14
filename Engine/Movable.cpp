#include "Movable.h"


namespace lazyEngine {

	Movable::Movable(const SDL_Rect& r, int s, char * sheet1, char * sheet2, int sWidth, int sHeight) : GameObject(r), speed(s)
	{
		spriteWidth = sWidth;
		spriteHeight = sHeight;
	}

	void Movable::move(int xx, int yy) {

		rect.y += yy;
		rect.x += xx;

	}

	Movable::~Movable()
	{
		SDL_DestroyTexture(spriteSheet1);
		SDL_DestroyTexture(spriteSheet2);
	}





}
