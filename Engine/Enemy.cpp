#include "Enemy.h"
#include "System.h"
#include <SDL_image.h>
#include <iostream>


using namespace std;

namespace lazyEngine {


	Enemy::Enemy(const SDL_Rect& r, int s) : Movable(r, s)
	{
		rCount = 0;
		rSpriteW = 0;
		rSpriteH = 384;
		sw = 64;
		sh = 64;
		SDL_Surface* surface = IMG_Load("img/fireball.png");
		if (surface == nullptr) {
			cerr << "No image found." << endl;
		}
		spriteSheet1 = SDL_CreateTextureFromSurface(sys.getRen(), surface);
		SDL_FreeSurface(surface);
	}

	void Enemy::tick()
	{
		// SDL_Point targetPos = sys.getTarget();
		// attackera mot spelarens position, downwards
		//if (getRect().y < 480) {
		//	
		//}
		move(0, speed);
		animate();

		// nu åker eldkloten neråt i jämn hastighet
	}

	void Enemy::animate() {
		rCount++;
		if (rCount < 8) {
			rSpriteW += sw;
		}
		else {
			rCount = 0;
			rSpriteW = 0;
		}
	}

	void Enemy::draw() {
		SDL_Rect rp = { rSpriteW,rSpriteH,sw,sh };
		SDL_RenderCopy(sys.getRen(), getSheet1(), &rp, &getRect());
	}


	Enemy::~Enemy()
	{
		SDL_DestroyTexture(getSheet1());
	}
}