#include "GameEngine.h"
#include <iostream>
#include <SDL.h>

using namespace std;

namespace engine {

	GameEngine::GameEngine()
	{
		SDL_Init(SDL_INIT_EVERYTHING);
		win = SDL_CreateWindow("Testing", 100, 100, 600, 500, 0);
		ren = SDL_CreateRenderer(win, -1, 0);
		TTF_Init();
		font = TTF_OpenFont("c:/Windows/Fonts/arial.ttf", 24);
	}


	GameEngine::~GameEngine()
	{
		TTF_CloseFont(font);
		TTF_Quit();
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
		SDL_Quit();
	}

}
