#include "Enemy.h"
#include "System.h"
#include <SDL_image.h>
#include <iostream>


using namespace std;

namespace lazyEngine {


	Enemy::Enemy(const SDL_Rect& r, int xSpd, int ySpd, char * sheet1, int sheet1X, int sheet1Y,
		char * sheet2, int sheet2X, int sheet2Y, int sWidth, int sHeight, int rsx, int rsy, int lsx, int lsy, bool start1) :
		Movable(r, xSpd, ySpd, sheet1, sheet1X, sheet1Y, sheet2, sheet2X, sheet2Y, sWidth, sHeight, rsx, rsy, lsx, lsy, start1)
	{

		destroyed = false;

		SDL_Surface* surface1 = IMG_Load(sheet1);
		if (surface1 == nullptr) {
			cerr << "Image " << sheet1 << " not found." << endl;
		}
		spriteSheet1 = SDL_CreateTextureFromSurface(sys.getRen(), surface1);
		SDL_FreeSurface(surface1);

		SDL_Surface* surface2 = IMG_Load(sheet2);
		if (surface2 == nullptr) {
			cerr << "Image " << sheet2 << " not found." << endl;
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
		move(xSpeed, ySpeed);
	}

	void Enemy::animate() {
		if (!destroyed) {
			if (facingRight) {
				rCountX++;
				if (rCountX < spriteCount1X) {
					rSpriteX += spriteWidth;
				}
				else {
					rCountX = 0;
					rSpriteX = initSRX;
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
		else {
			lCountX++;
			if (lCountX < spriteCount2X) {
				rSpriteX += spriteWidth;
			}
			//else if (lCountX < (spriteCount2X - 1) && rSpriteY < 256) {
			else if (lCountX < (spriteCount2X - 1) && lCountY < (spriteCount2Y -1)) {
				lCountX = 0;
				rSpriteX = initSRX;
				rSpriteY += spriteHeight;
			}
			else {
				lCountX = 0;
				rSpriteX = 0;
				rSpriteY = 0;
			}
		}
	}

	void Enemy::die() {
		destroyed = true;
		ySpeed = 0;
		xSpeed = 0;
	}

	void Enemy::draw() {
		if (!destroyed) {
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
		
	}
}