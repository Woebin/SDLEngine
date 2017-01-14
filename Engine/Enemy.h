#ifndef ENEMY_H
#define ENEMY_H
#include "Movable.h"
#include "SpriteSheet.h"

namespace lazyEngine {
	class Enemy : public Movable
	{
	public:
		Enemy(const SDL_Rect& r, int s, SpriteSheet sheet1, SpriteSheet sheet2);
		void tick();
		void animate(int start, int stop);
		void die();
		void draw();
		~Enemy();
	

	};

}

#endif