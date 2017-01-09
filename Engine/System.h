#ifndef SYSTEM_H
#define SYSTEM_H
#include <SDL.h>
#include <SDL_ttf.h>
namespace lazyEngine {

	class System
	{
	public:
		System();
		SDL_Renderer* getRen() { return ren; }
		TTF_Font* getFont() { return font; }
		SDL_Point getTarget();
		void setTarget(SDL_Point p);



		~System();
	private:
		SDL_Window* win;
		SDL_Renderer* ren;
		TTF_Font* font;
		SDL_Point target;
	};
	// global variabel f�r renderaren f�r den ska anv�ndas �verallt
	// n�nsttans finns ett objekt av denna System sys
	extern System sys;
}
#endif