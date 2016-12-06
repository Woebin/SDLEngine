#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include <SDL.h>
#include <SDL_ttf.h>

namespace engine {
	class GameEngine
	{
	public:
		GameEngine();
		SDL_Renderer* getRen() { return ren; }
		TTF_Font* getFont() { return font; }
		~GameEngine();
		/*AddSprite();
		RemoveSprite();
		Run();*/
	private:
		SDL_Window* win;
		SDL_Renderer* ren;
		TTF_Font* font;


		// en testkommentar
	};

	extern GameEngine eng;
}

#endif