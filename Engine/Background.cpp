#include "Background.h"
#include "System.h"
#include <iostream>
using namespace std;
namespace lazyEngine {

	Background::Background(const SDL_Rect& r) : Immovable(r)
	{
		SDL_Surface* surface = SDL_LoadBMP("c:/images/gubbe.bmp");
		if (surface == nullptr) {
			cerr << "Bild hittas inte!" << endl;

		}
		//texture = SDL_CreateTextureFromSurface(sys.getRen(), surface);
		texture = SDL_CreateTextureFromSurface(sys.getRen(), surface);
		// m�ste man g�ra en setTexture?
		SDL_FreeSurface(surface);


	}

	void Background::draw() {

		SDL_RenderCopy(sys.getRen(), getTexture(), NULL, &getRect());
		// NULL kan bytas ut mot vilken del av bilden som skall ritas ut

	}


	Background::~Backround()
	{
	}
}

