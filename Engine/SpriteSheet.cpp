#include "SpriteSheet.h"
#include <utility>

using namespace std;

namespace lazyEngine {

	SpriteSheet::SpriteSheet(char* path, int sWidth, int sHeight, int sCountX, int sCountY) : filepath(path), spriteWidth(sWidth), spriteHeight(sHeight), spriteCountX(sCountX), spriteCountY(sCountY)
	{
		/*
		* This adds the pixel coordinates of each sprite to a vector, in order from upper left to lower right. 
		* So sprite 0 starts at 0,0 and so forth.
		*/
		for (int yi = 0; yi < spriteCountY; yi++) {
			for (int xi = 0; xi < spriteCountX; xi++) {
				coords.push_back(make_pair((sWidth * xi), (sHeight * yi)));
			}
		}
		spriteCount = sCountX * sCountY;
	}

	char* SpriteSheet::getPath() { return filepath; }
	int SpriteSheet::getSWidth() { return spriteWidth; }
	int SpriteSheet::getSHeight() { return spriteHeight; }

	/*
	* Returns the pixel coordinates of the requested sprite number, 
	* keeping in mind that the user will consider the first sprite #1.
	*/
	pair<int, int> SpriteSheet::getSpriteCoords(int sNum) { return SpriteSheet::coords[sNum - 1]; }

	SpriteSheet::~SpriteSheet()
	{
	}
}