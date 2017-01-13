#include "Background.h"
#include "System.h"
#include <iostream>
#include<SDL_image.h>

using namespace std;
namespace lazyEngine {

	Background::Background(const SDL_Rect& r, char * imgPath) : Immovable(r, imgPath)
	{
		SDL_Surface* surface = IMG_Load(imgPath);
		if (surface == nullptr) {
			cerr << "No background image found." << endl;

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


	Background::~Background()
	{
	}
}

