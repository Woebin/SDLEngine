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
		bool checkCollision(SDL_Rect A, SDL_Rect B);
		void run();



	private:
		std::vector<GameObject*> gameObjectVector;

	};

}
#endif