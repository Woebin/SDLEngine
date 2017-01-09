#include "GameEngine.h"
#include <SDL.h>
#include "System.h"
#include "GameObject.h"
#include <vector>
#include "Player.h"
#include "Enemy.h"
#include <cstdlib> 
#include <ctime> 

namespace lazyEngine {

	GameEngine::GameEngine() {
	}


	void GameEngine::add(GameObject* o) {
		gameObjectVector.push_back(o);
	}


	void GameEngine::remove(GameObject* o) {
		for (auto c : gameObjectVector) {
			if (c == o) {
				// delete o;    this one would break the whole program, never use delete this way
				break;

			}

		}

		// for (GameObject* pek=vek; pek < vek; pek++)
		//		if( *pek == o){
		//			delete o;
		//			break;
		//		}



	}

	void GameEngine::spawnEnemy(SDL_Rect spawn_area, int speed)
	{


		srand((unsigned)time(0));
		int x = (rand() % spawn_area.w) + 1;
		srand((unsigned)time(0));
		int y = (rand() % spawn_area.h) + 1;
		SDL_Rect r = { x, y, 64, 64 };
		Enemy enemy(r, speed); // kan succesivt öka speed om vi vill
		gameObjectVector.push_back(&enemy);
	}









	bool GameEngine::checkCollision(SDL_Rect A, SDL_Rect B)
	{
		//The sides of the rectangles
		int leftA, leftB;
		int rightA, rightB;
		int topA, topB;
		int bottomA, bottomB;

		//Calculate the sides of rect A
		leftA = A.x;
		rightA = A.x + A.w;
		topA = A.y;
		bottomA = A.y + A.h;

		//Calculate the sides of rect B
		leftB = B.x;
		rightB = B.x + B.w;
		topB = B.y;
		bottomB = B.y + B.h;

		//If any of the sides from A are outside of B
		if (bottomA <= topB)
		{
			return false;
		}

		if (topA >= bottomB)
		{
			return false;
		}

		if (rightA <= leftB)
		{
			return false;
		}

		if (leftA >= rightB)
		{
			return false;
		}

		//If none of the sides from A are outside B
		return true;
	}


	const int TIMEPERLOOP = 1000 / 30;
	void GameEngine::run() {
		bool goOn = true;
		while (goOn) {
			Uint32 nextTick = SDL_GetTicks() + TIMEPERLOOP;
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
				switch (eve.type) {
				case SDL_QUIT:
					goOn = false; break;
				case SDL_MOUSEBUTTONDOWN:
					for (auto c : gameObjectVector)
						c->mouseDown(eve);
					break;
				case SDL_MOUSEBUTTONUP:
					for (auto c : gameObjectVector)
						c->mouseUp(eve);
					break;
				case SDL_KEYDOWN:
					for (auto c : gameObjectVector)
						c->keyDown(eve);
					break;
				case SDL_KEYUP:
					for (auto c : gameObjectVector)
						c->keyUp(eve);
					break;
				} // switch
			} // inner while




			SDL_SetRenderDrawColor(sys.getRen(), 255, 255, 255, 0);
			SDL_RenderClear(sys.getRen());

			// spawnEnemies
			if (nextTick % spawnTime) {
				SDL_Rect r = { 0, 0, 640, 480 };
				spawnEnemy(r, 2);
			}

			for (GameObject* c : gameObjectVector) {
				c->tick();

				c->draw();


				if (Player* player = dynamic_cast<Player*>(c)) {  // if1
					for (GameObject* other : gameObjectVector) {  // for
						if (Enemy* enemy = dynamic_cast<Enemy*>(other)) {  // if2
							if (checkCollision(player->getRect(), enemy->getRect())) {  // if3
								// player dies
								// cue music
								enemy->die();

							} // if3
						} // if2  -- collectebles?
					} // for
				} // if1
			} // original for-loop

			SDL_RenderPresent(sys.getRen());

			int delay = nextTick - SDL_GetTicks();
			if (delay > 0) {
				SDL_Delay(delay);
			}
		} // outer while
	}


	GameEngine::~GameEngine()
	{
		gameObjectVector.clear();
		gameObjectVector.resize(0);
	}


}