#ifndef PLAYER_H
#define PLAYER_H
#include "Movable.h"



namespace lazyEngine {

	class Player :
		public Movable
	{
	public:
		//Player(const SDL_Rect& r, int s);
		Player(const SDL_Rect & r, int s, char * sheet1, char * sheet2, int sWidth, int sHeight);
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