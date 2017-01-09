
#include "Player.h"

#include "System.h"
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <iostream>
using namespace std;

namespace lazyEngine {

	Player::Player(const SDL_Rect& r, int s) : Movable(r, s)
	{


		SDL_Surface* surface = IMG_Load("img/robojerk.png");
		if (surface == nullptr) {
			cerr << "No image found." << endl;

		}

		texture = SDL_CreateTextureFromSurface(sys.getRen(), surface);

		SDL_FreeSurface(surface);

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
		case SDLK_RIGHT: move(speed, 0); break;
		case SDLK_LEFT: move(-speed, 0); break;
		case SDLK_UP: move(0, -speed); break;
		case SDLK_DOWN: move(0, speed); break;
		}
	}

	void Player::keyUp(const SDL_Event & eve)
	{
		// gravity shit? slowing down?
	}


	void Player::draw() {
		SDL_Rect rp = { 0,0,39,39 };
		SDL_RenderCopy(sys.getRen(), getTexture(), &rp, &getRect());
		// NULL kan bytas ut mot vilken del av bilden som skall ritas ut

	}




	Player::~Player()
	{

		SDL_DestroyTexture(getTexture());
	}

}
