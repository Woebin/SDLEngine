#ifndef FRAME_H
#define FRAME_H

#include <vector>
#include "GameObject.h"

namespace engine {

	class Frame
	{
	public:
		void add(GameObject* gobj);
		void run();
		~Frame();
	private:
		std::vector<GameObject*> gobjs;
	};

}

#endif