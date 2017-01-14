#include "Source.h"
#include "GameEngine.h"
#include "Player.h"
#include "Background.h"
#include "Enemy.h"
#include "Spawner.h"
using namespace lazyEngine;

int main(int argc, char** argv) {
	GameEngine ge;
	SDL_Rect rp = { 200,205,38,38 };
	SDL_Rect rb = { 0,0,640,480 };
	SDL_Rect re = { 200,0,64,64 };
	Player p(rp, 5, "img/robojerk.png", "img/robojerkreverse.png", 38, 38);
	Enemy e1(re, 2, "img/fireball.png", "img/explosion.png", 64, 64);
	//Spawner spwn(&ge, 640, 480, 2, "img/fireball.png", "img/explosion.png", 64, 64);
	Background bg(rb, "img/stolenBg.png");
	ge.add(&bg);
	ge.add(&p);
	ge.add(&e1);
	ge.run();

	return 0;
}

Source::Source()
{
}


Source::~Source()
{
}
