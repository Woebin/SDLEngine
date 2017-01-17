#ifndef ENEMY_H
#define ENEMY_H
#include "Movable.h"

namespace lazyEngine {
	class Enemy : public Movable
	{
	public:
		Enemy(const SDL_Rect& r, int xSpd, int ySpd, char * sheet1, int sheet1X, int sheet1Y, 
			char * sheet2, int sheet2X, int sheet2Y, int sWidth, int sHeight, int rsx, int rsy, int lsx, int lsy, bool start1);
		void tick();
		void animate();
		void die();
		void draw();
		~Enemy();
	

	};

}

#endif