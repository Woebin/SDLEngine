#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "Immovable.h"
#include <string>

namespace lazyEngine {
	class Background :
		public Immovable
	{
	public:
		Background(const SDL_Rect& r);
		void draw();


		~Background();
	};
}

#endif

