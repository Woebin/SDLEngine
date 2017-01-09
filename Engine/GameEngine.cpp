#include "GameEngine.h"
#include <SDL.h>
#include "System.h"
#include "GameObject.h"
#include <vector>

namespace lazyEngine {

	GameEngine::GameEngine() {
	}


	void GameEngine::add(GameObject* o) {
		gameObjectVector.push_back(o);
	}


	void GameEngine::remove(GameObject* o) {
		for (auto c : gameObjectVector) {
			if (c == o) {
				delete o;
				break;
				// when deleting from a vector will there be a hole?
				// do we need to swap places or fill the hole?
			}

		}

		// for (GameObject* pek=vek; pek < vek; pek++)
		//		if( *pek == o){
		//			delete o;
		//			break;
		//		}



	}


	const int TIMEPERLOOP = 1000 / 60;
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
			for (GameObject* c : gameObjectVector) {
				c->tick();
				// tick() ska vara en funktion som anropas efter varje speloop, den kanske flyttar en fiende �t h�ger
				// �kar ett v�rde p� en klocka, k�r en soundbite utifr�n hur l�ng tid som g�tt i spelet. man 
				// uppdaterar till exeempel koordinaterna p� en sprite innan den ritas ut
				c->draw();
			}

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