
#include "Player.h"

#include "System.h"
#include <iostream>
using namespace std;

namespace lazyEngine {

	Player::Player(const SDL_Rect& r, int s) : Movable(r, s)
	{


		SDL_Surface* surface = SDL_LoadBMP("c:/images/gubbe.bmp");
		if (surface == nullptr) {
			cerr << "Bild hittas inte!" << endl;

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
		case SDLK_UP: move(0, speed); break;
		case SDLK_DOWN: move(0, -speed); break;
		}
	}

	void Player::keyUp(const SDL_Event & eve)
	{
		// gravity shit? slowing down?
	}


	void Player::draw() {

		SDL_RenderCopy(sys.getRen(), getTexture(), NULL, &getRect());
		// NULL kan bytas ut mot vilken del av bilden som skall ritas ut

	}




	Player::~Player()
	{

		SDL_DestroyTexture(getTexture());
	}

}