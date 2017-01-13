#ifndef ENEMY_H
#define ENEMY_H
#include "Movable.h"

namespace lazyEngine {
	class Enemy : public Movable
	{
	public:
		Enemy(const SDL_Rect& r, int s, char * sheet1, char * sheet2, int sWidth, int sHeight);
		void tick();
		void animate();
		void die();
		void draw();
		~Enemy();
	

	};

}

#endif