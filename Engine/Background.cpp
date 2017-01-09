#include "Background.h"
#include "System.h"
#include <iostream>
#include<SDL_image.h>

using namespace std;
namespace lazyEngine {

	Background::Background(const SDL_Rect& r) : Immovable(r)
	{
		SDL_Surface* surface = IMG_Load("img/bg.png");
		if (surface == nullptr) {
			cerr << "Bild hittas inte!" << endl;

		}
		//texture = SDL_CreateTextureFromSurface(sys.getRen(), surface);
		spriteSheet1 = SDL_CreateTextureFromSurface(sys.getRen(), surface);
		// m�ste man g�ra en setTexture?
		SDL_FreeSurface(surface);


	}

	void Background::draw() {

		SDL_RenderCopy(sys.getRen(), getSheet1(), NULL, &getRect());
		// NULL kan bytas ut mot vilken del av bilden som skall ritas ut

	}


	Background::~Background()
	{
	}
}

