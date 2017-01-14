#include "Movable.h"
#include "SpriteSheet.h"


namespace lazyEngine {

	Movable::Movable(const SDL_Rect& r, int s, SpriteSheet ss1, SpriteSheet ss2) : GameObject(r), speed(s), sheet1(ss1), sheet2(ss2)
	{
		//spriteWidth = sWidth;
		//spriteHeight = sHeight;
	}

	void Movable::move(int xx, int yy) {

		rect.y += yy;
		rect.x += xx;

	}

	Movable::~Movable()
	{
	}





}
