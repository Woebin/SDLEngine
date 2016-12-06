#include "Frame.h"
#include <iostream>
#include "GameEngine.h"

using namespace std;

namespace engine {

	void Frame::add(GameObject* gobj)
	{
		gobjs.push_back(gobj);
	}

	void Frame::run() {
		bool goOn = true;
		while (goOn) {
			SDL_Event eve;
			while (SDL_PollEvent(&eve)) {
				switch (eve.type) {
				case SDL_QUIT:
					goOn = false;
					break;
				case SDL_MOUSEBUTTONDOWN:
					for (auto g : gobjs)
						g->mouseDown(eve);
					break;
				case SDL_MOUSEBUTTONUP:
					for (auto g : gobjs)
						g->mouseUp(eve);
					break;
				case SDL_KEYDOWN:
					for (auto g : gobjs)
						g->keyDown(eve);
					break;
				case SDL_KEYUP:
					for (auto g : gobjs)
						g->keyUp(eve);
					break;
				}
			}

			SDL_SetRenderDrawColor(eng.getRen(), 255, 255, 255, 0);
			SDL_RenderClear(eng.getRen());
			for (GameObject* g : gobjs)
				g->draw();
			SDL_RenderPresent(eng.getRen());
		}
	}

	Frame::~Frame()
	{
		for (GameObject* g : gobjs)
			delete g;
	}

}
