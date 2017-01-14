#include "Player.h"
#include "System.h"

#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
using namespace std;

namespace lazyEngine {
	Player::Player(const SDL_Rect& r, int xSpd, int ySpd, char * sheet1, int sheet1X, int sheet1Y,
		char * sheet2, int sheet2X, int sheet2Y, int sWidth, int sHeight, int rsx, int rsy, int lsx, int lsy, bool start1) :
		Movable(r, xSpd, ySpd, sheet1, sheet1X, sheet1Y, sheet2, sheet2X, sheet2Y, sWidth, sHeight, rsx, rsy, lsx, lsy, start1)
	{
		SDL_Surface* surface1 = IMG_Load(sheet1);
		if (surface1 == nullptr) {
			cerr << "Image " << sheet1 << " not found." << endl;
		}

		destroyed = false;

		spriteSheet1 = SDL_CreateTextureFromSurface(sys.getRen(), surface1);

		SDL_FreeSurface(surface1);
		SDL_Surface* surface2 = IMG_Load(sheet2);
		if (surface2 == nullptr) {
			cerr << "Image " << sheet2 << " not found." << endl;

		}

		spriteSheet2 = SDL_CreateTextureFromSurface(sys.getRen(), surface2);

		SDL_FreeSurface(surface2);

	}


	void Player::mouseDown(const SDL_Event & eve)
	{
	}

	void Player::mouseUp(const SDL_Event & eve)
	{
	}

	void Player::keyDown(const SDL_Event & eve)
	{
		switch (eve.key.keysym.sym) {
		case SDLK_RIGHT:
			facingRight = true;
			if (xSpeed > 0)
				animate();
			move(xSpeed, 0);
			break;
		case SDLK_LEFT:
			facingRight = false;
			if (xSpeed > 0)
				animate();
			move(-xSpeed, 0);
			break;
		case SDLK_UP:
			move(0, -ySpeed);
			if (ySpeed > 0)
				animate();
			break;
		case SDLK_DOWN:
			move(0, ySpeed);
			if (ySpeed > 0)
				animate();
			break;
		}
	}

	void Player::keyUp(const SDL_Event & eve)
	{
		stop();
	}

	void Player::animate() {
		if (facingRight) {
			rCountX++;
			if (rCountX < (spriteCount1X - 1)) {
				rSpriteX += spriteWidth;
			}
			else {
				rCountX = 1;
				rSpriteX = spriteWidth;
			}
		}
		else {
			lCountX++;
			if (lCountX < (spriteCount2X - 1))
				lSpriteX -= spriteWidth;
			else {
				lCountX = 1;
				lSpriteX = (initSLX - spriteWidth);
			}
		}
	}

	void Player::stop() {
		rCountX = 0;
		lCountX = 0;
		rSpriteX = initSRX;
		lSpriteX = initSLX;
		rSpriteY = initSRY;
	}

	void Player::die() {
	}

	void Player::draw() {
		if (facingRight) {
			SDL_Rect rp = { rSpriteX, rSpriteY, spriteWidth, spriteHeight };
			SDL_RenderCopy(sys.getRen(), getSheet1(), &rp, &getRect());
		}
		else {
			SDL_Rect rp = { lSpriteX, lSpriteY, spriteWidth, spriteHeight };
			SDL_RenderCopy(sys.getRen(), getSheet2(), &rp, &getRect());
		}
	}

	SDL_Point Player::getPos() {
		SDL_Rect temp = getRect();
		SDL_Point p = { temp.x, temp.y };
		return p;
	}




	Player::~Player()
	{
		SDL_DestroyTexture(getSheet1());
		SDL_DestroyTexture(getSheet2());
	}

	void Player::tick()
	{
		sys.setTarget(getPos());
	}

}
