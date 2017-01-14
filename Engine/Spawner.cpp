//#include "Spawner.h"
//#include "GameEngine.h"
//#include "Enemy.h"
//#include <cstdlib> 
//#include <ctime> 
//
//
//namespace lazyEngine {
//	Spawner::Spawner(GameEngine* eng, int width, int height, int spd, char* ss1, char* ss2, int sWidth, int sHeight)
//	{
//		engine = eng;
//		speed = spd;
//		sheet1 = ss1;
//		sheet2 = ss2;
//		screenW = width;
//		screenH = height;
//		spriteW = sWidth;
//		spriteH = sHeight;
//
//	}
//	void Spawner::Spawn() {
//		srand((unsigned)time(0));
//		int xPoint = (rand() % screenW) + 1;
//
//		SDL_Rect r = { xPoint, screenH, 64, 64 };
//		Enemy enemy(r, speed, sheet1, sheet2, spriteW, spriteH); // kan succesivt öka speed om vi vill
//		engine->add(&enemy);
//	}
//
//	Spawner::~Spawner()
//	{
//		delete engine;
//		delete sheet1;
//		delete sheet2;
//	}
//}