#include "Source.h"
#include "GameEngine.h"
#include "Player.h"
#include "Background.h"
#include "Enemy.h"
#include <ctime> 
#include <cstdlib> 

//#include "Spawner.h"
using namespace lazyEngine;

int main(int argc, char** argv) {
	GameEngine ge;
	srand((unsigned)time(0));
	SDL_Rect rp = { 200,205,38,38 };
	SDL_Rect rb = { 0,0,640,480 };
	SDL_Rect rball1 = { ((rand() % 640) + 1),-64,64,64 };
	SDL_Rect rball2 = { ((rand() % 640) + 1),-128,64,64 };
	SDL_Rect rball3 = { ((rand() % 640) + 1),-192,64,64 };
	SDL_Rect rball4 = { ((rand() % 640) + 1),-256,64,64 };
	SDL_Rect rball5 = { ((rand() % 640) + 1),-320,64,64 };
	SDL_Rect rball6 = { ((rand() % 640) + 1),-384,64,64 };
	SDL_Rect rball7 = { ((rand() % 640) + 1),-448,64,64 };
	SDL_Rect rball8 = { ((rand() % 640) + 1),-512,64,64 };
	SDL_Rect rjerk1 = { -1000,150,131,131 };
	//SDL_Rect rjerk2 = { 500,205,131,131 };

	/*
	*Player / Enemy params: SDL_Rect, horizontal speed, vertical speed, path to spritesheet #1, number of sprites per row used, number of sprites per column used, path to spritesheet #2,
	* sprites per row & column for #2, sprite width, sprite height, start points X&Y coordinates on spritesheets, start on sheet1 (true) or sheet2 (false).
	*/
	Player p(rp, 5, 0, "img/robojerk.png", 8, 0, "img/robojerkreverse.png", 8, 0, 38, 38, 0, 0, 266, 0, true);

	char* path1 = "img/fireball.png";
	char* path2 = "img/explosion.png";
	Enemy fire1(rball1, 0, 2, path1, 8, 0, path2, 5, 5, 64, 64, 0, 384, 0, 0, true);
	Enemy fire2(rball2, 0, 2, path1, 8, 0, path2, 5, 5, 64, 64, 0, 384, 0, 0, true);
	Enemy fire3(rball3, 0, 2, path1, 8, 0, path2, 5, 5, 64, 64, 0, 384, 0, 0, true);
	Enemy fire4(rball4, 0, 2, path1, 8, 0, path2, 5, 5, 64, 64, 0, 384, 0, 0, true);
	Enemy fire5(rball5, 0, 2, path1, 8, 0, path2, 5, 5, 64, 64, 0, 384, 0, 0, true);
	Enemy fire6(rball6, 0, 2, path1, 8, 0, path2, 5, 5, 64, 64, 0, 384, 0, 0, true);
	Enemy fire7(rball7, 0, 2, path1, 8, 0, path2, 5, 5, 64, 64, 0, 384, 0, 0, true);
	Enemy fire8(rball8, 0, 2, path1, 8, 0, path2, 5, 5, 64, 64, 0, 384, 0, 0, true);
	Enemy jerk1(rjerk1, 1, 0, "img/enemy.png", 8, 3, "img/enemyleft.png", 8, 3, 262, 262, 0, 0, 266, 0, true);
	//Enemy jerk2(rjerk2, -1, 0, "img/enemy.png", 8, 3, "img/enemyleft.png", 8, 3, 262, 262, 0, 0, 266, 0, false);
	//Spawner spwn(&ge, 640, 480, 2, "img/fireball.png", "img/explosion.png", 64, 64);
	Background bg(rb, "img/stolenBg.png");
	ge.add(&bg);
	ge.add(&p);
	ge.add(&fire1);
	ge.add(&fire2);
	ge.add(&fire3);
	ge.add(&fire4);
	ge.add(&fire5);
	ge.add(&fire6);
	ge.add(&fire7);
	ge.add(&fire8);
	ge.add(&jerk1);
	//ge.add(&jerk2);
	ge.run();

	return 0;
}

Source::Source()
{
}


Source::~Source()
{
}
