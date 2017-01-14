#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <vector>
#include <utility>

namespace lazyEngine {
	class SpriteSheet
	{
	public:
		SpriteSheet(char* path, int sWidth, int sHeight, int sCountX, int sCountY);
		std::vector<std::pair<int, int>> coords;
		char* getPath();
		std::pair<int, int> getSpriteCoords(int sNum);
		int getSWidth();
		int getSHeight();
		~SpriteSheet();
	protected:
		int spriteWidth;
		int spriteHeight;
		int spriteCountX;
		int spriteCountY;
		int spriteCount;
		char* filepath;
	};
}

#endif