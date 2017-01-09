#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "GameObject.h"
#include <vector>



namespace lazyEngine {

	class GameEngine
	{
	public:
		GameEngine();
		~GameEngine();
		void add(GameObject*);
		void remove(GameObject*);
		// void spawnEnemy(timeHowOften, bredd och h�jd den kan spawna p�(�ver hela banan exempelvis)
		void spawnEnemy(SDL_Rect spawn_area, int speed);

		bool checkCollision(SDL_Rect A, SDL_Rect B);
		void run();



	private:
		std::vector<GameObject*> gameObjectVector;
		int spawnTime = 5000; // h�rdkodad, borde �ndras till konstruktor argument

	};

}
#endif