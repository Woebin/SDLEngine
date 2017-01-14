#include "Movable.h"


namespace lazyEngine {

	Movable::Movable(const SDL_Rect& r, int xSpd, int ySpd, char * sheet1, int sheet1X, int sheet1Y, 
		char * sheet2, int sheet2X, int sheet2Y, int sWidth, int sHeight, int rsx, int rsy, int lsx, int lsy, bool start1) :
		GameObject(r), xSpeed(xSpd), ySpeed(ySpd), rSpriteX(rsx), rSpriteY(rsy), lSpriteX(lsx), lSpriteY(lsy), facingRight(start1) {
		spriteWidth = sWidth;
		spriteHeight = sHeight;
		spriteCount1X = sheet1X;
		spriteCount1Y = sheet1Y;
		spriteCount2X = sheet2X;
		spriteCount2Y = sheet2Y;
		initSRX = rSpriteX;
		initSRY = rSpriteY;
		initSLX = lSpriteX;
		initSLY = lSpriteY;
		facingRight = start1;
		rCountX = 0;
		rCountY = 0;
		lCountX = 0;
		lCountY = 0;
	}

	void Movable::move(int xx, int yy) {

		rect.y += yy;
		rect.x += xx;

	}

	Movable::~Movable()
	{
	}





}
