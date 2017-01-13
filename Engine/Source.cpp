#include "Source.h"
#include "GameEngine.h"
#include "Player.h"
#include "Background.h"
#include "Enemy.h"
#include "SpriteSheet.h"
using namespace lazyEngine;


int main(int argc, char** argv) {
	GameEngine ge;
	SDL_Rect rp = { 200,205,38,38 };
	SDL_Rect rb = { 0,0,640,480 };
	SDL_Rect re = { 200,0,64,64 };
	Player p(rp, 5, "img/robojerk.png", "img/robojerkreverse.png", 38, 38);
	Enemy e1(re, 2, "img/fireball.png", "img/explosion.png", 64, 64);
	Background bg(rb, "img/stolenBg.png"); // "Borrowed" from http://www.emunix.emich.edu/~evett/GameProgramming/BookCode/chapter11.new/timedloop/background.bmp
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
