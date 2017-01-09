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
		Movable(const SDL_Rect& r, int s);
		// �kallar super i cpp
		SDL_Texture* getSheet1() const { return spriteSheet1; }
		SDL_Texture* getSheet2() const { return spriteSheet2; }
		SDL_Texture* spriteSheet1;
		SDL_Texture* spriteSheet2;

		int speed;
		// Movable::Movable(const SDL_Rect& r, int s): GameObject(r), speed(s)
		// om man ska best�mma farten n�r man skapat objektet

		int rCount;
		int lCount;
		int rSpriteW;
		int rSpriteH;
		int lSpriteW;
		int lSpriteH;
		bool facingRight;
		int sw;
		int sh;
	private:



	};
}



#endif 


