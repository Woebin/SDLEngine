#include "Enemy.h"

using namespace std;

namespace lazyEngine {

	Enemy::Enemy(const SDL_Rect& r, int s) : Movable(r, s)
	{
	}

	void Enemy::tick()
	{
		
	}


	Enemy::~Enemy()
	{
	}
}