#ifndef PLAYER_H
#define PLAYER_H
#include "Movable.h"



namespace lazyEngine {

	class Player :
		public Movable
	{
	public:
		//Player(const SDL_Rect& r, int s);
		Player(const SDL_Rect & r, int xSpd, int ySpd, char * sheet1, int sheet1X, int sheet1Y, 
			char * sheet2, int sheet2X, int sheet2Y, int sWidth, int sHeight, int rsx, int rsy, int lsx, int lsy, bool start1);
		void draw();
		SDL_Point getPos();
		void mouseDown(const SDL_Event& eve);
		void mouseUp(const SDL_Event& eve);
		void keyDown(const SDL_Event& eve);
		void keyUp(const SDL_Event& eve);
		void animate();
		void stop();
		void die();
		~Player();

		void tick();

	};

}


#endif