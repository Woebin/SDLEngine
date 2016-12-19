﻿#ifndef MOVABLE_H
#define MOVABLE_H
#include "GameObject.h"



namespace lazyEngine {
	class Movable : public GameObject
	{
	public:


		~Movable();


		void move(int xx, int yy);

	protected:
		Movable(const SDL_Rect& r, int s);
		// �kallar super i cpp


		int speed;
		// Movable::Movable(const SDL_Rect& r, int s): GameObject(r), speed(s)
		// om man ska best�mma farten n�r man skapat objektet
	private:



	};
}



#endif 


