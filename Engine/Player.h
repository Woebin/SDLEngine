#ifndef PLAYER_H
#define PLAYER_H
#include "Movable.h"
#include "SpriteSheet.h"



namespace lazyEngine {

	class Player :
		public Movable
	{
	public:
		//Player(const SDL_Rect& r, int s);
		Player(const SDL_Rect & r, int s, SpriteSheet sheet1, SpriteSheet sheet2);
		void draw();
		SDL_Point getPos();
		void mouseDown(const SDL_Event& eve);
		void mouseUp(const SDL_Event& eve);
		void keyDown(const SDL_Event& eve);
		void keyUp(const SDL_Event& eve);
		void animate(int start, int stop);
		void stop();
		void die();
		~Player();

		void tick();

	};

}


#endif