#ifndef PLAYER_H
#define PLAYER_H
#include "Movable.h"



namespace lazyEngine {

	class Player :
		public Movable
	{
	public:
		Player(const SDL_Rect& r, int s);
		void draw();
		SDL_Point getPos();
		void mouseDown(const SDL_Event& eve);
		void mouseUp(const SDL_Event& eve);
		void keyDown(const SDL_Event& eve);
		void keyUp(const SDL_Event& eve);
		void animate();
		~Player();

		void tick();

	};

}


#endif