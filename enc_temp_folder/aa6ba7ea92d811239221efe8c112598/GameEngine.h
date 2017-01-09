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
		// void spawnEnemy(timeHowOften, bredd och höjd den kan spawna på(över hela banan exempelvis)
		void spawnEnemy(SDL_Rect spawn_area, int speed);

		bool checkCollision(SDL_Rect A, SDL_Rect B);
		void run();



	private:
		std::vector<GameObject*> gameObjectVector;
		int spawnTime = 5000; // hårdkodad, borde ändras till konstruktor argument

	};

}
#endif