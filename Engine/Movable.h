#ifndef MOVABLE_H
#define MOVABLE_H
#include "GameObject.h"
#include "SpriteSheet.h"



namespace lazyEngine {
	class Movable : public GameObject
	{
	public:


		~Movable();

		void move(int xx, int yy);
		virtual void animate(int start, int stop) = 0;

	protected:
		Movable(const SDL_Rect& r, int s, SpriteSheet ss1, SpriteSheet ss2);
		// �kallar super i cpp
		SDL_Texture* getSheet1() const { return spriteSheet1; }
		SDL_Texture* getSheet2() const { return spriteSheet2; }
		SDL_Texture* spriteSheet1;
		SDL_Texture* spriteSheet2;
		SpriteSheet sheet1;
		SpriteSheet sheet2;

		int speed;
		// Movable::Movable(const SDL_Rect& r, int s): GameObject(r), speed(s)
		// om man ska best�mma farten n�r man skapat objektet

		int rCount;
		int lCount;
		int rSpriteX;
		int rSpriteY;
		int lSpriteX;
		int lSpriteY;
		bool facingRight;
		int spriteWidth;
		int spriteHeight;
		bool destroyed;
	private:



	};
}



#endif 


