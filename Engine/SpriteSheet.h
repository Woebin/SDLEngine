#ifndef SPRITESHEET_H
#define SPRITESHEET_H

class SpriteSheet
{
public:
	SpriteSheet(char* path, int sWidth, int sHeight, int sCountX, int sCountY);
	char* filepath;
	int spriteWidth;
	int spriteHeight;
	int spriteCountX;
	int spriteCountY;
	~SpriteSheet();
};

#endif