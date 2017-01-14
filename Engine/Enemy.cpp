#include "Enemy.h"
#include "System.h"
#include <SDL_image.h>
#include <iostream>


using namespace std;

namespace lazyEngine {


	Enemy::Enemy(const SDL_Rect& r, int s) : Movable(r, s)
	{
		rCount = 0;
		lCount = 0;
		rSpriteX = 0;
		rSpriteY = 384;
		spriteWidth = 64;
		spriteHeight = 64;
		destroyed = false;

		SDL_Surface* surface1 = IMG_Load("img/fireball.png");
		if (surface1 == nullptr) {
			cerr << "No image found." << endl;
		}
		spriteSheet1 = SDL_CreateTextureFromSurface(sys.getRen(), surface1);
		SDL_FreeSurface(surface1);

		SDL_Surface* surface2 = IMG_Load("img/explosion.png");
		if (surface2 == nullptr) {
			cerr << "No image found." << endl;
		}
		spriteSheet2 = SDL_CreateTextureFromSurface(sys.getRen(), surface2);
		SDL_FreeSurface(surface2);
	}

	void Enemy::tick()
	{
		// SDL_Point targetPos = sys.getTarget();
		// attackera mot spelarens position, downwards
		//if (getRect().y < 480) {
		//	
		//}
		animate();
		move(0, speed);

		// nu åker eldkloten neråt i jämn hastighet
	}

	void Enemy::animate() {
		if (!destroyed) {
			rCount++;
			if (rCount < 8) {
				rSpriteX += spriteWidth;
			}
			else {
				rCount = 0;
				rSpriteX = 0;
			}
		}
		else {
			lCount++;
			if (lCount < 5) {
				rSpriteX += spriteWidth;
			}
			else if (lCount < 6 && rSpriteY < 256) {
				lCount = 0;
				rSpriteX = 0;
				rSpriteY += spriteHeight;
			}
			else {
				lCount = 0;
				rSpriteX = 0;
				rSpriteY = 0;
			}
		}
	}

	void Enemy::die() {
		destroyed = true;
		speed = 0;
	}

	void Enemy::draw() {
		if (!destroyed){
		SDL_Rect rp = { rSpriteX,rSpriteY,spriteWidth,spriteHeight };
		SDL_RenderCopy(sys.getRen(), getSheet1(), &rp, &getRect());
		}
		else {
			SDL_Rect rp = { rSpriteX,rSpriteY,spriteWidth,spriteHeight };
			SDL_RenderCopy(sys.getRen(), getSheet2(), &rp, &getRect());
		}
	}


	Enemy::~Enemy()
	{
		SDL_DestroyTexture(getSheet1());
		SDL_DestroyTexture(getSheet2());
	}
}