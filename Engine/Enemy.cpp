#include "Enemy.h"
#include "System.h"
#include "SpriteSheet.h"
#include <SDL_image.h>
#include <iostream>


using namespace std;

namespace lazyEngine {


	Enemy::Enemy(const SDL_Rect& r, int s, SpriteSheet ss1, SpriteSheet ss2) : Movable(r, s, ss1, ss2)
	{
		rCount = 0;
		lCount = 0;
		rSpriteX = 0;
		rSpriteY = 384;
		destroyed = false;

		SDL_Surface* surface1 = IMG_Load(ss1.getPath());
		if (surface1 == nullptr) {
			cerr << "Image " << ss1.getPath() << " not found." << endl;
		}
		spriteSheet1 = SDL_CreateTextureFromSurface(sys.getRen(), surface1);
		SDL_FreeSurface(surface1);

		SDL_Surface* surface2 = IMG_Load(ss2.getPath());
		if (surface2 == nullptr) {
			cerr << "Image " << ss2.getPath() << " not found." << endl;
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
	/*	animate();*/
		move(0, speed);

		// nu åker eldkloten neråt i jämn hastighet
	}

	void Enemy::animate(int start, int stop) {
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
		if (!destroyed) {
			SDL_Rect rp = { rSpriteX,rSpriteY,sheet1.getSWidth(),sheet1.getSHeight() };
			SDL_RenderCopy(sys.getRen(), getSheet1(), &rp, &getRect());
		}
		else {
			SDL_Rect rp = { rSpriteX,rSpriteY,sheet2.getSWidth(),sheet2.getSHeight() };
			SDL_RenderCopy(sys.getRen(), getSheet2(), &rp, &getRect());
		}
	}


	Enemy::~Enemy()
	{
		SDL_DestroyTexture(getSheet1());
		SDL_DestroyTexture(getSheet2());
	}
}