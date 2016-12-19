#ifndef IMMOVABLE_H
#define IMMOVABLE_H
#include "GameObject.h"
namespace lazyEngine {
	class Immovable :
		public GameObject
	{
	public:

		~Immovable();
	protected:
		Immovable(const SDL_Rect& r);

	private:
		// finns det n�got som �r speciellt f�r Immovable objekt?
		// int value;   p� coins?
	};

}

#endif