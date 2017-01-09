#include "Enemy.h"
#include "System.h"
#include <SDL_image.h>
#include <iostream>


using namespace std;

namespace lazyEngine {

	Enemy::Enemy(const SDL_Rect& r, int s) : Movable(r, s)
	{
		SDL_Surface* surface = IMG_Load("img/fireball.png");
		if (surface == nullptr) {
			cerr << "No image found." << endl;

		}

		texture = SDL_CreateTextureFromSurface(sys.getRen(), surface);
		
		SDL_FreeSurface(surface);
	}

	void Enemy::tick()
	{

		move(0, -5);

		// SDL_Point targetPos = sys.getTarget();
		// attackera mot spelarens position, downwards
		if (getRect().y < sys.SCREEN_HEIGHT) {
			delete this;
		}
		

		// nu åker eldkloten neråt i jämn hastighet



	}


	Enemy::~Enemy()
	{

	

		SDL_DestroyTexture(getTexture());
	}
}