
#include "Player.h"

#include "System.h"
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
using namespace std;

namespace lazyEngine {
	int sw = 38;
	int sh = 38;
	int rwTest = 0;
	int hTest = 0;
	int rCount = 0;

	int lwTest = 266;
	int lCount = 8;

	bool facingRight = true;

	Player::Player(const SDL_Rect& r, int s) : Movable(r, s)
	{
		SDL_Surface* surface1 = IMG_Load("img/robojerk.png");
		if (surface1 == nullptr) {
			cerr << "No image found." << endl;

		}

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
				rwTest += sw;
			}
			else {
				rCount = 1;
				rwTest = 38;
			}
		}
		else {
			lCount++;
			if (lCount < 7)
				lwTest -= sw;
			else {
				lCount = 1;
				lwTest = 228;
			}
		}
	}

	void Player::stop() {
		rCount = 0;
		lCount = 0;
		rwTest = 0;
		lwTest = 266;
		hTest = 0;
	}


	void Player::draw() {
		if (facingRight) {
			SDL_Rect rp = { rwTest,0,sw,sh };
			SDL_RenderCopy(sys.getRen(), getSheet1(), &rp, &getRect());
		}
		else {
			SDL_Rect rp = { lwTest,0,sw,sh };
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
