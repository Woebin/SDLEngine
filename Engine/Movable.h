#ifndef MOVABLE_H
#define MOVABLE_H
#include "GameObject.h"



namespace lazyEngine {
	class Movable : public GameObject
	{
	public:


		~Movable();

		void move(int xx, int yy);
		virtual void animate() = 0;

	protected:
		Movable(const SDL_Rect& r, int xSpd, int ySpd, char * sheet1, int sheet1X, int sheet1Y, 
			char * sheet2, int sheet2X, int sheet2Y, int sWidth, int sHeight, int rsx, int rsy, int lsx, int lsy, bool start1);
		// �kallar super i cpp
		SDL_Texture* getSheet1() const { return spriteSheet1; }
		SDL_Texture* getSheet2() const { return spriteSheet2; }
		SDL_Texture* spriteSheet1;
		SDL_Texture* spriteSheet2;

		int xSpeed;
		int ySpeed;
		// Movable::Movable(const SDL_Rect& r, int s): GameObject(r), speed(s)
		// om man ska best�mma farten n�r man skapat objektet
		
		int initSRX;
		int initSRY;
		int initSLX;
		int initSLY;

		int rCountX;
		int rCountY;
		int lCountX;
		int lCountY;

		int rSpriteX;
		int rSpriteY;
		int lSpriteX;
		int lSpriteY;

		bool facingRight;
		int spriteWidth;
		int spriteHeight;
		int spriteCount1X;
		int spriteCount1Y;
		int spriteCount2X;
		int spriteCount2Y;
		bool destroyed;
	private:



	};
}



#endif 


