#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "Immovable.h"
#include <string>

namespace lazyEngine {
	class Background :
		public Immovable
	{
	public:
		Background(const SDL_Rect& r, char * imgPath);
		void draw();

		~Background();
	};
}

#endif

