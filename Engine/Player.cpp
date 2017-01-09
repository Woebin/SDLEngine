
#include "Player.h"

#include "System.h"
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
using namespace std;

namespace lazyEngine {

	Player::Player(const SDL_Rect& r, int s) : Movable(r, s)
	{
		SDL_Surface* surface1 = IMG_Load("img/robojerk.png");
		if (surface1 == nullptr) {
			cerr << "No image found." << endl;

		}

		sw = 38;
		sh = 38;
		rSpriteW = 0;
		rSpriteH = 0;
		rCount = 0;
		lSpriteW = 266;
		lCount = 0;
		facingRight = true;

		spriteSheet1 = SDL_CreateTextureFromSurface(sys.getRen(), surface1);

		SDL_FreeSurface(surface1);
		SDL_Surface* surface2 = IMG_Load("img/robojerkreverse.png");
		if (surface2 == nullptr) {
			cerr << "No image found." << endl;

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
			animate();
			move(speed, 0);
			break;
		case SDLK_LEFT:
			facingRight = false;
			animate();
			move(-speed, 0);
			break;
		case SDLK_UP: move(0, -speed); break;
		case SDLK_DOWN: move(0, speed); break;
		}
	}

	void Player::keyUp(const SDL_Event & eve)
	{
		stop();
		// gravity shit? slowing down?
	}

	void Player::animate() {
		if (facingRight) {
			rCount++;
			if (rCount < 7) {
				rSpriteW += sw;
			}
			else {
				rCount = 1;
				rSpriteW = 38;
			}
		}
		else {
			lCount++;
			if (lCount < 7)
				lSpriteW -= sw;
			else {
				lCount = 1;
				lSpriteW = 228;
			}
		}
	}

	void Player::stop() {
		rCount = 0;
		lCount = 0;
		rSpriteW = 0;
		lSpriteW = 266;
		rSpriteH = 0;
	}


	void Player::draw() {
		if (facingRight) {
			SDL_Rect rp = { rSpriteW,0,sw,sh };
			SDL_RenderCopy(sys.getRen(), getSheet1(), &rp, &getRect());
		}
		else {
			SDL_Rect rp = { lSpriteW,0,sw,sh };
			SDL_RenderCopy(sys.getRen(), getSheet2(), &rp, &getRect());
		}
		// NULL kan bytas ut mot vilken del av bilden som skall ritas ut

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
