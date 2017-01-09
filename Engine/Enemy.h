#ifndef ENEMY_H
#define ENEMY_H
#include "Movable.h"

namespace lazyEngine {
	class Enemy : public Movable
	{
	public:
		Enemy(const SDL_Rect & r, int s);
		void tick();
		void animate();
		void die();
		void draw();
		~Enemy();
	

	};

}

#endif